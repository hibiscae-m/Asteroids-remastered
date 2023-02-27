//
// Created by Marius on 09/01/2023.
//

#ifndef ASTEROIDS_MISSILE_H
#define ASTEROIDS_MISSILE_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Missile : public Entity {
public:
    Missile() = delete;
    Missile(sf::Vector2f position, float angle);
    void move(float delta_time) override;
private:
    void reactCollision(const Entity& other) override;
    sf::Time lifetime = sf::Time::Zero;
    sf::Clock clock;
    sf::Sound sound;
};


#endif //ASTEROIDS_MISSILE_H
