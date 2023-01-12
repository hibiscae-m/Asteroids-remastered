//
// Created by Marius on 12/01/2023.
//

#include "Explosion.h"

Explosion::Explosion(sf::Vector2f position) : Entity("resources/explosion.png") {
    sprite.setPosition(position);
    sprite.setScale(0.2, 0.2);
}

void Explosion::update() {
    lifetime += loop.restart();
    if (lifetime > sf::milliseconds(100)) {
        lifetime -= sf::milliseconds(100);
        counter++;
        sprite.setScale(sprite.getScale().x * 2, sprite.getScale().y * 2);
    }
    if (counter >= 3)
        destructed = true;
}

void Explosion::move(float delta_time) {
    update();
    Entity::move(delta_time);
}