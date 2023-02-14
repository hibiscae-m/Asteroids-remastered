//
// Created by Marius on 14/02/2023.
//

#ifndef ASTEROIDS_SHIELD_H
#define ASTEROIDS_SHIELD_H

#include "Bonus.h"
#include "GameManager.h"
#include <SFML/Graphics.hpp>

class Shield : public Bonus {
public:
    Shield() = delete;
    Shield(GameManager& game_manager, sf::Vector2f position);
};


#endif //ASTEROIDS_SHIELD_H
