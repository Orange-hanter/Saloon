//
// Created by aragog on 19/07/15.
//

#ifndef MYGAME_HUD_H
#define MYGAME_HUD_H

#include "cocos2d.h"

using namespace cocos2d;


class HUD: public cocos2d::LayerColor {

public:

    static HUD* createLayer(const std::string& _message, cocos2d::Size size);

    void initOptions(const std::string& _message);

};


#endif //MYGAME_HUD_H
