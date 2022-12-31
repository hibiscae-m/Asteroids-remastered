//
// Created by Marius on 30/12/2022.
//

#include "GameManager.h"

GameManager::GameManager(int width, int length) : space_width(width), space_length(length)
{}

void GameManager::add(std::unique_ptr<Entity> entity) {
    entities.push_back(std::move(entity));
}

void GameManager::draw(sf::RenderWindow& window) const {
    for (const auto& entity: entities)
        entity->draw(window);
}

void GameManager::move(const float delta_time) const {
    for (const auto& entity: entities)
        entity->move(delta_time);
    reposition();
}

void GameManager::reposition() const {
    for (const auto& entity: entities) {
        if (entity->getPosition().x > static_cast<float>(space_width))
            entity->setPosition(0, entity->getPosition().y);
        if (entity->getPosition().x < 0 )
            entity->setPosition(static_cast<float>(space_width), entity->getPosition().y);

        if (entity->getPosition().y > static_cast<float>(space_length))
            entity->setPosition(entity->getPosition().x, 0);
        if (entity->getPosition().y < 0)
            entity->setPosition(entity->getPosition().x, static_cast<float>(space_length));
    }
}

void GameManager::checkCollision() const {
    for (const auto& first_entity: entities)
        for (const auto& second_entity: entities)
            if (first_entity != second_entity)
                first_entity->checkCollision(*second_entity);
}
