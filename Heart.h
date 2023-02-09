//
// Created by Marius on 26/01/2023.
//

#ifndef ASTEROIDS_HEART_H
#define ASTEROIDS_HEART_H

#include "Bonus.h"
#include "GameManager.h"
#include <SFML/Graphics.hpp>
#include <string_view>

class Heart : public Bonus {
public:
    Heart() = delete;
    Heart(GameManager& game_manager, sf::Vector2f position);
};


#endif //ASTEROIDS_HEART_H
