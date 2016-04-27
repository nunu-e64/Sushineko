//
//  Character.cpp
//  Sushineko
//
//  Created by Fumiya Amano on 2016/04/26.
//
//

#include "Character.hpp"
USING_NS_CC;

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

bool Character::init()
{
    if (!Node::init())
    {
        return false;
    };
    
    // キャラクターは左側からスタートする
    this->side = Side::Left;
    
    // キャラクターのアニメーションのタイムラインを読み込む
    this->timeline = CSLoader::createTimeline("Character.csb");
    
    // キャラクターのアニメーションのタイムラインを確保し、メモリ領域が解放されないようにする
    this->timeline->retain();
    
    return true;
}

void Character::onExit()
{
    // initで呼び出したretainを解放する
    this->timeline->release();
    
    Node::onExit();
}

void Character::runChopAnimation()
{
    this->stopAllActions();
    this->runAction(this->timeline);
    this->timeline->play("chop", false);

}
