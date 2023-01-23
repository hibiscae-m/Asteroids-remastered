//
// Created by Marius on 30/12/2022.
//

#include "GameManager.h"
#include "Flight.h"
#include "Asteroid.h"
#include "Explosion.h"
#include "TextScore.h"

#include <random>
#include <cmath>

GameManager::GameManager(sf::RenderWindow& window, UI& ui) :
    living_space{window, OOB_limit},
    window(window),
    ui(ui)
{
}

void GameManager::addToBuffer(std::unique_ptr<Entity> entity) {
    buffer.push_back(std::move(entity));
}

void GameManager::addFlight() {
    addToBuffer(std::make_unique<Flight>(*this,
                                         static_cast<float>(window.getSize().x) / 2,
                                         static_cast<float>(window.getSize().y) / 2 ));
}

void GameManager::addAsteroid() {
    auto generator = std::random_device();
    auto map_corner_distribution = std::uniform_int_distribution(0,7);
    auto speed_distribution = std::uniform_real_distribution<float>(asteroid_min_speed, asteroid_max_speed);
    auto random_map_corner = map_corner_distribution(generator);
    auto random_position = living_space.getRandomOOBPosition(random_map_corner, generator);
    auto random_angle = living_space.getRandomAngle(random_map_corner, generator);
    auto random_speed = speed_distribution(generator);

    addToBuffer(std::make_unique<Asteroid>(*this, random_position, random_angle, random_speed));
}

void GameManager::spawnAsteroids() {
    time_since_last_asteroid += asteroid_spawn_clock.restart();
    if (time_since_last_asteroid > asteroid_spawn_timer) {
        time_since_last_asteroid -= asteroid_spawn_timer;
        // additional asteroid every 5 levels
        for (auto i = 0; i <= static_cast<int>(trunc(static_cast<float>(level) / 5)); i++)
            addAsteroid();
    }
}

void GameManager::addExplosion(sf::Vector2f position) {
    addToBuffer(std::make_unique<Explosion>(position));
}

void GameManager::add() {
    for (auto& entity: buffer)
        entities.push_back(std::move(entity));
    buffer.clear();
}

void GameManager::draw() const {
    // Going in reverse order to draw Flight above the rest
    for (auto i = entities.size(); i > 0u; i--)
        entities[i-1]->draw(window);
}

void GameManager::move(const float delta_time) const {
    for (const auto& entity: entities)
        entity->move(delta_time);
    checkCollision();
    checkPosition();
}

void GameManager::checkCollision() const {
    for (const auto& first_entity: entities)
        for (const auto& second_entity: entities)
            if (first_entity != second_entity)
                first_entity->checkCollision(*second_entity);
}

void GameManager::checkPosition() const {
    for (const auto& entity: entities)
        // if entity goes out of range of living space
        if (*entity != living_space)
            entity->callDestruction();
}

void GameManager::clear() {
    for (auto i = 0u; i < entities.size(); i++)
        if (entities[i]->isDestructed())
            entities.erase(entities.begin()+i);
}

void GameManager::update() {
    clear();
    checkLevel();
    spawnAsteroids();
    add();
}

void GameManager::addScore(int value, sf::Vector2f position) {
    score += value;
    ui.setScore(score);
    addToBuffer(std::make_unique<TextScore>(value, position));
}

void GameManager::setUIHealth(short health) {
    ui.setHealth(health);
}

void GameManager::checkLevel() {
    auto checking_level = static_cast<int>(trunc((score / score_level_bearing) + 1));
    if (level != checking_level) {
        level = checking_level;
        ui.setLevel(level);
        asteroid_spawn_timer = sf::seconds(1 / static_cast<float>(level) + 2);
    }
}