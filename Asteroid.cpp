//
// Created by Marius on 27/12/2022.
//

#include "Asteroid.h"
#include <random>

Asteroid::Asteroid(GameManager& game_manager, sf::Vector2f random_position, float random_angle, float random_speed) :
    Entity("resources/asteroid.png"),
    game_manager(game_manager)
{
    type = Type::Asteroid;
    angle = random_angle;
    sprite.setPosition(random_position);
    sprite.setRotation(angle);
    speed = random_speed;
    score_value = static_cast<int>(10 / sprite.getScale().x);
}

Asteroid::Asteroid(GameManager& game_manager, Asteroid* parent, int counter) :
    Entity("resources/asteroid.png"),
    game_manager(game_manager),
    counter(counter)
{
    type = Type::Asteroid;
    speed = parent->speed;
    auto generator = std::random_device();
    auto angle_distribution = std::uniform_real_distribution<float>(1, 360);
    angle = angle_distribution(generator);
    sprite.setRotation(angle);
    sprite.setPosition(parent->getPosition());
    sprite.setScale(parent->getScale() * child_size_ratio);
    hitbox.setScale(sprite.getScale());
    score_value = static_cast<int>(10 / sprite.getScale().x);
}

void Asteroid::move(float delta_time) {
    sprite.rotate(rotation_speed);
    Entity::move(delta_time);
}

void Asteroid::reactCollision(const Entity& other) {
    if (other.getType() == Type::Missile) {
        destructed = true;
        game_manager.addScore(score_value, sprite.getPosition());
        game_manager.addExplosion(sprite.getPosition());
        auto generator = std::random_device();
        auto spawn_bonus_distribution = std::uniform_int_distribution(0, 20);
        if (spawn_bonus_distribution(generator) == 0) {
            auto bonus_type_distribution = std::uniform_int_distribution(0, 3);
            auto random_bonus_type = bonus_type_distribution(generator);
            switch(random_bonus_type) {
                case bonus_type::Heart:
                    game_manager.addHeart(sprite.getPosition());
                    break;
                case bonus_type::SpeedBoost:
                    game_manager.addSpeedBoost(sprite.getPosition());
                    break;
                case bonus_type::Shield:
                    game_manager.addShield(sprite.getPosition());
                    break;
                case bonus_type::MultipleShots:
                    game_manager.addMultipleShots(sprite.getPosition());
                    break;
                default:
                    break;
            }
        }
        if (counter < counter_max)
            for (auto i=0; i < amount_of_children; i++)
                game_manager.addToBuffer(std::make_unique<Asteroid>(game_manager, this, counter + 1));
    }
}
