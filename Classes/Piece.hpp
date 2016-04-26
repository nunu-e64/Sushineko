//
//  Piece.hpp
//  Sushineko
//
//  Created by Fumiya Amano on 2016/04/26.
//
//

#ifndef Piece_hpp
#define Piece_hpp

#include "cocos2d.h"
#include "Constants.h"

class Piece: public cocos2d::Node
{
public:
    CREATE_FUNC(Piece);
    float getSpriteHeight();
    void setObstacleSide(Side side);
    Side getObstacleSide();
protected:
    Side side;
};

#endif /* Piece_hpp */
