//
// Created by Marius on 27/12/2022.
//

#include "Flight.h"
#include "Missile.h"

Flight::Flight(GameManager& game_manager, float position_x, float position_y) : Entity("resources/flight.png"), game_manager(game_manager) {
    sprite.setPosition(position_x, position_y);
    type = Type::Flight;
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
    }
}

void Flight::reactCollision(const Entity& other) {
    if (other.getType() == Type::Asteroid) {
        if (!damaged) {
            damage_clock.restart();
            blink_clock.restart();
            damaged = true;
            health--;
            game_manager.setUIHealth(health);
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
}

void Flight::checkHealth() {
    if (health <= 0) {
        destructed = true;
        game_manager.addExplosion(sprite.getPosition());
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
}