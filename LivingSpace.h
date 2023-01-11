//
// Created by Marius on 10/01/2023.
//

#ifndef ASTEROIDS_LIVINGSPACE_H
#define ASTEROIDS_LIVINGSPACE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <random>

class LivingSpace {
public:
    LivingSpace() = delete;
    explicit LivingSpace(sf::RenderWindow& window, float out_of_screen_limit = 0 );

    sf::Vector2f getRandomOOBPosition(int map_corner, std::random_device& generator) const;
    float getRandomAngle(int map_corner, std::random_device& generator) const;

    enum MapCorner { UpLeft, UpMiddle, UpRight,
                     MiddleLeft, MiddleRight,
                     BottomLeft, BottomMiddle, BottomRight };

    bool operator==(const Entity& entity) const;
    bool operator!=(const Entity& entity) const;

private:
    sf::RenderWindow& window;
    float out_of_screen_limit;

    struct Coordinates {
        sf::Vector2f up_left;
        sf::Vector2f up_middle;
        sf::Vector2f up_right;
        sf::Vector2f middle_left;
        sf::Vector2f middle_right;
        sf::Vector2f bottom_left;
        sf::Vector2f bottom_middle;
        sf::Vector2f bottom_right;
    };
    Coordinates coordinates;
};


#endif //ASTEROIDS_LIVINGSPACE_H
