//
// Created by aragog on 19/07/15.
//

#include "HUD.h"


void HUD::initOptions( )
{

//-----------------HUD DEFENITION-------------------------------

    auto backboard = cocos2d::Sprite::create("Sprites/Hood/hood.png");
    backboard->setPosition(Vec2::ZERO);
    backboard->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    this->addChild( backboard, 3 );

    auto skils  = cocos2d::Sprite::create("Sprites/Hood/skils.png");
    skils->setPosition(Vec2( 666, 80 ));
    skils->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    this->addChild( skils, 3 );

    auto stats  = cocos2d::Sprite::create("Sprites/Hood/stats.png");
    stats->setPosition(Vec2(100, 80));
    stats->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    this->addChild( stats, 3 );

    auto weapon = cocos2d::Sprite::create("Sprites/Hood/weapon.png");
    weapon->setPosition(Vec2(250, 80));
    weapon->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    this->addChild( weapon, 3 );
}
