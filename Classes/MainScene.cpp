#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CharacterReader.hpp"
#include "PieceReader.hpp"
#include "Character.hpp"
#include "Piece.hpp"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "MainScene" splash screen"
    auto sprite = Sprite::create("MainScene.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // カスタムクラス用のReaderを登録する
    // CharacterReader::getInstance()ではなく、CharacterReader::getInstanceとすること。さもなくばクラッシュするので、注意が必要
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CharacterReader", (ObjectFactory::Instance) CharacterReader::getInstance);
    instance->registReaderObject("PieceReader", (ObjectFactory::Instance) PieceReader::getInstance);
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    Size size = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(size);
    ui::Helper::doLayout(rootNode);
    
    
    // 寿司タワーを作る
    this->pieceNum = 10;
    this->pieceIndex = 0;

    this->pieceNode = rootNode->getChildByName("pieceNode");
    this->lastObstacleSide = Side::Left;
    
    for (int i = 0; i < this->pieceNum; ++i) {
        auto hoge = CSLoader::createNode("Piece.csb");
//        Piece* piece = dynamic_cast<Piece*>(hoge);
        Piece* piece = static_cast<Piece*>(hoge);
//        Piece* piece = dynamic_cast<Piece*>(CSLoader::createNode("Piece.csb"));
        
        float rollHeight = piece->getSpriteHeight();
        piece->setPosition(0.0f, rollHeight / 2.0f * i);
        this->pieceNode->addChild(piece);
        this->pieces.pushBack(piece);
        this->lastObstacleSide = this->getSideForObstacle(this->lastObstacleSide);
        piece->setObstacleSide(lastObstacleSide);
    }

    this->character = rootNode->getChildByName<Character*>("character");
    this->scoreLabel = rootNode->getChildByName<cocos2d::ui::Text*>("scoreLabel");
    auto lifeBG = rootNode->getChildByName("lifeBG");
    this->timeBar = lifeBG->getChildByName<Sprite*>("lifeBar");
    
    this->gameState = GameState::Title;

    addChild(rootNode);
    
    this->resetGameState();

    return true;
}

void MainScene::onEnter() {
    Layer::onEnter();
    this->setupTouchHandling();
    this->triggerTitle();
    this->scheduleUpdate();
}

void MainScene::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        switch (this->gameState) {
            case GameState::Title:
                this->triggerReady();
                break;
            case GameState::Ready:
                this->triggerPlaying();
                // ここで「break」は不要！
            case GameState::Playing: {
                // MainSceneの座標システムでタッチの位置を取得する
                Vec2 touchLocation = this->convertTouchToNodeSpace(touch);
                
                // タッチが画面の右側か左側かを確認する
                // キャラクターを適切なサイドに移動させる
                if (touchLocation.x < this->getContentSize().width / 2.0f)
                {
                    this->character->setSide(Side::Left);
                }
                else
                {
                    this->character->setSide(Side::Right);
                }
                
                if (this->isGameOver())
                {
                    this->triggerGameOver();
                    return true;
                }

                this->stepTower();
                this->setScore(this->score + 1);
                this->setTimeLeft(this->timeLeft + 0.25f);
                
                break;
            }
            case GameState::GameOver:
                this->triggerReady();
                break;
        }
        
        return true;
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

Side MainScene::getSideForObstacle(Side side)
{
    Side nextSide;
    switch (side) {
        case Side::None: {
            float rand = CCRANDOM_0_1();
            if (rand < 0.45f) {
                nextSide = Side::Left;
            } else if(rand < 0.90f) {
                nextSide = Side::Right;
            } else {
                nextSide = Side::None;
            }
            break;
        }
        default: {
            nextSide = Side::None;
            break;
        }
    }
    
    return nextSide;
}

void MainScene::stepTower()
{
    auto currentPiece = this->pieces.at(this->pieceIndex);
    float pieceHeight = currentPiece->getSpriteHeight();
    
    currentPiece->setPositionY(currentPiece->getPositionY() + pieceHeight / 2.0f * this->pieceNum);
    currentPiece->setLocalZOrder(currentPiece->getLocalZOrder() + 1);

    this->lastObstacleSide = getSideForObstacle(this->lastObstacleSide);
    currentPiece->setObstacleSide(this->lastObstacleSide);
                                  
    this->pieceNode->setPositionY(this->pieceNode ->getPositionY() + -1.0f * pieceHeight / 2.0f);
    
    this->pieceIndex = (this->pieceIndex + 1) % this->pieceNum;

    //Check GameOver
    if (this->isGameOver())
    {
        this->triggerGameOver();
    }
}

bool MainScene::isGameOver()
{
    if (this->character->getSide() == this->pieces.at(this->pieceIndex)->getObstacleSide())
    {
        return true;
    } else
    {
        return false;
    }
}

void MainScene::triggerGameOver()
{
    this->gameState = GameState::GameOver;
    this->setTimeLeft(0.0f);
}

void MainScene::triggerPlaying()
{
    this->gameState = GameState::Playing;
    
    // 最上位のノードのリファレンスを取得
    auto scene = this->getChildByName("Scene");
    
    // 左右のTAPのスプライトのリファレンスを取得
    cocos2d::Sprite* tapLeft = scene->getChildByName<cocos2d::Sprite*>("tapLeft");
    cocos2d::Sprite* tapRight = scene->getChildByName<cocos2d::Sprite*>("tapRight");
    
    // フェードアウトのアクションを2つ作成
    cocos2d::FadeOut* leftFade = cocos2d::FadeOut::create(0.35f);
    cocos2d::FadeOut* rightFade = cocos2d::FadeOut::create(0.35f);
    
    // フェードアウトのアクションを実行
    tapLeft->runAction(leftFade);
    tapRight->runAction(rightFade);
    
    this->scoreLabel->setVisible(true);
}

void MainScene::triggerTitle()
{
    this->gameState = GameState::Title;
    cocostudio::timeline::ActionTimeline* titleTimeline = CSLoader::createTimeline("MainScene.csb");
    this->stopAllActions();
    this->runAction(titleTimeline);
    titleTimeline->play("title", false);
}

void MainScene::triggerReady()
{
    this->resetGameState();
    
    auto scene = this->getChildByName("Scene");
    
    // 左右のTAPのスプライトのリファレンスを取得
    cocos2d::Sprite* tapLeft = scene->getChildByName<cocos2d::Sprite*>("tapLeft");
    cocos2d::Sprite* tapRight = scene->getChildByName<cocos2d::Sprite*>("tapRight");
    
    // スプライトが表示されるようにする
    tapLeft->setOpacity(255);
    tapRight->setOpacity(255);

    this->gameState = GameState::Ready;
    cocostudio::timeline::ActionTimeline* readyTimeline = CSLoader::createTimeline("MainScene.csb");
    this->stopAllActions();
    this->runAction(readyTimeline);
    readyTimeline->play("ready", true);
}

void MainScene::setScore(int score)
{
    // スコアのインスタンス変数をアップデートする
    this->score = score;
    
    // スコアのラベルをアップデートする
    this->scoreLabel->setString(std::to_string(this->score));
}

void MainScene::setTimeLeft(float timeLeft)
{
    // 残り時間を0秒と10秒の間に固定する
    this->timeLeft = clampf(timeLeft, 0.0f, 10.0f);
    
    // 残り時間を正しく表示するためにUIをアップデートする
    this->timeBar->setScaleX(timeLeft / 10.0f);
}

void MainScene::resetGameState()
{
    // 新規ゲーム開始時に、一番下のピースには障害物がないことを確認する
    Piece* currentPiece = this->pieces.at(this->pieceIndex);
    currentPiece->setObstacleSide(Side::None);
 
    setScore(0);
    setTimeLeft(5.0f);
}

void MainScene::update(float dt)
{
    Layer::update(dt);
    
    if (gameState == GameState::Playing)
    {
        setTimeLeft(timeLeft - dt);
    }
    
    // タイマーが0以下なら、ゲームは終了
    if (this->timeLeft <= 0.0f)
    {
        this->triggerGameOver();
    }
}