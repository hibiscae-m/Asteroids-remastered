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
    //Constructor called when new Asteroids spawn
    Asteroid(GameManager& game_manager, sf::Vector2f random_position, float random_angle, float random_speed);
    //Constructor called from the destruction of an asteroid
    Asteroid(GameManager& game_manager, Asteroid* parent, int counter);

    void move(float delta_time) override;
    void reactCollision(const Entity& other) override;
private:
    enum bonus_type { Heart, SpeedBoost };
    inline sf::Vector2f getScale() { return sprite.getScale(); };
    int counter{};
    GameManager& game_manager;
    float rotation_speed = 1.f;
    short counter_max = 2;
    short amount_of_children = 3;
    float child_size_ratio = 0.7;
};


#endif //ASTEROIDS_ASTEROID_H
