//
// Created by 29937 on 2024-04-29.
//

#include "GameLogic.h"

GameLogic::GameLogic(sf::RenderWindow& window, MusicManager& musicManager)
        : window(window), musicManager(musicManager) {
}

void GameLogic::pageSwitch() {
    int PageNumber = 0;

    Loading loading("../assets/BG/gamingBackground/FirstEnter/titlescreen.jpg",
                    "../assets/BG/gamingBackground/FirstEnter/Logo.jpg",
                    "../assets/others/Menu/191.png");

    Menu menu("../assets/BG/gamingBackground/Menu/MainMenu.png",
              "../assets/others/Menu/191.png");

    while(window.isOpen()){
        switch (PageNumber) {
            case 0: // This is loading Page
                musicManager.playMusic("Beginning");
                loading.gameInit(window);
                PageNumber = 1;
                break;
            case 1: // This is Menu Page
                musicManager.playMusic("Menu");
                menu.menuInit(window);
                PageNumber = 3;
                break;
            case 3: // This is Game Page
                // Assuming there's a similar setup for game page music
                musicManager.playMusic("GamePageMusic");
                loading.gameInit(window); // Assuming you might have a separate class for actual game logic
                PageNumber = 4;
                break;
            default:
                std::cout << "Next Page" << std::endl;
                exit(0);
        }
    }
}
