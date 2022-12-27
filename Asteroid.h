//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <SFML/Graphics.hpp>

class Asteroid {
public:
    Asteroid();
    void draw(sf::RenderWindow& window);
private:
    sf::Sprite sprite;
    sf::Texture texture;
};


#endif //ASTEROIDS_ASTEROID_H
