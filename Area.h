//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_AREA_H
#define ASTEROIDS_AREA_H

#include <SFML/Graphics.hpp>

class Area {
public:
    Area() = default;
    inline void initialize(sf::RenderWindow& window) { max_range = window.getSize(); };
    inline sf::Vector2u getMaxRange() { return max_range; }
private:
    sf::Vector2u max_range{};
};


#endif //ASTEROIDS_AREA_H
