//
// Created by Marius on 30/12/2022.
//

#ifndef ASTEROIDS_GAMEMANAGER_H
#define ASTEROIDS_GAMEMANAGER_H

#include "Entity.h"
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class GameManager {
public:
    explicit GameManager() = default;
    void add(std::unique_ptr<Entity> entity);
    void draw(sf::RenderWindow& window);
    void move(float delta_time);
    void checkCollision();
private:
    std::vector<std::unique_ptr<Entity>> entities{};
};


#endif //ASTEROIDS_GAMEMANAGER_H
