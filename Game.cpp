//
// Created by Marius on 27/12/2022.
//

#include "Game.h"

constexpr unsigned int WINDOW_WIDTH{1600};
constexpr unsigned int WINDOW_LENGTH{900};
constexpr std::string_view WINDOW_TITLE{"Game!"};

Game::Game() :
    window{sf::VideoMode(WINDOW_WIDTH, WINDOW_LENGTH), WINDOW_TITLE.data()},
    game_manager(WINDOW_WIDTH, WINDOW_LENGTH)
{}

void Game::run() {
    game_manager.addToBuffer(std::make_unique<Flight>(game_manager));
    game_manager.addToBuffer(std::make_unique<Asteroid>(game_manager));
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    while (window.isOpen()) {
        time_since_last_update += clock.restart();
        if (time_since_last_update > TIME_PER_FRAME) {
            time_since_last_update -= TIME_PER_FRAME;
            processEvents();
        }
        render();
        game_manager.update();
    }
}

void Game::processEvents() {
    sf::Event event{};
    while(window.pollEvent(event))
        if (event.type == sf::Event::Closed)
            window.close();
    game_manager.move(temp_clock.restart().asSeconds());
    game_manager.checkCollision();
}

void Game::render() {
    window.clear();
    game_manager.draw(window);
    window.display();
}