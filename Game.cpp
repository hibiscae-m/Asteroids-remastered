//
// Created by Marius on 27/12/2022.
//

#include "Game.h"

constexpr float WINDOW_WIDTH{1900};
constexpr float WINDOW_LENGTH{1200};
constexpr std::string_view WINDOW_TITLE{"Game!"};

Game::Game() :
    window{sf::VideoMode(WINDOW_WIDTH, WINDOW_LENGTH), WINDOW_TITLE.data()},
    game_manager(window)
{}

void Game::run() {
    game_manager.addFlight();
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    sf::Time time_since_last_asteroid = sf::Time::Zero;
    while (window.isOpen()) {
        time_since_last_update += clock.restart();
        if (time_since_last_update > TIME_PER_FRAME) {
            time_since_last_update -= TIME_PER_FRAME;
            processEvents();
        }
        time_since_last_asteroid += asteroid_spawn_clock.restart();
        if (time_since_last_asteroid > sf::seconds(3)) {
            time_since_last_asteroid -= sf::seconds(3);
            game_manager.addAsteroid();
        }
        render();
        game_manager.update();
    }
}

void Game::processEvents() {
    sf::Event event{};
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            game_manager.addAsteroid();
    }
    game_manager.move(loop.restart().asSeconds());
}

void Game::render() {
    window.clear();
    game_manager.draw();
    window.display();
}