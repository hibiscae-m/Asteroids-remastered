//
// Created by Marius on 09/02/2023.
//

#ifndef ASTEROIDS_BONUS_H
#define ASTEROIDS_BONUS_H

#include "Entity.h"
#include "GameManager.h"
#include <SFML/Graphics.hpp>
#include <string_view>

class Bonus : public Entity {
public:
    Bonus() = delete;
    Bonus(GameManager& game_manager, sf::Vector2f position, std::string_view texture_location);
    void move(float delta_time) override;
private:
    void reactCollision(const Entity& other) override;
    GameManager& game_manager;
    sf::Clock clock;
    sf::Time life_time = sf::seconds(5);
    sf::Time time_after_spawn = sf::Time::Zero;
};


#endif //ASTEROIDS_BONUS_H
