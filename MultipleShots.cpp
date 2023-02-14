//
// Created by Marius on 14/02/2023.
//

#include "MultipleShots.h"

MultipleShots::MultipleShots(GameManager &game_manager, sf::Vector2f position)
    : Bonus (game_manager, position, "resources/multipleshots_bonus.png")
{
    type = Type::MultipleShots;
}
