//
// Created by Marius on 26/01/2023.
//

#include "Heart.h"

Heart::Heart(GameManager& game_manager, sf::Vector2f position)
  : Bonus(game_manager, position, "resources/heart.png")
{
    type = Type::Heart;
}
