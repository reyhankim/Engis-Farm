//
// Created by reyha on 04/04/2019.
//

#include <iostream>
#include "../include/Scene.hpp"
using namespace std;

Scene::Scene() : DEFAULT_FARM_MAP_HEIGHT(15), DEFAULT_FARM_MAP_WIDTH(15) {
    this->sessionName = "guest";
    field = LinkedList<Cell*>();
    animals = LinkedList<FarmAnimal*>();
    player = Player();
    farmMapHeight = DEFAULT_FARM_MAP_HEIGHT;
    farmMapWidth = DEFAULT_FARM_MAP_WIDTH;
    farmMap = new char*[farmMapHeight];
    for(int i = 0; i < farmMapHeight; ++i)
        farmMap = reinterpret_cast<char **>(new char[farmMapWidth]);
}

Scene::Scene(string _sessionName, int _farmMapHeight, int _farmMapWidth) : DEFAULT_FARM_MAP_HEIGHT(15), DEFAULT_FARM_MAP_WIDTH(15) {
    this->sessionName = _sessionName;
    field = LinkedList<Cell*>();
    animals = LinkedList<FarmAnimal*>();
    player = Player();
    farmMapHeight = _farmMapHeight;
    farmMapWidth = _farmMapWidth;
    farmMap = new char*[farmMapHeight];
    for(int i = 0; i < farmMapHeight; ++i)
        farmMap = reinterpret_cast<char **>(new char[farmMapWidth]);
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
    this->farmMap = new char*[farmMapHeight];
    for(int i = 0; i < farmMapHeight; i++)
        this->farmMap = reinterpret_cast<char **>(new char[farmMapWidth]);
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
}

void Scene::drawScene() {
    for (int i = 0; i < this->farmMapHeight; i++) {
        for (int j = 0; j < this->farmMapWidth; j++) {
            cout << this->farmMap[i][j];
        }
        cout << endl;
    }
}
