//
//  Character.cpp
//  Sushineko
//
//  Created by Fumiya Amano on 2016/04/26.
//
//

#include "Character.hpp"

void Character::setSide(Side side) {
    this->side = side;
    if (side == Side::Right) {
        this->setScaleX(-1.0f);
    } else {
        this->setScaleX(1.0f);
    }
}

Side Character::getSide()
{
    return this->side;
}