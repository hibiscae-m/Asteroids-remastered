//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include <string_view>
#include <SFML/Graphics.hpp>
#include "Flight.h"
#include "Asteroid.h"
#include "GameManager.h"
#include "UI.h"

class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void render();
    void start();

    bool game_started = false;

    sf::RenderWindow window;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f/60.f);
    sf::Clock loop{};
    GameManager game_manager;
    UI ui;
};


#endif //ASTEROIDS_GAME_H
