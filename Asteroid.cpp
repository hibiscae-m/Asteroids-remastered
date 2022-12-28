//
// Created by Marius on 27/12/2022.
//

#include "Asteroid.h"
#include <cstdlib>
#include <iostream>

Asteroid::Asteroid() {
    if (!texture.loadFromFile("resources/asteroid.png"))
        throw std::invalid_argument("cannot find file 'resources/asteroid.png'");
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    srand((unsigned) time(nullptr));
    int random = rand();
}

void Asteroid::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
