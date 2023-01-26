//
// Created by Marius on 26/01/2023.
//

#include "Heart.h"

Heart::Heart(GameManager& game_manager, sf::Vector2f position)
  : Entity("resources/heart.png"),
    game_manager(game_manager)
{
    type = Type::Heart;
    sprite.setScale(0.3, 0.3);
    sprite.setPosition(position);
    hitbox.setRadius(static_cast<float>(hitbox.getRadius() * 0.3));
    hitbox.setOrigin(hitbox.getGlobalBounds().width/2, hitbox.getGlobalBounds().height/2);
    hitbox.setPosition(sprite.getPosition());
}

void Heart::reactCollision(const Entity& other) {
    if (other.getType() == Type::Flight) {
        game_manager.addScore(100, sprite.getPosition());
        destructed = true;
    }
}
