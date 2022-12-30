//
// Created by Marius on 30/12/2022.
//

#include "GameManager.h"

void GameManager::add(std::unique_ptr<Entity> entity) {
    entities.push_back(std::move(entity));
}

void GameManager::draw(sf::RenderWindow& window) {
    for (const auto& entity: entities)
        entity->draw(window);
}

void GameManager::move(float delta_time) {
    for (const auto& entity: entities)
        entity->move(delta_time);
}

void GameManager::checkCollision() {
    for (const auto& first_entity: entities)
        for (const auto& second_entity: entities)
            if (first_entity != second_entity)
                first_entity->checkCollision(*second_entity);
}