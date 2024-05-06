//
// Created by 29937 on 2024-05-05.
//

#ifndef PVSZ_MUSICMANAGER_H
#define PVSZ_MUSICMANAGER_H

#include <SFML/Audio.hpp>
#include <map>
#include <memory>
#include <iostream>

class MusicManager {

public:
    MusicManager() = default;
    ~MusicManager() = default;
    void loadMusic(const std::string& name, const std::string& path);
    void playMusic(const std::string& name);

private:
    std::map<std::string, std::unique_ptr<sf::Music>> musics;
    sf::Music* currentMusic = nullptr;
};


#endif //PVSZ_MUSICMANAGER_H
