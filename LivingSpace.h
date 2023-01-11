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
    explicit LivingSpace(sf::RenderWindow& window, short out_of_screen_limit = 0 );

    enum MapCorner { UpLeft, UpRight, BottomLeft, BottomRight };

    bool operator==(const Entity& entity) const;
    bool operator!=(const Entity& entity) const;

private:
    sf::RenderWindow& window;
    short out_of_screen_limit;
};


#endif //ASTEROIDS_LIVINGSPACE_H
