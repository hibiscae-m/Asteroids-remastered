//
// Created by Marius on 09/01/2023.
//

#include "Missile.h"

Missile::Missile(sf::Vector2f position, float angle) : Entity("resources/missile.png") {
    sprite.setPosition(position);
    this->angle = angle;
    sprite.setRotation(this->angle);
    speed = 3000.f;
}

void Missile::move(float delta_time) {
    lifetime += clock.restart();
    if (lifetime > sf::seconds(2))
        destructed = true;
    Entity::move(delta_time);
}

void Missile::reactCollision(const Entity& other) {
    if (other.getType() == Type::Asteroid)
        destructed = true;
}
