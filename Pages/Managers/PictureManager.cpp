#include "PictureManager.h"
#include <stdexcept>

void PictureManager::loadTexture(const std::string& name, const std::string& filename) {
    textures[name] = filename;
}

std::string PictureManager::getTexture(const std::string& name) {
    auto it = textures.find(name);
    if (it != textures.end()) {
        return it->second;
    } else {
        throw std::runtime_error("Texture not found: " + name);
    }
}

int PictureManager::getTextureNum() const {
    return textures.size();
}
