#ifndef PVSZ_INITIALIZATION_H
#define PVSZ_INITIALIZATION_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <Windows.h>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

class Initialization {
public:
    Initialization();
    virtual ~Initialization() = default;

protected:
    void getSizeofScreen(sf::RenderWindow& window);
    void setWindowSize(unsigned int width, unsigned int height);
    void loadImgTexture(const std::string& path);
    void loadIcon(const std::string& path);
    void setTop(HWND hwnd);
    void setBackground(unsigned int screenWidth, unsigned int screenHeight, bool isStretch = true);
    bool showExitConfirmation(sf::RenderWindow& window);
    bool checkUserInput(sf::RenderWindow& window, const sf::Event& event);

    std::unique_ptr<sf::Texture> backgroundTexture;
    sf::Sprite background;
    sf::Vector2u windowSize;
    unsigned int windowWidth;
    unsigned int windowHeight;
};

#endif // PVSZ_INITIALIZATION_H
