//
// Created by Marius on 28/12/2022.
//

#ifndef ASTEROIDS_ENTITY_H
#define ASTEROIDS_ENTITY_H

#include <SFML/Graphics.hpp>
#include <string_view>

class Entity {
public:
    explicit Entity(std::string_view texture_location);
    void draw(sf::RenderWindow& window);
    virtual void move(float deltaTime);
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed{};
private:
    const float FRICTION{3.f};
};


#endif //ASTEROIDS_ENTITY_H
