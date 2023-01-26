//
// Created by Marius on 26/01/2023.
//

#ifndef ASTEROIDS_HEART_H
#define ASTEROIDS_HEART_H

#include "Entity.h"
#include "GameManager.h"
#include <SFML/Graphics.hpp>


class Heart : public Entity {
public:
    Heart() = delete;
    Heart(GameManager& game_manager, sf::Vector2f position);
private:
    void reactCollision(const Entity& other) override;
    GameManager& game_manager;
};


#endif //ASTEROIDS_HEART_H
