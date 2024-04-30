
#include "../includes/Loading.h"


int main() {
    printf("Hello, World!\n");

    std::string Bg1_path = "../assets/BG/gamingBackground/FirstEnter/titlescreen.jpg";
    std::string Bg2_path = "../assets/BG/gamingBackground/FirstEnter/Logo.jpg";
    std::string Music_path = "../assets/Sound/Begining.mp3";
    std::string Icon_path = "../assets/others/Menu/191.png";

    Loading loading(Bg1_path, Bg2_path, Music_path, Icon_path);
    loading.gameInit();

    return 0;
}
