//
// Created by cub3d on 13/09/18.
//

#include <Settings/SettingsParser.h>
#include "BreakoutScene.h"
#include "Scene/SceneElementPrototype.h"

Unknown::KeyBind left(SDLK_LEFT, "Left");
Unknown::KeyBind right(SDLK_RIGHT, "Right");
Unknown::KeyBind deploy(SDLK_SPACE, "Space");

bool attached = true;

BreakoutScene::BreakoutScene() : Scene() {}

//TODO: need to clear the screen before drawing next frame, as this is no longer default behaviour

void BreakoutScene::update() {
    auto ball = getEntity("Ball");
    auto paddle = getEntity("Paddle");

    Scene::update();

    b2Vec2 speed(0, 0);

    if(left.pressed() && paddle->position.x > paddle->prototype.size.width/2) {
        speed = b2Vec2(-8, 0);
    }

    if(right.pressed() && paddle->position.x < 16 - paddle->prototype.size.width/2) {
        speed = b2Vec2(8, 0);
    }

    paddle->getComponent<UK::PhysicsBodyComponent>()->body->SetLinearVelocity(speed);

    auto lin = ball->getComponent<UK::PhysicsBodyComponent>()->body->GetLinearVelocity();
    if(std::abs(lin.y) < 10) {
        int speed = 10;

        if(lin.y < 0)
            speed *= -1;


        ball->getComponent<UK::PhysicsBodyComponent>()->body->SetLinearVelocity(b2Vec2(lin.x, speed));
    }

    if(attached) {
        if(deploy.pressed()) {
            ball->getComponent<Unknown::PhysicsBodyComponent>()->body->ApplyForceToCenter(b2Vec2(RANDINT(-200, 200), 160 * 9.8), true);
            attached = false;
        }

        ball->setPosition(paddle->position.x, paddle->position.y - 0.4);
    }

    if(ball->position.y > 18) {
        attached = true;
        ball->getComponent<Unknown::PhysicsBodyComponent>()->body->SetLinearVelocity(b2Vec2(0, 0));
        ball->setPosition(paddle->position.x, paddle->position.y-0.4);
    }
}

void BreakoutScene::reset() {
    Scene::reset();

    loadScenegraph("BreakoutScene.json");

    for(int x = 0; x < 8; x++) {
        for (int y = 0; y < 5; y++) {
            auto brick = UK_LOAD_ENTITY_AT("Brick.json", 2 * x + 1, y + 0.5);
            addObject(brick);

            contactManager.addListener(getEntity("Ball"), brick, [](auto objs, bool touchgin) {
                objs.second->queueDisable();
                objs.first->template getComponent<Unknown::PhysicsBodyComponent>()->body->ApplyForceToCenter(b2Vec2(RANDINT(-100, 100), -200), true);
            });
        }
    }

    registerEntityCollision("Ball", "Paddle", [&](auto objs, bool touching) {
        objs.first->template getComponent<Unknown::PhysicsBodyComponent>()->body->ApplyForceToCenter(b2Vec2(RANDINT(-100, 100), -1 * 10 * 9.8), true);
    });

    attached = true;
}
