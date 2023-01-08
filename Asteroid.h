//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Asteroid : public Entity {
public:
    Asteroid();
    void move(float delta_time) override;
};


#endif //ASTEROIDS_ASTEROID_H
