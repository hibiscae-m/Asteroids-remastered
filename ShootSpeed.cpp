//
// Created by Marius on 09/02/2023.
//

#include "ShootSpeed.h"

SpeedBoost::SpeedBoost(GameManager &game_manager, sf::Vector2f position)
  : Bonus(game_manager, position, "resources/shootspeed_bonus.png")
{
    type = Type::ShootSpeed;
}
