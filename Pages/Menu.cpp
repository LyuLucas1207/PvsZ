//
// Created by 29937 on 2024-04-29.
//

#include "Menu.h"

//Menu::Menu(PictureManager& pictureManager) {
//    loadImgTexture(Bg1_path);
//    loadIcon(Icon_path);
//}
Menu::Menu(PictureManager& pictureManager) : pictureManager(pictureManager) {
    loadImgTexture(pictureManager.getTexture("Menu_BackGround"));
    loadIcon(pictureManager.getTexture("Menu_Icon"));

}
void Menu::menuInit(sf::RenderWindow& window){
    getSizeofScreen(window);
    setBackground(windowWidth, windowHeight,false);
    setTop(window.getSystemHandle());

    bool isRunning = true;
    while (window.isOpen()) {
        window.clear(); // 清空窗口
        window.draw(background);
        window.display();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || checkUserInput(window, event)) {
                isRunning = false;
                break;
            }
        }
        if (!isRunning) {
            break;
        }
    }
}