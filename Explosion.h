//
// Created by Marius on 12/01/2023.
//

#ifndef ASTEROIDS_EXPLOSION_H
#define ASTEROIDS_EXPLOSION_H

#include "Entity.h"

class Explosion : public Entity {
public:
    Explosion() = delete;
    explicit Explosion(sf::Vector2f position);
private:
    void update();
    void move(float delta_time) override;
    sf::Clock loop{};
    sf::Time lifetime = sf::Time::Zero;
    short counter{};
};


#endif //ASTEROIDS_EXPLOSION_H
