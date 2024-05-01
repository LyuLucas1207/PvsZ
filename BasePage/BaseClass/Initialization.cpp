//
// Created by 29937 on 2024-04-29.
//

#include "Initialization.h"
#include <iostream>

Initialization::Initialization() : windowWidth(DEFAULT_WIDTH), windowHeight(DEFAULT_HEIGHT) {}

sf::VideoMode Initialization::getSizeofScreen() {
    windowWidth = sf::VideoMode::getDesktopMode().width;
    windowHeight = sf::VideoMode::getDesktopMode().height;
    return sf::VideoMode::getDesktopMode();
}

void Initialization::setWindowSize(unsigned int width, unsigned int height) {
    windowWidth = width;
    windowHeight = height;
}

void Initialization::loadImgTexture(const std::string& path) {
    backgroundTexture = std::make_unique<sf::Texture>();
    if (!backgroundTexture->loadFromFile(path)) {
        std::cerr << "Error: Cannot load image texture\n";
        exit(1);
    }
}

void Initialization::loadMusic(const std::string &path) {
    music = std::make_unique<sf::Music>();
    if (!music->openFromFile(path)) {
        std::cerr << "Error: Cannot load music\n";
        exit(1);
    }
    music->setLoop(true);
    music->play();

}

void Initialization::loadIcon(const std::string &path) {
    sf::Image icon;
    if (!icon.loadFromFile(path)) {
        std::cerr << "Error: Cannot load icon\n";
        exit(1);
    }
    sf::Vector2u iconSize = icon.getSize();
    sf::RenderWindow window(sf::VideoMode(iconSize.x, iconSize.y), "Icon");
    window.setIcon(iconSize.x, iconSize.y, icon.getPixelsPtr());
}

//sf::Vector2u bg_img: size of the background image, you can get it by calling backgroundTexture->getSize()
void Initialization::setBackground(unsigned int screenWidth, unsigned int screenHeight,bool IsStretch) {
    background.setTexture(*backgroundTexture);
    sf::Vector2u bg_img = backgroundTexture->getSize();
    if (IsStretch) {
        float scaleX = static_cast<float>(screenWidth) / bg_img.x;
        float scaleY = static_cast<float>(screenHeight) / bg_img.y;
        float scale = std::min(scaleX, scaleY);
        background.setScale(scale, scale);
    }
    else {
        background.setScale(1, 1);
    }

    float spriteWidth = bg_img.x * background.getScale().x;
    float spriteHeight = bg_img.y * background.getScale().y;
    float posX = (screenWidth - spriteWidth) / 2;
    float posY = (screenHeight - spriteHeight) / 2;
    background.setPosition(posX, posY);
}

void Initialization::setTop(HWND hwnd) {
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}