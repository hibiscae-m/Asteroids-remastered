//
// Created by Marius on 09/02/2023.
//

#ifndef ASTEROIDS_RESOURCESMANAGER_H
#define ASTEROIDS_RESOURCESMANAGER_H

#include <SFML/Graphics.hpp>
#include <string_view>
#include <unordered_map>

class ResourcesManager {
public:
    ResourcesManager() = delete;
    static sf::Texture const& getResource(std::string_view const& texture_location);
private:
    static std::unordered_map<std::string_view, sf::Texture> resources;
};


#endif //ASTEROIDS_RESOURCESMANAGER_H
