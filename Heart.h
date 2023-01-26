//
// Created by Marius on 26/01/2023.
//

#ifndef ASTEROIDS_HEART_H
#define ASTEROIDS_HEART_H

#include "Entity.h"
#include <SFML/Graphics.hpp>


class Heart : public Entity {
public:
    Heart() = delete;
    Heart(sf::Vector2f position);
private:
protected:
    void reactCollision(const Entity& other) override;
};


#endif //ASTEROIDS_HEART_H
