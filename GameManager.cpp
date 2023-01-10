//
// Created by Marius on 30/12/2022.
//

#include "GameManager.h"

GameManager::GameManager(float width, float length) : living_space{width, length, 200}
{
}

void GameManager::addToBuffer(std::unique_ptr<Entity> entity) {
    buffer.push_back(std::move(entity));
}

void GameManager::add() {
    for (auto& entity: buffer)
        entities.push_back(std::move(entity));
    buffer.clear();
}

void GameManager::draw(sf::RenderWindow& window) const {
    // Going in reverse order to draw Flight above the rest
    for (auto i = entities.size(); i > 0u; i--)
        entities[i-1]->draw(window);
}

void GameManager::move(const float delta_time) const {
    for (const auto& entity: entities)
        entity->move(delta_time);
    checkCollision();
    checkPosition();
    //reposition();
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