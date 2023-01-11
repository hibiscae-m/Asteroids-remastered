//
// Created by Marius on 10/01/2023.
//

#include "LivingSpace.h"

LivingSpace::LivingSpace(unsigned int window_width, unsigned int window_length, float out_of_screen_limit)
    : window_width(window_width), window_length(window_length), out_of_screen_limit(out_of_screen_limit)
{}

bool LivingSpace::operator==(const Entity& entity) const {
    return ( entity.getPosition().x > -out_of_screen_limit &&
             entity.getPosition().x < static_cast<float>(window_width) + out_of_screen_limit &&
             entity.getPosition().y > -out_of_screen_limit &&
             entity.getPosition().y < static_cast<float>(window_length) + out_of_screen_limit );
}

bool LivingSpace::operator!=(const Entity& entity) const {
    return !(*this == entity);
}
