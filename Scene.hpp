//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_FARM_HPP
#define ENGISFARM_FARM_HPP

#include "LinkedList.hpp"
#include "Cell.hpp"
#include "FarmAnimal.hpp"
#include "Player.hpp"
#include <string>

using namespace std;

class Scene {
    private:
        const int DEFAULT_FARM_MAP_HEIGHT;
        const int DEFAULT_FARM_MAP_WIDTH;

        string sessionName;

        LinkedList<Cell*> field;
        LinkedList<FarmAnimal*> animals;
        
        Player player;
        
        char** farmMap;
        int farmMapHeight;
        int farmMapWidth;

        // Memanggil method render setiap objek dalam Fields dan menyimpannya
        // dalam Canvas, kemudian melakukan hal yang sama dengan Animals.
        void UpdateFarmMap();

    public:
        // CTOR
        Scene();
        // CTOR user defined
        Scene(string _sessionName, int _farmMapHeight, int _farmMapWidth);
        // CCTOR
        Scene(Scene &oldScene);
        // DTOR
        ~Scene();
        
        // menampilkan jendela permainan di konsol
        void DrawScene();
};


#endif //ENGISFARM_FARM_HPP
