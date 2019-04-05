
#include "FarmAnimal.hpp"

// Class MeatProducingFarmAnimal digunakan untuk mengelompokkan animal
    public:
        // DTOR Virtual
        virtual ~MeatProducingFarmAnimal();
        // method untuk pergerakan animal, hanya dapat bergerak di Barn
        // menerima List of Renderable* untuk mengecek cell yang akan ditempati
        void autoMove(LinkedList<Renderable*> farmMap) override;
