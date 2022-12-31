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
    void draw(sf::RenderWindow& window) const;
    virtual void move(float delta_time);
    inline void setPosition(float x, float y) { sprite.setPosition(x, y); };
    inline sf::Vector2f getPosition() const { return sprite.getPosition(); }
    void checkCollision(const Entity& other) const;
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed{};
};


#endif //ASTEROIDS_ENTITY_H
