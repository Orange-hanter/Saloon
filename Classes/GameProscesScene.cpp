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

//    hud = HUD::createLayer("The Enemy is approaching!", visibleSize);
    //
    // ------------------------------HUD_DEFENITION_START------------------------------------------------------
    cocos2d::Layer* hud = cocos2d::LayerColor::create(cocos2d::Color4B(214, 17, 17, 1));
    hud->setPosition(cocos2d::Vec2::ZERO);
    hud->setContentSize( visibleSize );

    auto _messageLabel = cocos2d::Label::createWithSystemFont("HUD","Arial",19);
    _messageLabel->setColor(cocos2d::Color3B(255, 215, 0));
    _messageLabel->setPosition(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width/2,
                                             cocos2d::Director::getInstance()->getVisibleSize().height/2));
    this->addChild(_messageLabel,3);

    auto backboard = cocos2d::Sprite::create("hood.png");

    this->addChild( backboard, 3 );

//------------------------------HUD_DEFENITION_END---------------------------------------------------------*/
    this->addChild( hud, 2 );
    this->schedule( schedule_selector(GameProscesScene::Update) );

    return true;
}

void GameProscesScene::Update(float dt) {

    //main loop

}
