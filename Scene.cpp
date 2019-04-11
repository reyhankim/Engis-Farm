//
// Created by reyha on 04/04/2019.
//

#include <iostream>
#include "Scene.hpp"
#include "Land.hpp"
#include "LeafInclude.hpp"
//#include <cassert>

using namespace std;

Scene::Scene(): sessionName("guest"),
                farmMapHeight(DEFAULT_FARM_MAP_HEIGHT),
                farmMapWidth(DEFAULT_FARM_MAP_WIDTH),
                field(fieldGenerator()),
                animals(animalGenerator(3)),
                player(farmMapWidth/2, farmMapHeight/2)
{
    farmMap = new char*[farmMapHeight];
    for(int i = 0; i < farmMapHeight; ++i)
        farmMap[i] = new char[farmMapWidth];
}

Scene::Scene(string _sessionName, int _farmMapHeight, int _farmMapWidth) :
                sessionName(_sessionName),
                farmMapHeight(_farmMapHeight),
                farmMapWidth(_farmMapWidth),
                field(fieldGenerator()),
                animals(animalGenerator(3)),
                player(farmMapWidth/2, farmMapHeight/2)
{
    farmMap = new char*[farmMapHeight];
    for(int i = 0; i < farmMapHeight; ++i)
        farmMap[i] = new char[farmMapWidth];
}

Scene::Scene(Scene &oldScene)
{
    this->sessionName = oldScene.sessionName;
    this->farmMapWidth = oldScene.farmMapWidth;
    this->farmMapHeight = oldScene.farmMapHeight;

    this->field;
    for(int i = 0; i < this->farmMapHeight*this->farmMapWidth; i++) {
        this->field.add(oldScene.field.get(i));
    }

    this->animals;
    for(int i = 0; i < Counter<FarmAnimal>::objects_alive; i++) {
        this->animals.add(oldScene.animals.get(i));
    }

    farmMap = new char*[farmMapHeight];
    for(int i = 0; i < farmMapHeight; ++i)
        farmMap[i] = new char[farmMapWidth];
    for(int i = 0; i < farmMapHeight; i++) {
        for(int j = 0; j < farmMapWidth; j++) {
            this->farmMap[i][j] = oldScene.farmMap[i][j];
        }
    }

    player = oldScene.player;
}

Scene::~Scene() {
    delete &this->field;
    delete &this->animals;
    for(int i = 0; i < farmMapHeight; ++i)
        delete farmMap[i];
    delete farmMap;
    cout << "G a m e  O v e r !" << endl;
}

void Scene::drawScene() {
    UpdateFarmMap();
    for (int i = 0; i < this->farmMapHeight; i++) {
        for (int j = 0; j < this->farmMapWidth; j++) {
            cout << this->farmMap[i][j] << " | ";
        }
        cout << endl << endl;
    }
}

void Scene::UpdateFarmMap() {
    // Step 0: Pengecekan terhadap FarmAnimal yang memiliki hungerLevel == 5
    for(int i = 0; i < Counter<FarmAnimal>::objects_alive; i++) {
        FarmAnimal *temp = this->animals.get(i);

        if(temp->getHungryLevel() >= 5) {
            this->animals.remove(temp); // Delete object
            delete temp;
        }
    }

    // Step 1: Memanggil render() untuk mendapatkan posisi CELLS dari Farm sekarang dan randGrassGrow()
    for(int i = 0; i < this->farmMapHeight*this->farmMapWidth; i++) {

        Cell* currentCell = this->field.get(i);

        if (Land* l = dynamic_cast<Land*>(currentCell)) {
            l->randomGrass();
        }

        this->farmMap[currentCell->getY()][currentCell->getX()] = currentCell->render();
    }

    // Step 2: Memanggil render() untuk mendapatkan posisi ANIMALS dari Farm sekarang
    for(int i = 0; i < Counter<FarmAnimal>::objects_alive; i++) {

        FarmAnimal* currentAnimal = this->animals.get(i);

        animalRandomMove(currentAnimal);
        //currentAnimal->move(rand()%5, this->field, farmMapWidth, farmMapHeight);

        this->farmMap[currentAnimal->getY()][currentAnimal->getX()] = currentAnimal->render();
    }

    // Step 3: Memanggil render() untuk mendapatkan posisi A player
    this->farmMap[player.getY()][player.getX()] = player.render();
}

void Scene::animalRandomMove(FarmAnimal* animal)
{
    bool canMove = false;
    // randomize direction
    int destX = animal->getX() - 1 + rand()%3;
    int destY = animal->getY() - 1 + rand()%3;

    if (destX < 0 || destY < 0 || destX >= farmMapWidth || destY >= farmMapHeight)
    {
        canMove = false;
    }
    else
    {
        Cell* tempCell;

        for (int i = 0; i<field.count; i++)
        {
            tempCell = field.get(i);

            if (tempCell->getX() == destX && tempCell->getY() == destY)
            {
                if (tempCell->isWalkable())
                {
                    if (dynamic_cast<EggProducingFarmAnimal*>(animal))
                    {
                        if (dynamic_cast<Coop*>(tempCell))
                        {
                            canMove = true;
                        }
                    }

                    if (dynamic_cast<MeatProducingFarmAnimal*>(animal))
                    {
                        if (dynamic_cast<Barn*>(tempCell))
                        {
                            canMove = true;
                        }
                    }

                    if (dynamic_cast<MilkProducingFarmAnimal*>(animal))
                    {
                        if (dynamic_cast<Grassland*>(tempCell))
                        {
                            canMove = true;
                        }
                    }
                }

                break;
            }
        }
    }

    if (canMove)
    {
        animal->setX(destX);
        animal->setY(destY);
    }
}

LinkedList<Cell *> Scene::fieldGenerator()
{
    LinkedList<Cell *> newField;

    for (int j = 0; j<farmMapWidth/2; j++)
    {

        for (int i = 0; i<farmMapHeight/2; i++)
        {
            newField.add(new Coop(j, i));
        }
        for (int i = farmMapHeight/2; i<farmMapHeight; i++)
        {
            newField.add(new Barn(j, i));
        }
    }

    for (int j = farmMapWidth/2+1; j<farmMapWidth; j++)
    {
        for (int i = 0; i<farmMapHeight; i++)
        {
            newField.add(new Grassland(j, i));
        }
    }

    for(int i = 3; i<farmMapHeight; i++)
    {
        newField.add(new Grassland(farmMapWidth/2, i));
    }

    newField.add(new Truck(farmMapWidth/2, 0));

    newField.add(new Mixer(farmMapWidth/2, 1));

    newField.add(new Well(farmMapWidth/2, 2));

    return newField;
}

LinkedList<FarmAnimal *> Scene::animalGenerator(int modifier)
{
    LinkedList<FarmAnimal *> newAnimals;

    for (int i=0; i<=modifier; i++)
    {
        // randomisasi chicken
        if (rand()%2 == 1)
        {
            newAnimals.add(new Chicken(rand()%farmMapWidth/2, rand()%farmMapHeight/2));
        }
        // randomisasi duck
        if (rand()%2 == 1)
        {
            newAnimals.add(new Duck(rand()%farmMapWidth/2, rand()%farmMapHeight/2));
        }
        // randomisasi cow
        if (rand()%2 == 1)
        {
            newAnimals.add(new Cow(rand()%farmMapWidth/2, rand()%farmMapHeight/2+farmMapHeight/2));
        }
        // randomisasi Goat
        if (rand()%2 == 1)
        {
            newAnimals.add(new Goat(rand()%farmMapWidth/2+farmMapWidth/2, rand()%farmMapHeight/2+3));
        }
        // randomisasi horse
        if (rand()%2 == 1)
        {
            newAnimals.add(new Horse(rand()%farmMapWidth/2+farmMapWidth/2, rand()%farmMapHeight/2+3));
        }
        // randomisasi swine
        if (rand()%2 == 1)
        {
            newAnimals.add(new Swine(rand()%farmMapWidth/2, rand()%farmMapHeight/2+farmMapHeight/2));
        }
    }

    return newAnimals;
}