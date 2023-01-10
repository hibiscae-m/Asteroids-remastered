//
// Created by Marius on 27/12/2022.
//

#include "Asteroid.h"
#include <cstdlib>
#include <random>

Asteroid::Asteroid(GameManager& game_manager, Asteroid* parent) : Entity("resources/asteroid.png"), game_manager(game_manager) {
    type = Type::Asteroid;
    auto generator = std::random_device();
    auto random_position = std::uniform_real_distribution<float>(500,800);
    auto random_rotation = std::uniform_real_distribution<float>(0,359);
    sprite.rotate(random_rotation(generator));
    sprite.setPosition(random_position(generator), random_position(generator));
    speed = 300.f;
    angle = sprite.getRotation();
    if (parent) {
        sprite.setPosition(parent->getPosition());
        sprite.setScale(parent->getScale() / 1.3f);
        hitbox.setScale(sprite.getScale());
    }
}

void Asteroid::move(float delta_time) {
    sprite.rotate(1.f);
    Entity::move(delta_time);
}

void Asteroid::reactCollision(const Entity& other) {
    if (other.getType() == Type::Missile) {
        destructed = true;
        for (auto i=0; i<3; i++)
            game_manager.addToBuffer(std::make_unique<Asteroid>(game_manager, this));
    }
}
