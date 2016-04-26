//
//  Character.hpp
//  Sushineko
//
//  Created by Fumiya Amano on 2016/04/26.
//
//

#ifndef __SushiNeko__Character__
#define __SushiNeko__Character__

#include "cocos2d.h"
#include "Constants.h"

class Character : public cocos2d::Node
{
public:
    CREATE_FUNC(Character);
//    CC_PROPERTY(Side, side, Side);
    void setSide(Side side);
    Side getSide();
private:
    Side side;
    
};

#endif /* defined(__SushiNeko__Character__) */
