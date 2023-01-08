//
// Created by Marius on 28/12/2022.
//

#include "Entity.h"
#include "Vector.h"
#include <iostream>
#include <cmath>

Entity::Entity(const std::string_view texture_location) {
    if (!texture.loadFromFile(texture_location.data()))
        throw std::invalid_argument(texture_location.data());
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    hitbox.setRadius(sprite.getGlobalBounds().width/1.85);
    hitbox.setOrigin(hitbox.getGlobalBounds().width/2, hitbox.getGlobalBounds().height/2);
    hitbox.setPosition(sprite.getPosition());
    hitbox.setFillColor(sf::Color(255,0,0,100));
}

void Entity::move(const float delta_time) {
    sf::Vector2f movement = Vector::acquire_movement(speed * delta_time, angle);
    sprite.move(movement);
    hitbox.setPosition(sprite.getPosition());
}

void Entity::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
    window.draw(hitbox);
}

float Entity::getDistance(sf::Vector2f first, sf::Vector2f second) const {
    float distance_x = first.x - second.x;
    float distance_y = first.y - second.y;
    float distance = std::sqrt((distance_x * distance_x) + (distance_y * distance_y));
    return distance;
}

void Entity::checkCollision(const Entity& other) {
    if (getDistance(hitbox.getPosition(), other.hitbox.getPosition()) < (hitbox.getRadius() + other.hitbox.getRadius()))
        reactCollision(other);
}

void Entity::reactCollision(const Entity& other) {

}