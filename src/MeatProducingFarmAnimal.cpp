
#include "../include/MeatProducingFarmAnimal.hpp"

// Class MeatProducingFarmAnimal digunakan untuk mengelompokkan animal

        // DTOR Virtual
        MeatProducingFarmAnimal::~MeatProducingFarmAnimal(){

}
        // method untuk pergerakan animal, hanya dapat bergerak di Barn
        // menerima List of Renderable* untuk mengecek cell yang akan ditempati
        void MeatProducingFarmAnimal::autoMove(LinkedList<Renderable*> farmMap){
        int direction = rand() % 5 ;
        switch (direction){
            case 0 :
                break;
            case 1 :
                if (getY() - 1 >= 0){
                    if (dynamic_cast<>())
                    setY(getY())
                }

        }
}
