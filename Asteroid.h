//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "GameManager.h"
#include <random>
#include "UI.h"

class Asteroid : public Entity {
public:
    Asteroid() = delete;
    Asteroid(GameManager& game_manager, sf::Vector2f random_position, float random_angle);
    Asteroid(GameManager& game_manager, Asteroid* parent, int counter);
    void move(float delta_time) override;
    void reactCollision(const Entity& other) override;
    inline sf::Vector2f getScale() { return sprite.getScale(); };
private:
    int counter{};
    GameManager& game_manager;
};


#endif //ASTEROIDS_ASTEROID_H
