//
// Created by Marius on 09/02/2023.
//

#ifndef ASTEROIDS_SHOOTSPEED_H
#define ASTEROIDS_SHOOTSPEED_H

#include "Bonus.h"

class SpeedBoost : public Bonus {
public:
    SpeedBoost() = delete;
    SpeedBoost(GameManager& game_manager, sf::Vector2f position);
};


#endif //ASTEROIDS_SHOOTSPEED_H
