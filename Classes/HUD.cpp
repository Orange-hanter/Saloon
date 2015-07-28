//
// Created by aragog on 19/07/15.
//

#include "HUD.h"


HUD* HUD::createLayer(const std::string& _message, cocos2d::Size size)
{
    HUD* a = new HUD();
    a->create();
    a->setColor(cocos2d::Color3B(110, 40, 50));

    a->setContentSize( size );
    a->setAnchorPoint(cocos2d::Vec2::ZERO);

    a->initOptions(_message);

    return a;
}

void HUD::initOptions(const std::string& _message)
{

    //Create a sprite
    auto _messageLabel = cocos2d::Label::createWithSystemFont("HUD","Arial",19);
    _messageLabel->setColor(cocos2d::Color3B(255, 215, 0));

    //Set sprite position
    _messageLabel->setPosition(cocos2d::Vec2(cocos2d::Director::getInstance()->getVisibleSize().width,
                                             cocos2d::Director::getInstance()->getVisibleSize().height));

    //Add it in as child
    this->addChild(_messageLabel, 4);

}
