//
// Created by 29937 on 2024-04-29.
//

#include "GameLogic.h"

void GameLogic::pageSwitch() {
    int PageNumber = 0;
    while(true){
        if(PageNumber == 0){//This is loading Page
            std::string Bg1_path = "../assets/BG/gamingBackground/FirstEnter/titlescreen.jpg";
            std::string Bg2_path = "../assets/BG/gamingBackground/FirstEnter/Logo.jpg";
            std::string Music_path = "../assets/Sound/Begining.mp3";
            std::string Icon_path = "../assets/others/Menu/191.png";

            Loading loading(Bg1_path, Bg2_path, Music_path, Icon_path);
            loading.gameInit();
            PageNumber = 1;
        }else{
            std::cout << "Next Page" << std::endl;
            exit(0);
        }
    }
}