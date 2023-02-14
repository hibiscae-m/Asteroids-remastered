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
    void addAsteroid();
    void addExplosion(sf::Vector2f position);
    void addHeart(sf::Vector2f position);
    void addSpeedBoost(sf::Vector2f position);
    void addShield(sf::Vector2f position);
    void addToBuffer(std::unique_ptr<Entity> entity);

    void addScore(int value, sf::Vector2f position);
    void setUIHealth(short health);

    void move(float delta_time) const;
    void draw() const;
    void update();

private:
    void add();
    void clear();
    void checkCollision() const;
    void checkPosition() const;
    void checkLevel();
    void spawnAsteroids();

    std::vector<std::unique_ptr<Entity>> entities{};
    std::vector<std::unique_ptr<Entity>> buffer{};

    sf::RenderWindow& window;
    const float OOB_limit = 200; // Define maximal distance (pixels) where Elements are living out of screen
    LivingSpace living_space;
    UI& ui;

    sf::Clock asteroid_spawn_clock{};
    sf::Time time_since_last_asteroid = sf::Time::Zero;
    sf::Time asteroid_spawn_timer = sf::seconds(3);
    float asteroid_min_speed = 300;
    float asteroid_max_speed = 400;

    int score = 0;
    int score_level_bearing = 500; //level will up every X points
    int level = 1;
};


#endif //ASTEROIDS_GAMEMANAGER_H
