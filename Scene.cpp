//
// Created by reyha on 04/04/2019.
//

#include <iostream>
#include "Scene.hpp"
#include "Land.hpp"
#include "LeafInclude.hpp"
//#include <cassert>

using namespace std;

Scene::Scene() : DEFAULT_FARM_MAP_HEIGHT(15), DEFAULT_FARM_MAP_WIDTH(15) {
    this->sessionName = "guest";
    farmMapHeight = DEFAULT_FARM_MAP_HEIGHT;
    farmMapWidth = DEFAULT_FARM_MAP_WIDTH;
    farmMap = new char*[farmMapHeight];
    for(int i = 0; i < farmMapHeight; ++i)
        farmMap[i] = new char[farmMapWidth];

    cout << "fieldGenerator start" << endl;
    this->field = fieldGenerator();
    cout << "fieldGenerator finish" << endl;

    cout << "animalGenerator start" << endl;
    this->animals = animalGenerator(3);
    cout << "animalGenerator finish" << endl;
}

Scene::Scene(string _sessionName, int _farmMapHeight, int _farmMapWidth) : DEFAULT_FARM_MAP_HEIGHT(15), DEFAULT_FARM_MAP_WIDTH(15) {
    this->sessionName = _sessionName;
    farmMapHeight = _farmMapHeight;
    farmMapWidth = _farmMapWidth;
    farmMap = new char*[farmMapHeight];
    for(int i = 0; i < farmMapHeight; ++i)
        farmMap[i] = new char[farmMapWidth];

    cout << "fieldGenerator start" << endl;
    this->field = fieldGenerator();
    cout << "fieldGenerator finish" << endl;

    cout << "animalGenerator start" << endl;
    this->animals = animalGenerator(3);
    cout << "animalGenerator finish" << endl;
}

Scene::Scene(Scene &oldScene) : DEFAULT_FARM_MAP_HEIGHT(15), DEFAULT_FARM_MAP_WIDTH(15) {
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
    cout << "updating map" << endl;
    UpdateFarmMap();
    cout << "printing map" << endl;
    for (int i = 0; i < this->farmMapHeight; i++) {
        for (int j = 0; j < this->farmMapWidth; j++) {
            cout << this->farmMap[i][j];
        }
        cout << endl;
    }
}

void Scene::UpdateFarmMap() {
    // Step 0: Pengecekan terhadap FarmAnimal yang memiliki hungerLevel == 5
    cout << "step 0" << endl;
    cout << "Farmanimal counter " << Counter<FarmAnimal>::objects_alive << endl;
    for(int i = 0; i < Counter<FarmAnimal>::objects_alive; i++) {
        cout << "Getting FarmAnimal " << i << endl;
        FarmAnimal *temp = this->animals.get(i);

        if(temp->getHungryLevel() >= 5) {
            this->animals.remove(temp); // Delete object
            delete temp;
        }
        cout << "Getting FarmAnimal " << i << "finish" << endl;
    }

    // Step 1: Memanggil render() untuk mendapatkan posisi CELLS dari Farm sekarang dan randGrassGrow()
    cout << "step 1" << endl;
    cout << "farmMapHeight: " << farmMapHeight << endl;
    cout << "farmMapWidth: " << farmMapWidth << endl;
    for(int i = 0; i < this->farmMapHeight*this->farmMapWidth; i++) {

        cout << "Getting curentCell " << i << endl;
        Cell* currentCell = this->field.get(i);

        cout << currentCell << endl;

        cout << "currentCell X: " << currentCell->getX() << endl;
        cout << "currentCell Y: " << currentCell->getY() << endl;

        if (Land* l = dynamic_cast<Land*>(currentCell)) {
            l->randomGrass();
        }

        this->farmMap[currentCell->getX()][currentCell->getY()] = currentCell->render();
    }

    // Step 2: Memanggil render() untuk mendapatkan posisi ANIMALS dari Farm sekarang
    cout << "step 2" << endl;
    for(int i = 0; i < Counter<FarmAnimal>::objects_alive; i++) {

        FarmAnimal* currentAnimal = this->animals.get(i);

        currentAnimal->move(rand()%5, this->field);

        this->farmMap[currentAnimal->getX()][currentAnimal->getY()] = currentAnimal->render();
    }
}

LinkedList<Cell *> Scene::fieldGenerator()
{
    LinkedList<Cell *> newField;

    cout << "add coop and barn" << endl;
    for (int j = 0; j<farmMapWidth/2; j++)
    {
        cout << newField.head << endl;
        if (newField.head)
        {
            cout << newField.head->info->getX() << endl;
            cout << newField.head->info->getY() << endl;
        }

        for (int i = 0; i<farmMapHeight/2; i++)
        {
            newField.add(new Coop(j, i));
        }
        for (int i = farmMapHeight/2; i<farmMapHeight; i++)
        {
            newField.add(new Barn(j, i));
        }
    }

    cout << "add grassland" << endl;
    for (int j = farmMapWidth/2+1; j<farmMapWidth; j++)
    {
        for (int i = 0; i<farmMapHeight; i++)
        {
            newField.add(new Grassland(j, i));
        }
    }

    cout << "add another grassland" << endl;
    for(int i = 3; i<farmMapHeight; i++)
    {
        newField.add(new Grassland(farmMapWidth/2, i));
    }

    cout << "add truck" << endl;
    newField.add(new Truck(farmMapWidth/2, 0));

    cout << "add mixer" << endl;
    newField.add(new Mixer(farmMapWidth/2, 1));

    cout << "add well" << endl;
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
            cout << "add chicken" << endl;
            newAnimals.add(new Chicken(rand()%farmMapWidth/2, rand()%farmMapHeight/2));
        }
        // randomisasi duck
        if (rand()%2 == 1)
        {
            cout << "add duck" << endl;
            newAnimals.add(new Duck(rand()%farmMapWidth/2, rand()%farmMapHeight/2));
        }
        // randomisasi cow
        if (rand()%2 == 1)
        {
            cout << "add cow" << endl;
            newAnimals.add(new Cow(rand()%farmMapWidth/2, rand()%farmMapHeight/2+farmMapHeight/2));
        }
        // randomisasi Goat
        if (rand()%2 == 1)
        {
            cout << "add goat" << endl;
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
            cout << "add swine" << endl;
            newAnimals.add(new Swine(rand()%farmMapWidth/2, rand()%farmMapHeight/2+farmMapHeight/2));
        }
    }

    return newAnimals;
}