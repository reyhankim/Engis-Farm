cmake_minimum_required(VERSION 3.13)
project(EngisFarm)

set(CMAKE_CXX_STANDARD 14)

add_executable(EngisFarm main.cpp Renderable.hpp Player.hpp Cell.hpp FarmAnimal.hpp EggProducingFarmAnimal.hpp MeatProducingFarmAnimal.hpp MilkProducingFarmAnimal.hpp Land.hpp Facility.hpp Coop.hpp Grass.hpp Barn.hpp Well.hpp Truck.hpp Mixer.hpp Chicken.hpp Goat.hpp Cow.hpp Swine.hpp Duck.hpp Horse.hpp Product.hpp FarmProduct.hpp SideProduct.hpp BeefRolade.hpp InteractTemplate.hpp CowMeat.hpp SwineMeat.hpp DuckMeat.hpp ChickenMeat.hpp GoatMeat.hpp HorseMeat.hpp CowMilk.hpp GoatMilk.hpp  ChickenEgg.hpp DuckEgg.hpp)