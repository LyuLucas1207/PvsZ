
#include "../logic/GameLogic.h"



int main() {
    std::cout << "GameStart" << std::endl;

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Plants vs Zombies", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    // Instantiate the music manager and load music
    MusicManager musicManager;
    musicManager.loadMusic("Beginning", "../assets/Sound/Beginning.mp3");
    musicManager.loadMusic("Menu", "../assets/Sound/Menu.mp3");
    musicManager.loadMusic("GamePageMusic", "../assets/Sound/Beginning.mp3");

    // Pass the music manager to the game logic
    GameLogic gameLogic(window, musicManager);
    gameLogic.pageSwitch();

    return 0;
}
