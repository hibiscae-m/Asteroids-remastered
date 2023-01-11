//
// Created by Marius on 10/01/2023.
//

#include "LivingSpace.h"

LivingSpace::LivingSpace(sf::RenderWindow& window, short out_of_screen_limit)
    : window(window), out_of_screen_limit(out_of_screen_limit)
{}

bool LivingSpace::operator==(const Entity& entity) const {
    return ( entity.getPosition().x > static_cast<float>(-out_of_screen_limit) &&
             entity.getPosition().x < static_cast<float>(window.getSize().x + out_of_screen_limit) &&
             entity.getPosition().y > static_cast<float>(-out_of_screen_limit) &&
             entity.getPosition().y < static_cast<float>(window.getSize().y + out_of_screen_limit) );
}

bool LivingSpace::operator!=(const Entity& entity) const {
    return !(*this == entity);
}
