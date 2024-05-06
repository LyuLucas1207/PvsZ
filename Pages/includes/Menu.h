//
// Created by 29937 on 2024-04-29.
//

#ifndef PVSZ_MENU_H
#define PVSZ_MENU_H

#include "../UniversalPageFeatures/Initialization.h"
#include "../Managers/PictureManager.h"

class Menu : public Initialization {
public:
    Menu(PictureManager& pictureManager);
    ~Menu() = default;
    void menuInit(sf::RenderWindow& window);

private:
    PictureManager& pictureManager;
};


#endif //PVSZ_MENU_H
