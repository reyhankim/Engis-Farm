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

// Kelas Scene adalah blueprint dari objek yang menampung koleksi objek pada game serta melakukan update terhadap peta pada Farm
class Scene {
private:
    const int DEFAULT_FARM_MAP_HEIGHT;      // Tinggi peta farm default
    const int DEFAULT_FARM_MAP_WIDTH;       // Lebar peta farm default

    string sessionName;                     // nama pemain

    LinkedList<Cell *> field;                // LinkedList yang menyimpan koleksi Cell
    LinkedList<FarmAnimal *> animals;        // LinkedList yang menyimpan koleksi Animal

    Player player;                          // Instansiasi player

    char **farmMap;                         // Kumpulan hasil render karakter dari objek-objek pada farm
    int farmMapHeight;                      // Tinggi peta farm
    int farmMapWidth;                       // Lebar peta farm

    // Memanggil method render setiap objek dalam Fields dan menyimpannya
    // dalam Canvas, kemudian melakukan hal yang sama dengan Animals dan
    // terakhir player.
    void UpdateFarmMap();

    LinkedList<Cell *> fieldGenerator();

    LinkedList<FarmAnimal *> animalGenerator(int modifier);

    friend class MeatProducingFarmAnimal;
    friend class MilkProducingFarmAnimal;
    friend class EggProducingFarmAnimal;
    friend class Player;

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
    void drawScene();
};

#endif