#include <iostream>
#include "Scene.hpp"
#include "Cell.hpp"

int main() {
    Scene mainScene;
    while(1)
    {
        mainScene.drawScene();
        char x;
        cin >> x;
    }
}