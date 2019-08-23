#include <iostream>
#include <UK.h>

#include "BreakoutScene.h"
#include "MainMenuScene.h"

int main() {
    UK_CREATE_WINDOW();

    UK_ADD_SCENE(BreakoutScene, "Breakout");
    UK_ADD_SCENE(MainMenuScene, "Menu");
    UK_LOAD_SCENE("Menu");
    UK_LOAD_SCENE("Breakout");

    UK_INIT_GAME();

    return 0;
}