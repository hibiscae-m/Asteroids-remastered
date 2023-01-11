//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "GameManager.h"
#include <random>

class Asteroid : public Entity {
public:
    explicit Asteroid(GameManager& game_manager, Asteroid* parent = nullptr, int counter = 1);
    void move(float delta_time) override;
    void reactCollision(const Entity& other) override;
    inline sf::Vector2f getScale() { return sprite.getScale(); };
private:
    static sf::Vector2f getRandomPosition(int map_corner, std::random_device& generator);
    static float getRandomAngle(int map_corner, std::random_device& generator);
    enum MapCorner { UpLeft, UpRight, BottomLeft, BottomRight };
    int counter{};
    GameManager& game_manager;
};


#endif //ASTEROIDS_ASTEROID_H
