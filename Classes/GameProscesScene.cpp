//
// Created by aragog on 20/07/15.
//

#include "GameProscesScene.h"


cocos2d::Scene *GameProscesScene::createScene() {
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameProscesScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool GameProscesScene::init() {


    //////////////////////////////
    // 1. super init first
    if ( !cocos2d::Layer::init() )
    {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    hud = HUD::create();
    hud->initOptions("message");
    //
    this->addChild( hud, 2 );
    /*/ ------------------------------HUD_DEFENITION_START------------------------------------------------------



//------------------------------HUD_DEFENITION_END---------------------------------------------------------*/
    this->schedule( schedule_selector(GameProscesScene::Update) );

    return true;
}

void GameProscesScene::Update(float dt) {

    //main loop

}
