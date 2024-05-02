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

//UserInput
bool Initialization::showExitConfirmation(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("../assets/font/Jersey_15/Jersey15-Regular.ttf")) {
        std::cerr << "Error: Cannot load font file\n";
        return false;
    }

    sf::RectangleShape exitBackground(sf::Vector2f(400.f, 150.f)); // 背景大小
    exitBackground.setFillColor(sf::Color(0, 0, 0, 150)); // 半透明背景
    exitBackground.setPosition(window.getSize().x / 2 - 200, window.getSize().y / 2 - 75); // 居中

    sf::Text text("Really, you want to leave?", font, 24);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x / 2 - text.getLocalBounds().width / 2, window.getSize().y / 2 - 50);

    sf::Text option1("Exit!", font, 24);
    option1.setFillColor(sf::Color::White);
    option1.setPosition(window.getSize().x / 2 - exitBackground.getSize().x / 4 - option1.getLocalBounds().width / 2, window.getSize().y / 2 + 20);

    sf::Text option2("Back!", font, 24);
    option2.setFillColor(sf::Color::White);
    option2.setPosition(window.getSize().x / 2 + exitBackground.getSize().x / 4 - option2.getLocalBounds().width / 2, window.getSize().y / 2 + 20);


    while (true) {
        //window.clear(sf::Color::White);
        window.draw(exitBackground);
        window.draw(text);
        window.draw(option1);
        window.draw(option2);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false; // 确保在窗口关闭时退出
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (option1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    return true; // 用户选择“是”
                } else if (option2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    return false; // 用户选择“否”
                }
            }
        }
    }
}

bool Initialization::checkUserInput(sf::RenderWindow& window, const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) { // 如果按下的键不是 ESC 键，则退出循环
        if (event.key.code != sf::Keyboard::Escape) {
            return true;
        }else if(event.key.code == sf::Keyboard::Escape){
            if (showExitConfirmation(window)) {
                std::cout << "Exiting the game" << std::endl;
                exit(0);
            }
        }
    }// 检测鼠标事件
    if (event.type == sf::Event::MouseButtonPressed) {
        // 任何鼠标按键的点击都会导致退出循环
        return true;
    }
    return false;
}