//
// Created by Marius on 27/12/2022.
//

#include "Flight.h"
#include "Vector.h"

Flight::Flight() : Entity("resources/flight.png") {
    sprite.setPosition(100.f, 100.f);
}

void Flight::handlePlayerInputs(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        speed += ACCELERATION;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        sprite.rotate(-ANGLE_SPEED * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        sprite.rotate(ANGLE_SPEED * deltaTime);
}

void Flight::move(float deltaTime) {
    handlePlayerInputs(deltaTime);
    Entity::move(deltaTime);
}
