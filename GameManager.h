//
// Created by Marius on 30/12/2022.
//

#ifndef ASTEROIDS_GAMEMANAGER_H
#define ASTEROIDS_GAMEMANAGER_H

#include "Entity.h"
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "LivingSpace.h"

class GameManager {
public:
    GameManager() = delete;
    explicit GameManager(sf::RenderWindow& window);
    void addToBuffer(std::unique_ptr<Entity> entity);
    void update();
    void draw() const;
    void move(float delta_time) const;
private:
    void add();
    void clear();
    void checkCollision() const;
    void checkPosition() const;
    void reposition() const;
    std::vector<std::unique_ptr<Entity>> entities{};
    std::vector<std::unique_ptr<Entity>> buffer{};
    LivingSpace living_space;
    sf::RenderWindow& window;
    int space_width{};
    int space_length{};
};


#endif //ASTEROIDS_GAMEMANAGER_H
