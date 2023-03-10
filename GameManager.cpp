//
// Created by Marius on 30/12/2022.
//

#include "GameManager.h"
#include "Flight.h"
#include "Asteroid.h"
#include "Explosion.h"
#include "TextScore.h"
#include "Heart.h"
#include "ShootSpeed.h"
#include "Shield.h"
#include "MultipleShots.h"

#include <random>
#include <cmath>
#include <fstream>

GameManager::GameManager(sf::RenderWindow& window, UI& ui) :
    living_space{window, OOB_limit},
    window(window),
    ui(ui)
{
    std::ifstream file;
    file.open("data.bin", std::ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&highscore), sizeof(highscore));
        file.close();
    }
    if (!music.openFromFile("resources/midnight-alexiaction.wav")) {
        // loading errors
    }
    music.play();
    music.setLoopPoints(sf::Music::TimeSpan(sf::seconds(15), sf::seconds(150)));
    music.setLoop(true);
    music.setVolume(33);
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
        time_since_last_asteroid = sf::Time::Zero;
        // additional asteroid every 5 levels
        for (auto i = 0; i <= static_cast<int>(trunc(static_cast<float>(level) / 5)); i++)
            addAsteroid();
    }
}

void GameManager::addExplosion(sf::Vector2f position) {
    addToBuffer(std::make_unique<Explosion>(position));
}

void GameManager::addHeart(sf::Vector2f position) {
    addToBuffer(std::make_unique<Heart>(*this, position));
}

void GameManager::addSpeedBoost(sf::Vector2f position) {
    addToBuffer(std::make_unique<SpeedBoost>(*this, position));
}

void GameManager::addShield(sf::Vector2f position) {
    addToBuffer(std::make_unique<Shield>(*this, position));
}

void GameManager::addMultipleShots(sf::Vector2f position) {
    addToBuffer(std::make_unique<MultipleShots>(*this, position));
}

void GameManager::add() {
    for (auto& entity: buffer)
        entities.push_back(std::move(entity));
    buffer.clear();
}

void GameManager::draw() const {
    // Going in reverse order to drawGameUi Flight above the rest
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
    if (highscore < score) {
        highscore = score;
        ui.setHighscore(score);
    }
    if (ending_game)
        if (game_over_clock.getElapsedTime() > game_over_timer) {
            for (const auto& entity: entities) {
                entity->callDestruction();
            }
            std::ofstream file;
            file.open("data.bin", std::ios::binary);
            if (file.is_open()) {
                file.write(reinterpret_cast<char*>(&highscore), sizeof(highscore));
                file.close();
            }
            reset();
            ending_game = false;
            game_over = true;
        }
    if (game_over)
        music.setVolume(33);
    else
        music.setVolume(100);
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
        asteroid_spawn_timer = sf::seconds(1 / static_cast<float>(level) + 2);
    }
}

void GameManager::setGameOver(bool statement) {
    ui.setHighscore(highscore);
    game_over = statement;
}

void GameManager::callGameOver() {
    game_over_clock.restart();
    ending_game = true;
}

void GameManager::reset() {
    level = 1;
    score = 0;
    ui.setScore(score);
    setUIHealth(3);
}
