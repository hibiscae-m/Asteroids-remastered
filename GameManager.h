//
// Created by Marius on 30/12/2022.
//

#ifndef ASTEROIDS_GAMEMANAGER_H
#define ASTEROIDS_GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Entity.h"
#include "LivingSpace.h"
#include "UI.h"

class GameManager {
public:
    GameManager() = delete;
    explicit GameManager(sf::RenderWindow& window, UI& ui);

    void addFlight();
    void addAsteroid(int number);
    void addExplosion(sf::Vector2f position);
    void addToBuffer(std::unique_ptr<Entity> entity);

    void move(float delta_time) const;
    void draw() const;
    void update();

private:
    void add();
    void clear();
    void checkCollision() const;
    void checkPosition() const;
    void spawnAsteroids();
    void updateLevel();

    std::vector<std::unique_ptr<Entity>> entities{};
    std::vector<std::unique_ptr<Entity>> buffer{};

    sf::RenderWindow& window;
    const float OOB_limit = 200; // Define maximal distance (pixels) where Elements are living out of screen
    LivingSpace living_space;
    UI& ui;

    sf::Clock asteroid_spawn_clock{};
    sf::Time time_since_last_asteroid = sf::Time::Zero;
    sf::Time asteroid_spawn_timer = sf::seconds(3);
    int amount_of_spawns = 1;
};


#endif //ASTEROIDS_GAMEMANAGER_H
