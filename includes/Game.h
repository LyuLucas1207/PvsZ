#ifndef PVSZ_GAME_H
#define PVSZ_GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

class Game {
public:
    Game();
    Game(unsigned int width, unsigned int height);
    ~Game() = default;
    void gameInit();

private:
    sf::VideoMode getSizeofScreen();
    void loadImgTexture(const std::string& path);
    void setSprite(sf::Vector2u bg_img, unsigned int screenWidth, unsigned int screenHeight);
    void loadIcon(const std::string& path);
    void loadMusic(const std::string& path);

    std::unique_ptr<sf::Texture> backgroundTexture;
    std::unique_ptr<sf::Music> music;
    sf::Sprite sprite;
    unsigned int windowWidth;
    unsigned int windowHeight;
};

#endif // PVSZ_GAME_H
