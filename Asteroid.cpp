//
// Created by Marius on 27/12/2022.
//

#include "Asteroid.h"
#include <cstdlib>

Asteroid::Asteroid() : Entity("resources/asteroid.png") {
    srand((unsigned) time(nullptr));
    sprite.rotate(rand() % 360);
    sprite.setPosition(800, 450);
    speed = 5000.f;
}
