//
// Created by Marius on 27/12/2022.
//

#include "Flight.h"

Flight::Flight() : Entity("resources/flight.png") {
    sprite.setPosition(100.f, 100.f);
}

void Flight::handlePlayerInputs(const float delta_time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        speed += ACCELERATION;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        sprite.rotate(-ANGLE_SPEED * delta_time);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        sprite.rotate(ANGLE_SPEED * delta_time);
}

void Flight::move(const float delta_time) {
    handlePlayerInputs(delta_time);
    speed -= speed * FRICTION * delta_time;
    Entity::move(delta_time);
}
