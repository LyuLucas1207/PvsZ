//
// Created by 29937 on 2024-04-29.
//

#ifndef PVSZ_GAMELOGIC_H
#define PVSZ_GAMELOGIC_H

#include "../../Pages/Managers/MusicManager.h"
#include "Loading.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>

class GameLogic {
public:
    explicit GameLogic(sf::RenderWindow& window, MusicManager& musicManager);
    ~GameLogic() = default;
    void pageSwitch();

private:
    sf::RenderWindow& window;
    MusicManager& musicManager;
};

#endif // PVSZ_GAMELOGIC_H

