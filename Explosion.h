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
    sf::Time time_before_dies = sf::milliseconds(100);
    sf::Time lifetime = sf::Time::Zero;
};


#endif //ASTEROIDS_EXPLOSION_H
