//
// Created by Marius on 28/12/2022.
//

#include "Entity.h"
#include "Vector.h"
#include <iostream>

Entity::Entity(const std::string_view texture_location) {
    if (!texture.loadFromFile(texture_location.data()))
        throw std::invalid_argument(texture_location.data());
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
}

void Entity::move(const float delta_time) {
    sf::Vector2f movement = Vector::acquire_movement(speed * delta_time, sprite.getRotation());
    sprite.move(movement);
}

void Entity::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Entity::checkCollision(const Entity& other) {
    if (sprite.getGlobalBounds().intersects(other.sprite.getGlobalBounds()))
        reactCollision(other);
}

void Entity::reactCollision(const Entity& other) {

}