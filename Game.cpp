//
// Created by Marius on 27/12/2022.
//

#include "Game.h"

constexpr float WINDOW_WIDTH{1900};
constexpr float WINDOW_LENGTH{1200};
constexpr std::string_view WINDOW_TITLE{"Game!"};

Game::Game() :
    window{sf::VideoMode(WINDOW_WIDTH, WINDOW_LENGTH), WINDOW_TITLE.data()},
    game_manager(window, ui),
    ui(window)
{}

void Game::run() {
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    while (window.isOpen()) {
        time_since_last_update += clock.restart();
        if (time_since_last_update > TIME_PER_FRAME) {
            time_since_last_update -= TIME_PER_FRAME;
            processEvents();
            render();
            if (!game_manager.isGameOver())
                game_manager.update();
        }
    }
}

void Game::start() {
    game_manager.addFlight();
    game_manager.setGameOver(false);
}

void Game::processEvents() {
    sf::Event event{};
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (game_manager.isGameOver()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                if (ui.getChoice() == HomeChoices::Play)
                    start();
                else if (ui.getChoice() == HomeChoices::HighScores) {}
                else if (ui.getChoice() == HomeChoices::Quit)
                    window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                ui.increment();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                ui.decrement();
        }
    }
    if (!game_manager.isGameOver())
        game_manager.move(loop.restart().asSeconds());
}

void Game::render() {
    window.clear();
    if (!game_manager.isGameOver()) {
        game_manager.draw();
        ui.drawGameUi();
    }
    else {
        ui.drawHomeUi();
    }
    window.display();
}