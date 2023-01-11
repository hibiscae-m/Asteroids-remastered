//
// Created by Marius on 27/12/2022.
//

#include "Asteroid.h"
#include <cstdlib>
#include <random>

Asteroid::Asteroid(GameManager& game_manager, float position_x, float position_y) :
    Entity("resources/asteroid.png"),
    game_manager(game_manager)
{
    type = Type::Asteroid;
    sprite.setPosition(position_x, position_y);
    sprite.setRotation(300);
    speed = 300.f;
    angle = sprite.getRotation();
}

Asteroid::Asteroid(GameManager& game_manager, Asteroid* parent, int counter) :
    Entity("resources/asteroid.png"),
    game_manager(game_manager),
    counter(counter)
{
    type = Type::Asteroid;
    speed = 300.f;
    auto generator = std::random_device();
    auto angle_distribution = std::uniform_real_distribution<float>(1, 360);
    angle = angle_distribution(generator);
    sprite.setRotation(angle);
    sprite.setPosition(parent->getPosition());
    sprite.setScale(parent->getScale() / 1.3f);
    hitbox.setScale(sprite.getScale());
}

void Asteroid::move(float delta_time) {
    sprite.rotate(1.f);
    Entity::move(delta_time);
}

void Asteroid::reactCollision(const Entity& other) {
    if (other.getType() == Type::Missile) {
        destructed = true;
        if (counter <= 2)
            for (auto i=0; i<3; i++)
                game_manager.addToBuffer(std::make_unique<Asteroid>(game_manager, this, counter + 1));
    }
}

sf::Vector2f Asteroid::getRandomPosition(int map_corner, std::random_device& generator) {
    switch (map_corner) {
        case LivingSpace::MapCorner::UpLeft:
            return {100, 100};
        case LivingSpace::MapCorner::UpRight:
            return {1500, 100};
        case LivingSpace::MapCorner::BottomLeft:
            return {100, 800};
        case LivingSpace::MapCorner::BottomRight:
            return {1500, 800};
        default:
            throw std::invalid_argument("getRandomPosition");
    }
}

float Asteroid::getRandomAngle(int map_corner, std::random_device& generator) {
    std::uniform_real_distribution<float> random_angle_distribution;
    switch (map_corner) {
        case LivingSpace::MapCorner::UpLeft:
            random_angle_distribution = std::uniform_real_distribution<float>(0, 90);
            break;
        case LivingSpace::MapCorner::UpRight:
            random_angle_distribution = std::uniform_real_distribution<float>(90, 180);
            break;
        case LivingSpace::MapCorner::BottomLeft:
            random_angle_distribution = std::uniform_real_distribution<float>(270, 360);
            break;
        case LivingSpace::MapCorner::BottomRight:
            random_angle_distribution = std::uniform_real_distribution<float>(180, 270);
            break;
        default:
            throw std::invalid_argument("getRandomAngle");
    }
    return random_angle_distribution(generator);
}
