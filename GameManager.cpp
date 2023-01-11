//
// Created by Marius on 30/12/2022.
//

#include "GameManager.h"
#include "Flight.h"
#include "Asteroid.h"

GameManager::GameManager(sf::RenderWindow& window) :
    living_space{window, OOB_limit},
    window(window)
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
    addToBuffer(std::make_unique<Asteroid>(*this));
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
    add();
}