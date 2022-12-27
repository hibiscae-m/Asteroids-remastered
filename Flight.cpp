//
// Created by Marius on 27/12/2022.
//

#include "Flight.h"
#include <stdexcept>
#include <cmath>

Flight::Flight() {
    if (!texture.loadFromFile("resources/flight.png"))
        throw std::invalid_argument("cannot find file 'resources/flight.png'");
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    sprite.setPosition(100.f, 100.f);
}

void Flight::handlePlayerInputs(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        speed += ACCELERATION;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        sprite.rotate(-ANGLE_SPEED * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        sprite.rotate(ANGLE_SPEED * deltaTime);
    speed -= speed * FRICTION * deltaTime;
    sf::Vector2f movement = acquire_movement(speed * deltaTime, sprite.getRotation());
    sprite.move(movement);
}

sf::Vector2f Flight::acquire_movement(float current_speed, float angle_rotation) {
    return { current_speed*cos(angle_rotation/180.f*static_cast<float>(M_PI)),
             current_speed*sin(angle_rotation/180.f* static_cast<float>(M_PI)) };
}

void Flight::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
