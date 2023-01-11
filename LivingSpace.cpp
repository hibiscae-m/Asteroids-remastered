//
// Created by Marius on 10/01/2023.
//

#include "LivingSpace.h"
#include <random>

LivingSpace::LivingSpace(sf::RenderWindow& window, float out_of_screen_limit)
    : window(window), out_of_screen_limit(out_of_screen_limit)
{
    coordinates = {{-out_of_screen_limit,
                    -out_of_screen_limit},

                   {(out_of_screen_limit * 2 + static_cast<float>(window.getSize().x) / 2),
                    -out_of_screen_limit},

                   {(out_of_screen_limit + static_cast<float>(window.getSize().x)),
                    -out_of_screen_limit},

                   {-out_of_screen_limit,
                    (out_of_screen_limit * 2 + static_cast<float>(window.getSize().y) / 2)},

                   {(out_of_screen_limit + static_cast<float>(window.getSize().x)),
                    (out_of_screen_limit * 2 + static_cast<float>(window.getSize().y) / 2)},

                   {-out_of_screen_limit,
                    (out_of_screen_limit + static_cast<float>(window.getSize().y))},

                   {(out_of_screen_limit * 2 + static_cast<float>(window.getSize().x) / 2),
                    (out_of_screen_limit + static_cast<float>(window.getSize().y))},

                   {(out_of_screen_limit + static_cast<float>(window.getSize().x)),
                    (out_of_screen_limit + static_cast<float>(window.getSize().y))}
    };
}

sf::Vector2f LivingSpace::getRandomOOBPosition(int map_corner, std::random_device& generator) const {
    auto position_distribution = std::uniform_real_distribution<float>(-out_of_screen_limit, out_of_screen_limit);
    switch (map_corner) {
        case MapCorner::UpLeft:
            return coordinates.up_left;
        case MapCorner::UpMiddle:
            return {coordinates.up_middle.x + position_distribution(generator), coordinates.up_middle.y};
        case MapCorner::UpRight:
            return coordinates.up_right;
        case MapCorner::MiddleLeft:
            return {coordinates.middle_left.x, coordinates.middle_left.y + position_distribution(generator)};
        case MapCorner::MiddleRight:
            return {coordinates.middle_right.x, coordinates.middle_right.y + position_distribution(generator)};
        case MapCorner::BottomLeft:
            return coordinates.bottom_left;
        case MapCorner::BottomMiddle:
            return {coordinates.bottom_middle.x + position_distribution(generator), coordinates.bottom_middle.y};
        case MapCorner::BottomRight:
            return coordinates.bottom_right;
        default:
            throw std::invalid_argument("map_corner (OOB)");
    }
}

float LivingSpace::getRandomAngle(int map_corner, std::random_device& generator) const {
    auto angle_distribution = std::uniform_real_distribution<float>(-20, 20);
    switch (map_corner) {
        case MapCorner::UpLeft:
            return 45 + angle_distribution(generator);
        case MapCorner::UpMiddle:
            return 90 + angle_distribution(generator);
        case MapCorner::UpRight:
            return 125 + angle_distribution(generator);
        case MapCorner::MiddleLeft:
            return 360 + angle_distribution(generator);
        case MapCorner::MiddleRight:
            return 180 + angle_distribution(generator);
        case MapCorner::BottomLeft:
            return 315 + angle_distribution(generator);
        case MapCorner::BottomMiddle:
            return 270 + angle_distribution(generator);
        case MapCorner::BottomRight:
            return 225 + angle_distribution(generator);
        default:
            throw std::invalid_argument("map_corner (randomAngle)");
    }
}

bool LivingSpace::operator==(const Entity& entity) const {
    return ( entity.getPosition().x >= static_cast<float>(-out_of_screen_limit) &&
             entity.getPosition().x <= static_cast<float>(window.getSize().x) + out_of_screen_limit &&
             entity.getPosition().y >= static_cast<float>(-out_of_screen_limit) &&
             entity.getPosition().y <= static_cast<float>(window.getSize().y) + out_of_screen_limit );
}

bool LivingSpace::operator!=(const Entity& entity) const {
    return !(*this == entity);
}
