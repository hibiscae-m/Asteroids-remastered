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
    GameManager() = delete;
    GameManager(int width, int height);
    void addToBuffer(std::unique_ptr<Entity> entity);
    void update();
    void draw(sf::RenderWindow& window) const;
    void move(float delta_time) const;
    void checkCollision() const;
private:
    void add();
    void reposition() const;
    std::vector<std::unique_ptr<Entity>> entities{};
    std::vector<std::unique_ptr<Entity>> buffer{};
    int space_width{};
    int space_length{};
};


#endif //ASTEROIDS_GAMEMANAGER_H
