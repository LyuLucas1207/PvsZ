//
// Created by 29937 on 2024-05-05.
//

#include "MusicManager.h"

void MusicManager::loadMusic(const std::string& name, const std::string& path) {
    auto& music = musics[name] = std::make_unique<sf::Music>();
    if (!music->openFromFile(path)) {
        std::cerr << "Error: Cannot load music " << path << "\n";
        exit(1);
    }
}

void MusicManager::playMusic(const std::string& name) {
    if (currentMusic) {
        currentMusic->stop();
    }
    currentMusic = musics[name].get();
    currentMusic->play();
}
