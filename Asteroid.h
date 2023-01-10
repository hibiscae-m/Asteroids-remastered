//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "GameManager.h"

class Asteroid : public Entity {
public:
    Asteroid(GameManager& game_manager, Asteroid* parent = nullptr);
    void move(float delta_time) override;
    void reactCollision(const Entity& other) override;
    inline sf::Vector2f getScale() { return sprite.getScale(); };
private:
    GameManager& game_manager;
};


#endif //ASTEROIDS_ASTEROID_H
