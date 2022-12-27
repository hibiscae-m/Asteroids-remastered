//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include <string_view>
#include <SFML/Graphics.hpp>
#include "Flight.h"
#include "Asteroid.h"

class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void render();

    sf::RenderWindow window;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f/60.f);
    sf::Clock temp_clock{};

    Flight flight;
    Asteroid asteroid;
};


#endif //ASTEROIDS_GAME_H
