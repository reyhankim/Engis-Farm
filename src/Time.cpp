//
// Created by reyha on 05/04/2019.
//
#include "../include/Time.hpp"

int Time::gameTime = 0;

void Time::advanceGameTime() {
    gameTime++;
}

int Time::getGameTime() {
    return Time::gameTime;
}

