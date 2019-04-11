#include <iostream>
#include <string>
#include "Scene.hpp"
#include "Cell.hpp"

int main() {
    Scene mainScene;

    string command;

    while(1)
    {
        mainScene.drawScene();
        cin >> command;

        if (command == "up")
        {
            mainScene.commandMove(1);
        }
        else if (command == "right")
        {
            mainScene.commandMove(2);
        }
        else if (command == "down")
        {
            mainScene.commandMove(3);
        }
        else if (command == "left")
        {
            mainScene.commandMove(4);
        }
        else if (command == "kill"){
            mainScene.commandKill();
        }
    }
}