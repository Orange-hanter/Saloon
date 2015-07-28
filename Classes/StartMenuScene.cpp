#include "StartMenuScene.h"

USING_NS_CC;


cocos2d::Scene* StartMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();

    // 'layer' is an autorelease object
    auto layer = StartMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto startLabel = Label::createWithSystemFont("Start Game","Arial",19);
    auto startMenuItem = MenuItemLabel::create( startLabel, CC_CALLBACK_1(StartMenuScene::GoToGame, this) );
    startMenuItem->setPosition( Vec2(visibleSize.width/2 + origin.x,
                                     visibleSize.height/2 + origin.y ) );

    auto infoLabel = Label::createWithSystemFont("About Game","Arial",19);
    auto infoMenuItem = MenuItemLabel::create( infoLabel );
    infoMenuItem->setPosition( Vec2(visibleSize.width/2 + origin.x,
                                     visibleSize.height/2 + origin.y - 40 ) );

    auto exitLabel = Label::createWithSystemFont("Exit Game","Arial",19);
    auto exitMenuItem = MenuItemLabel::create( exitLabel, CC_CALLBACK_1(StartMenuScene::GoToExit, this) );
    exitMenuItem->setPosition( Vec2(visibleSize.width/2 + origin.x,
                                     visibleSize.height/2 + origin.y - 80 ) );

    auto menu = Menu::create(startMenuItem, infoMenuItem, exitMenuItem,  NULL);
    menu->setPosition(Vec2(Vec2::ZERO));
    this->addChild(menu);

    return true;
}

void StartMenuScene::GoToGame(cocos2d::Ref *sener) {

    auto gameScene = GameProscesScene::createScene();
    Director::getInstance()->replaceScene( TransitionFade::create( 0.5, gameScene) );

}


void StartMenuScene::GoToExit(cocos2d::Ref *sender) {

}
