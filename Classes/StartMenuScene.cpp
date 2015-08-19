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

    auto startLabel = Label::createWithSystemFont("Start Game","Arial", FONT_SIZE);
    auto startMenuItem = MenuItemLabel::create( startLabel, CC_CALLBACK_1(StartMenuScene::GoToGame, this) );
    startMenuItem->setPosition( Vec2(visibleSize.width/2 + origin.x,
                                     visibleSize.height/2 ) );

    auto infoLabel = Label::createWithSystemFont("About Game","Arial", FONT_SIZE);
    auto infoMenuItem = MenuItemLabel::create( infoLabel );
    infoMenuItem->setPosition( Vec2(visibleSize.width/2 + origin.x,
                                     visibleSize.height/2 + origin.y - 40 ) );

    auto exitLabel = Label::createWithSystemFont("Exit Game","Arial", FONT_SIZE);
    auto exitMenuItem = MenuItemLabel::create( exitLabel, CC_CALLBACK_1(StartMenuScene::GoToExit, this) );
    exitMenuItem->setPosition( Vec2(visibleSize.width/2 + origin.x,
                                     visibleSize.height/2 + origin.y - 80 ) );

    auto menu = Menu::create(startMenuItem, infoMenuItem, exitMenuItem,  NULL);
    menu->setPosition(Vec2(Vec2::ZERO));
    this->addChild(menu, 3);

    //---------------------Sky------------------------------
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
    ground->setAnchorPoint( Vec2::ANCHOR_BOTTOM_LEFT );
    ground->setPosition( 0, 0);
    this->addChild(ground, 1);
    //---------------------Ground-END------------------------------
    //---------------------Ground------------------------------
    auto ground2 = Sprite::create("Sprites/Enviroment/ground.png");
    ground2->setAnchorPoint( Vec2::ANCHOR_BOTTOM_LEFT );
    ground2->setPosition( 0, 119);
    this->addChild(ground2, 1);
    //---------------------Ground-END------------------------------


    return true;
}

void StartMenuScene::GoToGame(cocos2d::Ref *sener) {

    auto gameScene = GameProscesScene::createScene();
    Director::getInstance()->replaceScene( TransitionFade::create( 0.5, gameScene) );

}


void StartMenuScene::GoToExit(cocos2d::Ref *sender) {
    Director::getInstance()->end();
}
