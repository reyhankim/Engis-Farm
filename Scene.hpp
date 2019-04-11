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

#define DEFAULT_FARM_MAP_HEIGHT 15  // Tinggi peta farm default
#define DEFAULT_FARM_MAP_WIDTH 15   // Lebar peta farm default

using namespace std;

// Kelas Scene adalah blueprint dari objek yang menampung koleksi objek pada game serta melakukan update terhadap peta pada Farm
class Scene {

    private:
        char **farmMap;                         // Kumpulan hasil render karakter dari objek-objek pada farm

        // Memanggil method render setiap objek dalam Fields dan menyimpannya
        // dalam Canvas, kemudian melakukan hal yang sama dengan Animals dan
        // terakhir player.
        void UpdateFarmMap();

        void animalRandomMove(FarmAnimal* animal);

        LinkedList<Cell *> fieldGenerator();

        LinkedList<FarmAnimal *> animalGenerator(int modifier);

    public:
        string sessionName;                     // nama pemain

        int farmMapHeight;                      // Tinggi peta farm
        int farmMapWidth;                       // Lebar peta farm

        LinkedList<Cell *> field;                // LinkedList yang menyimpan koleksi Cell
        LinkedList<FarmAnimal *> animals;        // LinkedList yang menyimpan koleksi Animal

        Player player;                          // Instansiasi player

        // CTOR
        Scene();

        // CTOR user defined
        Scene(string _sessionName, int _farmMapHeight, int _farmMapWidth);

        // CCTOR
        Scene(Scene &oldScene);

        // DTOR
        ~Scene();

        // menampilkan jendela permainan di konsol
        void drawScene();

        void commandMove(int direction);

        void commandInteract();

        void commandKill();

        void commandGrow();

        void commandTalk();

        void commandMix();
};

#endif