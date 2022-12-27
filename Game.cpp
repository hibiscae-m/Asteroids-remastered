//
// Created by Marius on 27/12/2022.
//

#include "Game.h"

constexpr unsigned int WINDOW_WIDTH{1600};
constexpr unsigned int WINDOW_LENGTH{900};
constexpr std::string_view WINDOW_TITLE{"Game!"};

Game::Game() :
    window{sf::VideoMode(WINDOW_WIDTH, WINDOW_LENGTH), WINDOW_TITLE.data()}
{}

void Game::run() {
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    while (window.isOpen()) {
        time_since_last_update += clock.restart();
        if (time_since_last_update > TIME_PER_FRAME) {
            time_since_last_update -= TIME_PER_FRAME;
            processEvents();
        }
    render();
    }
}

void Game::processEvents() {
    sf::Event event{};
    while(window.pollEvent(event))
        if (event.type == sf::Event::Closed)
            window.close();
    flight.handlePlayerInputs(temp_clock.restart().asSeconds());
}

void Game::render() {
    window.clear();
    flight.draw(window);
    asteroid.draw(window);
    window.display();
}