#ifndef __MainScene_SCENE_H__
#define __MainScene_SCENE_H__

#include "cocos2d.h"
#include "Piece.hpp"
#include "ui/CocosGUI.h"

enum class GameState
{
    Title,
    Ready,
    Playing,
    GameOver
};

class Character;

class MainScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init() override;

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
    
private:
    cocos2d::Node* pieceNode;
    cocos2d::Vector<Piece*> pieces;
    Character* character;
    int pieceNum;
    int pieceIndex;     //bottom piece index
    Side lastObstacleSide;
    GameState gameState;
    cocos2d::ui::Text* scoreLabel;
    int score;
    float timeLeft;
    cocos2d::Sprite* timeBar;
    
    void onEnter() override;
    void setupTouchHandling();
    Side getSideForObstacle(Side side);
    void stepTower();
    bool isGameOver();
    void triggerGameOver();
    void triggerPlaying();
    void triggerTitle();
    void triggerReady();
    void setScore(int score);
    void setTimeLeft(float timeLeft);
    void resetGameState();
    void update(float dt) override;
};

#endif // __MainScene_SCENE_H__
