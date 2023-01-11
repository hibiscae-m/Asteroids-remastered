//
// Created by Marius on 10/01/2023.
//

#ifndef ASTEROIDS_LIVINGSPACE_H
#define ASTEROIDS_LIVINGSPACE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class LivingSpace {
public:
    LivingSpace() = delete;
    LivingSpace(float window_width, float window_length, float out_of_screen_limit = 0 );
    bool operator==(const Entity& entity) const;
    bool operator!=(const Entity& entity) const;
    enum MapCorner { UpLeft, UpRight, BottomLeft, BottomRight };
private:
    float window_width;
    float window_length;
    float out_of_screen_limit;
};


#endif //ASTEROIDS_LIVINGSPACE_H
