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
#include "cocostudio/CocoStudio.h"

class Character : public cocos2d::Node
{
public:
    CREATE_FUNC(Character);
//    CC_PROPERTY(Side, side, Side);
    void setSide(Side side);
    Side getSide();
    
    bool init() override;
    void onExit() override;
    void runChopAnimation();
private:
    Side side;
    cocostudio::timeline::ActionTimeline* timeline;
    
};

#endif /* defined(__SushiNeko__Character__) */
