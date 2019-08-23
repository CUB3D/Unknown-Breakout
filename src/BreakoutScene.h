//
// Created by cub3d on 13/09/18.
//

#ifndef UNKNOWN_GAME_BREAKOUTSCENE_H
#define UNKNOWN_GAME_BREAKOUTSCENE_H

#include <UK.h>

class BreakoutScene : public UK::Scene {
public:
    BreakoutScene();

    virtual void update() override;
    virtual void reset() override;
};


#endif //UNKNOWN_GAME_BREAKOUTSCENE_H
