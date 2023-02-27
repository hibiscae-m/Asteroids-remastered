//
// Created by Marius on 12/01/2023.
//

#include "Explosion.h"
#include "ResourcesManager.h"

Explosion::Explosion(sf::Vector2f position) : Entity("resources/explosion.png") {
    sprite.setPosition(position);
    sprite.setScale(0, 0);
    sound.setBuffer(ResourcesManager<sf::SoundBuffer>::getResource("resources/explosion.wav"));
    sound.setVolume(0.5);
    sound.play();
}

void Explosion::update() {
    lifetime += loop.restart();
    sprite.setScale(lifetime / time_before_dies, lifetime / time_before_dies);
    if (lifetime >= time_before_dies) {
        sprite.setScale(0, 0);
        if (sound.getStatus() == sf::SoundSource::Stopped)
            destructed = true;
    }
}

void Explosion::move(float delta_time) {
    update();
    Entity::move(delta_time);
}