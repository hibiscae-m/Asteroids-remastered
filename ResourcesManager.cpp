//
// Created by Marius on 09/02/2023.
//

#include "ResourcesManager.h"

std::unordered_map<std::string_view, sf::Texture> ResourcesManager::resources{};

sf::Texture const &ResourcesManager::getResource(const std::string_view &texture_location) {
    auto result = resources.find(texture_location);
    if (result == std::end(resources)) {
        if (!resources[texture_location].loadFromFile(texture_location.data())) {
            // Handle loading error
        }
        return resources[texture_location];
    }
    return result->second;
}
