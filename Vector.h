//
// Created by Marius on 28/12/2022.
//

#ifndef ASTEROIDS_VECTOR_H
#define ASTEROIDS_VECTOR_H

#include <SFML/Graphics.hpp>

class Vector {
public:
    Vector() = default;
    static sf::Vector2f acquire_movement(float current_speed, float angle_rotation);
};


#endif //ASTEROIDS_VECTOR_H
