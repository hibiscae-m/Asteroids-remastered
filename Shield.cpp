//
// Created by Marius on 14/02/2023.
//

#include "Shield.h"

Shield::Shield(GameManager &game_manager, sf::Vector2f position) :
    Bonus(game_manager, position, "resources/shield_bonus.png")
{
    type = Type::Shield;
}
