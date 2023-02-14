//
// Created by Marius on 14/02/2023.
//

#ifndef ASTEROIDS_MULTIPLESHOTS_H
#define ASTEROIDS_MULTIPLESHOTS_H

#include "Bonus.h"
#include "GameManager.h"
#include <SFML/Graphics.hpp>

class MultipleShots : public Bonus {
public:
    MultipleShots() = delete;
    MultipleShots(GameManager& game_manager, sf::Vector2f position);
};


#endif //ASTEROIDS_MULTIPLESHOTS_H
