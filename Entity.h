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
    Heart,
    ShootSpeed,
    Shield,
    MultipleShots,
    Other
};

class Entity {
public:
    Entity() = default;
    explicit Entity(std::string_view texture_location);
    virtual void draw(sf::RenderWindow& window) const;
    virtual void move(float delta_time);
    inline void setPosition(float x, float y) { sprite.setPosition(x, y); };
    inline sf::Vector2f getPosition() const { return sprite.getPosition(); }
    void checkCollision(const Entity& other);
    inline Type getType() const { return type; };
    inline int getScoreValue() const { return score_value; };
    inline bool isDestructed() const { return destructed; };
    virtual inline void callDestruction() { destructed = true; };
protected:
    virtual void reactCollision(const Entity& other);
    bool isVisible = true;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::CircleShape hitbox;
    float speed{};
    float angle{};
    Type type = Type::Other;
    bool destructed{false};
    int score_value = 0;
private:
    float getDistance(sf::Vector2f first, sf::Vector2f second) const;
};


#endif //ASTEROIDS_ENTITY_H
