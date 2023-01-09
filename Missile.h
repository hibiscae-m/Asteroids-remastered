//
// Created by Marius on 09/01/2023.
//

#ifndef ASTEROIDS_MISSILE_H
#define ASTEROIDS_MISSILE_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Missile : public Entity {
public:
    Missile() = delete;
    Missile(sf::Vector2f position, float angle);
    void move(float delta_time) override;
    void reactCollision(const Entity& other) override;
private:
    sf::Time lifetime = sf::Time::Zero;
    sf::Clock clock;
};


#endif //ASTEROIDS_MISSILE_H
