#include "../includes/Game.h"
#include <iostream>

Game::Game() : windowWidth(DEFAULT_WIDTH), windowHeight(DEFAULT_HEIGHT) {}
Game::Game(unsigned int width, unsigned int height) : windowWidth(width), windowHeight(height) {}

sf::VideoMode Game::getSizeofScreen() {
    return sf::VideoMode::getDesktopMode();
}

void Game::loadImgTexture(const std::string& path) {
    backgroundTexture = std::make_unique<sf::Texture>();
    if (!backgroundTexture->loadFromFile(path)) {
        std::cerr << "Error: Cannot load image texture\n";
        exit(1);
    }
}

void Game::setSprite(sf::Vector2u bg_img, unsigned int screenWidth, unsigned int screenHeight) {
    sprite.setTexture(*backgroundTexture);
    float scaleX = static_cast<float>(screenWidth) / bg_img.x;
    float scaleY = static_cast<float>(screenHeight) / bg_img.y;
    float scale = std::max(scaleX, scaleY);
    sprite.setScale(scale, scale);

    float spriteWidth = bg_img.x * scale;
    float spriteHeight = bg_img.y * scale;
    float posX = (screenWidth - spriteWidth) / 2;
    float posY = (screenHeight - spriteHeight) / 2;
    sprite.setPosition(posX, posY);
}

void Game::loadMusic(const std::string& path) {
    music = std::make_unique<sf::Music>();
    if (!music->openFromFile(path)) {
        std::cerr << "Error: Cannot load music\n";
        exit(1);
    }
    music->setLoop(true);
    music->play();
}

void Game::gameInit() {
    loadImgTexture("../assets/BG/gamingBackground/FirstEnter/titlescreen.jpg");
    loadMusic("../assets/Sound/Begining.mp3");

    // Get the size of the computer screen
    sf::VideoMode desktop = getSizeofScreen();
    windowWidth = desktop.width;
    windowHeight = desktop.height;

    // Create a full-screen window
    sf::RenderWindow window(desktop, "Plants vs Zombies", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    // Set the background sprite
    setSprite(backgroundTexture->getSize(), windowWidth, windowHeight);

    // Main game loop
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw game objects
        window.draw(sprite);

        // Display the window
        window.display();
    }
}
