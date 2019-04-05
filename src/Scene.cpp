//
// Created by reyha on 04/04/2019.
//

#include <iostream>
#include "../include/Scene.hpp"
#include "../include/Land.hpp"
#include "../include/Player.hpp"
#include "../include/LeafInclude.hpp"

using namespace std;

Scene::Scene() : DEFAULT_FARM_MAP_HEIGHT(15), DEFAULT_FARM_MAP_WIDTH(15) {
    this->sessionName = "guest";
    field = fieldGenerator();
    animals = animalGenerator(4);
    player = Player();
    farmMapHeight = DEFAULT_FARM_MAP_HEIGHT;
    farmMapWidth = DEFAULT_FARM_MAP_WIDTH;
    farmMap = new char*[farmMapHeight];
    for(int i = 0; i < farmMapHeight; ++i)
        farmMap[i] = new char[farmMapWidth];
}

Scene::Scene(string _sessionName, int _farmMapHeight, int _farmMapWidth) : DEFAULT_FARM_MAP_HEIGHT(15), DEFAULT_FARM_MAP_WIDTH(15) {
    this->sessionName = _sessionName;
    field = fieldGenerator();
    animals = animalGenerator(4);
    player = Player();
    farmMapHeight = _farmMapHeight;
    farmMapWidth = _farmMapWidth;
    farmMap = new char*[farmMapHeight];
    for(int i = 0; i < farmMapHeight; ++i)
        farmMap[i] = new char[farmMapWidth];
}

Scene::Scene(Scene &oldScene) : DEFAULT_FARM_MAP_HEIGHT(15), DEFAULT_FARM_MAP_WIDTH(15) {
    this->sessionName = oldScene.sessionName;
    this->farmMapWidth = oldScene.farmMapWidth;
    this->farmMapHeight = oldScene.farmMapHeight;

    this->field = LinkedList<Cell*>();
    for(int i = 0; i < this->farmMapHeight*this->farmMapWidth; i++) {
        this->field.add(oldScene.field.get(i));
    }

    this->animals = LinkedList<FarmAnimal*>();
    for(int i = 0; i < Counter<FarmAnimal>::objects_alive; i++) {
        this->animals.add(oldScene.animals.get(i));
    }

    this->player = oldScene.player;
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
    delete &this->farmMap;
    cout << "G a m e  O v e r !" << endl;
}

void Scene::drawScene() {
    for (int i = 0; i < this->farmMapHeight; i++) {
        for (int j = 0; j < this->farmMapWidth; j++) {
            cout << this->farmMap[i][j];
        }
        cout << endl;
    }
}

void Scene::UpdateFarmMap() {
    int i;
    // Step 0: Pengecekan terhadap FarmAnimal yang memiliki hungerLevel == 5
    for(i = 0; i < Counter<FarmAnimal>::objects_alive; i++) {
        if(this->animals.get(i)->getHungryLevel() >= 5) {
            FarmAnimal *temp = this->animals.get(i);
            this->animals.remove(this->animals.get(i)); // Delete object
            temp->~FarmAnimal();
        }
    }

    // Step 1: Memanggil render() untuk mendapatkan posisi CELLS dari Farm sekarang dan randGrassGrow()
    for(i = 0; i < this->farmMapHeight*this->farmMapWidth; i++) {
        if (Land* l = dynamic_cast<Land*>(this->field.get(i))) {
            this->field.get(i)->randomGrass();
        }
        this->farmMap[this->field.get(i)->getX()][this->field.get(i)->getY()] = this->field.get(i)->render();
    }
    // Step 2: Memanggil render() untuk mendapatkan posisi ANIMALS dari Farm sekarang

    for(i = 0; i < Counter<FarmAnimal>::objects_alive; i++) {
        this->animals.get(i)->autoMove();
        this->farmMap[this->animals.get(i)->getX()][this->animals.get(i)->getY()] = this->animals.get(i)->render();
    }
}

LinkedList<Cell *> Scene::fieldGenerator()
{
    LinkedList<Cell *> newField = LinkedList<Cell *>();

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
    LinkedList<FarmAnimal *> newAnimals = LinkedList<FarmAnimal *>();

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