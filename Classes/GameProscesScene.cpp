//
// Created by aragog on 20/07/15.
//

#include "GameProscesScene.h"

#define pow2(x) pow(x,2)


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
    hud->initOptions();
    this->addChild( hud, 2 );


    //---------------------Sky------------------------------s
    Texture2D::TexParams tparam = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
    Texture2D* skytexture = Director::getInstance()->getTextureCache()->addImage("Sprites/Enviroment/Sky1366х768_2.png");
    skytexture ->setTexParameters(&tparam);
    auto sky = Sprite::createWithTexture(skytexture ,Rect(0,0,visibleSize.width, 400));
    sky->setAnchorPoint( Vec2::ANCHOR_TOP_RIGHT );
    sky->setPosition(visibleSize.width, visibleSize.height);
    this->addChild(sky, 0);
    //---------------------Sky-END------------------------------


    //---------------------Ground------------------------------
    auto ground = Sprite::create("Sprites/Enviroment/ground.png");
    ground->setAnchorPoint( Vec2::ANCHOR_TOP_RIGHT );
    ground->setPosition( visibleSize.width, visibleSize.height - 340 );
    this->addChild(ground, 1);
    //---------------------Ground-END------------------------------

    //---------------------Saloon------------------------------
    auto salon = Sprite::create("Sprites/Saloons/Saloon-2.png");
    salon->setAnchorPoint( Vec2::ANCHOR_MIDDLE_BOTTOM );
    salon->setPosition( visibleSize.width / 2, visibleSize.height - 430 );
    this->addChild(salon, 2);
    //---------------------Saloon-END------------------------------


    Vector<Sprite*> cactuses;
    for (int index = 0; index < 3; ++index) {
        float rand = (float) random(1,100) / 100;
        if( rand > 0.61)
            continue;
        cactuses.pushBack(Sprite::create( "Sprites/Enviroment/cactus-2.png" ));
        cactuses.at(cactuses.size()-1)->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
        cactuses.at(cactuses.size()-1)->setPosition(((float)(index+1)/4.f * ground->getContentSize().width / 2.f + random(0,20) ),
                                                  ((float)(index+1)/4.f * ground->getContentSize().height / 2.f + random(0,20) )
        );
        ground->addChild(cactuses.at(cactuses.size()-1));
    }

    for (int index = 0; index < 3; ++index) {
        float rand = (float) random(1,100) / 100;
        if( rand > 0.61)
            continue;
        cactuses.pushBack(Sprite::create( "Sprites/Enviroment/cactus-2.png" ));
        cactuses.at(cactuses.size()-1)->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
        cactuses.at(cactuses.size()-1)->setPosition( ground->getContentSize().width - ((float)(index+1)/4.f * ground->getContentSize().width / 2.f + random(0,20) ),
                                                    ((float)(index+1)/4.f * ground->getContentSize().height / 2.f + random(0,20) )
        );
        ground->addChild(cactuses.at(cactuses.size()-1));
    }

	std::string enemySprite = "Sprites\Mobsmob-1. ";
	enemySprite.at(enemySprite.length() - 1) = 47 + random(1, 3);
	auto enemy = Sprite::create(enemySprite);
	this->addChild(enemy, 6);



    this->schedule( schedule_selector(GameProscesScene::Update) );
    return true;
}

void GameProscesScene::Update(float dt) {

    //main loop
	

}
