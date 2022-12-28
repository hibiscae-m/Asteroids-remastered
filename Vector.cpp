//
// Created by Marius on 28/12/2022.
//

#include "Vector.h"
#include <cmath>

sf::Vector2f Vector::acquire_movement(float current_speed, float angle_rotation) {
    return { current_speed*cos(angle_rotation/180.f*static_cast<float>(M_PI)),
             current_speed*sin(angle_rotation/180.f* static_cast<float>(M_PI)) };
}