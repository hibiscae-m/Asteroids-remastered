//
// Created by Marius on 09/02/2023.
//

#include "Bonus.h"

Bonus::Bonus(GameManager& game_manager, sf::Vector2f position, std::string_view texture_location)
        : Entity(texture_location),
          game_manager(game_manager)
{
    sprite.setPosition(position);
    hitbox.setRadius(static_cast<float>(hitbox.getRadius() * 0.3));
    hitbox.setOrigin(hitbox.getGlobalBounds().width/2, hitbox.getGlobalBounds().height/2);
    hitbox.setPosition(sprite.getPosition());
}

void Bonus::reactCollision(const Entity& other) {
    if (other.getType() == Type::Flight) {
        game_manager.addScore(100, sprite.getPosition());
        destructed = true;
    }
}

void Bonus::move(float delta_time) {
    time_after_spawn += clock.restart();
    auto alpha_sprite = static_cast<int>(255 - ((255 / life_time.asSeconds()) * time_after_spawn.asSeconds()));
    sprite.setColor(sf::Color(sprite.getColor().r,
                              sprite.getColor().g,
                              sprite.getColor().b,
                              alpha_sprite));
    if (time_after_spawn >= life_time)
        destructed = true;
}