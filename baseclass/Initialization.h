//
// Created by 29937 on 2024-04-29.
//

#ifndef PVSZ_INITIALIZATION_H
#define PVSZ_INITIALIZATION_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

class Initialization {
public:
    Initialization();
    ~Initialization() = default;

protected:
    sf::VideoMode getSizeofScreen();
    void setWindowSize(unsigned int width, unsigned int height);
    void loadImgTexture(const std::string& path);
    void loadMusic(const std::string& path);
    void loadIcon(const std::string& path);

    void setBackground(unsigned int screenWidth, unsigned int screenHeight, bool IsStretch = true);

    std::unique_ptr<sf::Texture> backgroundTexture;
    std::unique_ptr<sf::Music> music;
    sf::Sprite background;

    unsigned int windowWidth;
    unsigned int windowHeight;
};


#endif //PVSZ_INITIALIZATION_H
