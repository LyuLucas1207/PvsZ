#ifndef PVSZ_LOADING_H
#define PVSZ_LOADING_H

#include <iostream>
#include "../UniversalPageFeatures/Initialization.h"


class Loading: public Initialization {
public:
    Loading(const std::string& Bg1_path, const std::string& Bg2_path,const std::string& Icon_path);
    ~Loading() = default;
    void gameInit(sf::RenderWindow& window);

private:

    void loadImgTexture(const std::string& path1, const std::string& path2);
    void setBackground(unsigned int screenWidth, unsigned int screenHeight);


    std::unique_ptr<sf::Texture> transitionTexture;
    sf::Sprite transition;



};

#endif // PVSZ_LOADING_H
