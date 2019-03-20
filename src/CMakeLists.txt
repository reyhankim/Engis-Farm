cmake_minimum_required(VERSION 3.13)
project(EngisFarm)

set(CMAKE_CXX_STANDARD 14)

add_executable(EngisFarm main.cpp Renderable.hpp Player.hpp Cell.hpp FarmAnimal.hpp EggProducingFarmAnimal.hpp MeatProducingFarmAnimal.hpp MilkProducingFarmAnimal.hpp Land.hpp Facility.hpp Coop.hpp Barn.hpp Well.hpp Truck.hpp Mixer.hpp Chicken.hpp Goat.hpp Cow.hpp Swine.hpp Duck.hpp Horse.hpp Product.hpp FarmProduct.hpp SideProduct.hpp BeefRolade.hpp CowMeat.hpp SwineMeat.hpp ChickenMeat.hpp HorseMeat.hpp CowMilk.hpp GoatMilk.hpp  ChickenEgg.hpp DuckEgg.hpp ChickenNugget.hpp BeefSteak.hpp LinkedList.hpp Grassland.hpp Scene.hpp Time.hpp)