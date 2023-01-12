//
// Created by Marius on 12/01/2023.
//

#include "Explosion.h"

Explosion::Explosion(sf::Vector2f position) : Entity("resources/explosion.png") {
    sprite.setPosition(position);
    sprite.setScale(0, 0);
}

void Explosion::update() {
    lifetime += loop.restart();
    sprite.setScale(lifetime / time_before_dies, lifetime / time_before_dies);
    if (lifetime >= time_before_dies)
        destructed = true;
}

void Explosion::move(float delta_time) {
    update();
    Entity::move(delta_time);
}