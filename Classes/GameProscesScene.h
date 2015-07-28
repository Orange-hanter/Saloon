//
// Created by aragog on 20/07/15.
//

#ifndef MYGAME_GAMEPROSCESSCENE_H
#define MYGAME_GAMEPROSCESSCENE_H

#include "cocos2d.h"
#include "HUD.h"

class GameProscesScene: public cocos2d::Layer {


public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void Update(float dt);
    CREATE_FUNC(GameProscesScene);

private:
    HUD* hud;

};


#endif //MYGAME_GAMEPROSCESSCENE_H
