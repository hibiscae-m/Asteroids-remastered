//
// Created by Marius on 27/12/2022.
//

#include "Flight.h"
#include "Missile.h"

Flight::Flight(GameManager& game_manager, float position_x, float position_y) : Entity("resources/flight.png"), game_manager(game_manager) {
    sprite.setPosition(position_x, position_y);
    type = Type::Flight;
    shield.setRadius(sprite.getGlobalBounds().width * 0.9f);
    shield.setOrigin(shield.getGlobalBounds().width / 2, shield.getGlobalBounds().height / 2);
    shield.setFillColor(sf::Color(135, 206, 250, 125));
}

void Flight::handlePlayerInputs(const float delta_time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        speed += ACCELERATION;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        sprite.rotate(-ANGLE_SPEED * delta_time);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        sprite.rotate(ANGLE_SPEED * delta_time);
}

void Flight::move(const float delta_time) {
    update();
    if (!damaged)
        shoot();
    handlePlayerInputs(delta_time);
    speed -= speed * FRICTION * delta_time;
    angle = sprite.getRotation();
    Entity::move(delta_time);
}

void Flight::shoot() {
    time_since_last_shoot += shoot_clock.restart();
    if (time_since_last_shoot > shoot_cooldown) {
        time_since_last_shoot = sf::Time::Zero;
        game_manager.addToBuffer(std::make_unique<Missile>(sprite.getPosition(), sprite.getRotation()));
        if (multipleshots_bonus) {
            game_manager.addToBuffer(std::make_unique<Missile>(sprite.getPosition(), sprite.getRotation() - 15));
            game_manager.addToBuffer(std::make_unique<Missile>(sprite.getPosition(), sprite.getRotation() + 15));
        }
    }
}

void Flight::reactCollision(const Entity& other) {
    if (other.getType() == Type::Asteroid) {
        if (!damaged) {
            damage_clock.restart();
            blink_clock.restart();
            damaged = true;
            if (!has_shield) {
                health--;
                game_manager.setUIHealth(health);
            }
            else
                has_shield = false;
        }
    }
    else if (other.getType() == Type::Heart) {
        if (health < 3) {
            health++;
            game_manager.setUIHealth(health);
        }
    }
    else if (other.getType() == Type::ShootSpeed) {
        if (!shootspeed_boosted) {
            shootspeed_boosted = true;
            shoot_cooldown = sf::milliseconds(shoot_cooldown.asMilliseconds() / 2);
        }
        shootspeed_bonus_clock.restart();
    }
    else if (other.getType() == Type::Shield)
        has_shield = true;
    else if (other.getType() == Type::MultipleShots) {
        if (!multipleshots_bonus)
            multipleshots_bonus = true;
        multipleshots_bonus_clock.restart();
    }
}

void Flight::checkHealth() {
    if (health <= 0) {
        destructed = true;
        game_manager.addExplosion(sprite.getPosition());
        game_manager.callGameOver();
    }
    else {
        if (damaged) {
            if (damage_clock.getElapsedTime() < damage_invincibility) {
                if (blink_clock.getElapsedTime() > blink_duration) {
                    isVisible = !isVisible;
                    blink_clock.restart();
                }
            }
            else {
                damaged = false;
                isVisible = true;
            }
        }
    }
}

void Flight::update() {
    shield.setPosition(sprite.getPosition());
    checkHealth();
    checkBonus();
}

void Flight::checkBonus() {
    if (shootspeed_boosted) {
        if (shootspeed_bonus_clock.getElapsedTime() >= shootspeed_bonus_duration) {
            shootspeed_boosted = false;
            shoot_cooldown = sf::milliseconds(shoot_cooldown.asMilliseconds() * 2);
        }
    }
    if (multipleshots_bonus)
        if (multipleshots_bonus_clock.getElapsedTime() >= multipleshots_bonus_duration)
            multipleshots_bonus = false;
}

void Flight::draw(sf::RenderWindow &window) const {
    if (has_shield)
        window.draw(shield);
    Entity::draw(window);
}
