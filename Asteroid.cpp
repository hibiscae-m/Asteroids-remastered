//
// Created by Marius on 27/12/2022.
//

#include "Asteroid.h"
#include <random>

Asteroid::Asteroid(GameManager& game_manager, UI& ui, sf::Vector2f random_position, float random_angle) :
    Entity("resources/asteroid.png"),
    game_manager(game_manager),
    ui(ui)
{
    type = Type::Asteroid;
    angle = random_angle;
    sprite.setPosition(random_position);
    sprite.setRotation(angle);
    speed = 300.f;
}

Asteroid::Asteroid(GameManager& game_manager, UI& ui, Asteroid* parent, int counter) :
    Entity("resources/asteroid.png"),
    game_manager(game_manager),
    ui(ui),
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
        ui.addScore(static_cast<int>(10 / sprite.getScale().x));
        game_manager.addExplosion(sprite.getPosition());
        destructed = true;
        if (counter < 2)
            for (auto i=0; i<3; i++)
                game_manager.addToBuffer(std::make_unique<Asteroid>(game_manager, ui, this, counter + 1));
    }
}
