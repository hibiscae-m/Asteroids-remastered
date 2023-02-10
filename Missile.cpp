//
// Created by Marius on 09/01/2023.
//

#include "Missile.h"
#include <limits>

Missile::Missile(sf::Vector2f position, float angle) : Entity("resources/missile.png") {
    type = Type::Missile;
    // Drastically reducing hitbox for better collision with asteroids
    hitbox.setScale(hitbox.getScale().x / 10, hitbox.getScale().y / 10);
    sprite.setPosition(position);
    this->angle = angle;
    sprite.setRotation(this->angle);
    speed = 3000.f;
}

void Missile::move(float delta_time) {
    lifetime += clock.restart();
    if (lifetime > sf::seconds(1))
        destructed = true;
    Entity::move(delta_time);
}

void Missile::reactCollision(const Entity& other) {
    if (other.getType() == Type::Asteroid) {
        destructed = true;
        type = Type::Other; // Prevents missiles to destroy all lv 2 asteroids
    }
}
