//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_BARN_HPP
#define ENGISFARM_BARN_HPP
#include "Land.hpp"

class Barn : public Land {
public:
    char render() const override;
};


#endif //ENGISFARM_BARN_HPP
