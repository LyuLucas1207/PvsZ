//
// Created by 29937 on 2024-04-29.
//

#ifndef PVSZ_MENU_H
#define PVSZ_MENU_H

#include "../baseclass/Initialization.h"

class Menu : public Initialization {
public:
    Menu(const std::string& Bg1_path,const std::string& Icon_path);
    ~Menu() = default;
    void menuInit(sf::RenderWindow& window);

private:

};


#endif //PVSZ_MENU_H
