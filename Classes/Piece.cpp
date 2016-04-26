//
//  Piece.cpp
//  Sushineko
//
//  Created by Fumiya Amano on 2016/04/26.
//
//

#include "Piece.hpp"

USING_NS_CC;

float Piece::getSpriteHeight()
{
    // 巻き寿司のスプライトのリファレンスを取得する
    Sprite* roll = this->getChildByName<Sprite*>("roll");
    
    // 次に巻き寿司のスプライトの高さを返す
    return roll->getContentSize().height;
}

void Piece::setObstacleSide(Side side)
{
    this->side = side;
    Sprite* roll = this->getChildByName<Sprite*>("roll");
    Sprite* leftChopstick = roll->getChildByName<Sprite*>("leftChopstick");
    Sprite* rightChopstick = roll->getChildByName<Sprite*>("rightChopstick");

    switch (side) {
        case Side::None:
            leftChopstick->setVisible(false);
            rightChopstick->setVisible(false);
            break;
        case Side::Left:
            leftChopstick->setVisible(true);
            rightChopstick->setVisible(false);
            break;
        case Side::Right:
            leftChopstick->setVisible(false);
            rightChopstick->setVisible(true);
            break;
            
        default:
            break;
    }
}
Side Piece::getObstacleSide()
{
    return this->side;
}
