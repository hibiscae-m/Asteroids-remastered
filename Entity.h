//
// Created by Marius on 28/12/2022.
//

#ifndef ASTEROIDS_ENTITY_H
#define ASTEROIDS_ENTITY_H

#include <SFML/Graphics.hpp>
#include <string_view>

enum class Type {
    Flight,
    Asteroid,
    Missile,
    Other
};

class Entity {
public:
    explicit Entity(std::string_view texture_location);
    void draw(sf::RenderWindow& window) const;
    virtual void move(float delta_time);
    inline void setPosition(float x, float y) { sprite.setPosition(x, y); };
    inline sf::Vector2f getPosition() const { return sprite.getPosition(); }
    void checkCollision(const Entity& other);
    inline Type getType() const { return type; };
    inline bool isDestructed() const { return destructed; };
protected:
    virtual void reactCollision(const Entity& other);
    sf::Sprite sprite;
    sf::Texture texture;
    sf::CircleShape hitbox;
    float speed{};
    float angle{};
    Type type = Type::Other;
    bool destructed{false};
private:
    float getDistance(sf::Vector2f first, sf::Vector2f second) const;
};


#endif //ASTEROIDS_ENTITY_H
