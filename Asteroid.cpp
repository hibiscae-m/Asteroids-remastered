//
// Created by Marius on 27/12/2022.
//

#include "Asteroid.h"
#include <cstdlib>

Asteroid::Asteroid() : Entity("resources/asteroid.png") {
    srand((unsigned) time(nullptr));
    sprite.rotate(rand() % 360);
    sprite.setPosition(800, 450);
    speed = 300.f;
    angle = sprite.getRotation();
    type = Type::Asteroid;
}

void Asteroid::move(float delta_time) {
    sprite.rotate(1.f);
    Entity::move(delta_time);
}
