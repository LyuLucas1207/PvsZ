#include "Loading.h"


//loadImgTexture("../assets/BG/gamingBackground/FirstEnter/titlescreen.jpg");
//loadMusic("../assets/Sound/Begining.mp3");
//loadIcon("../assets/others/Menu/191.png");

Loading::Loading(const std::string& Bg1_path, const std::string& Bg2_path, const std::string& Music_path, const std::string& Icon_path) {
    loadImgTexture(Bg1_path, Bg2_path);
    loadMusic(Music_path);
    loadIcon(Icon_path);
}

void Loading::loadImgTexture(const std::string& path1, const std::string& path2) {
    backgroundTexture = std::make_unique<sf::Texture>();
    if (!backgroundTexture->loadFromFile(path1)) {
        std::cerr << "Error: Cannot load image texture\n";
        exit(1);
    }
    transitionTexture = std::make_unique<sf::Texture>();
    if (!transitionTexture->loadFromFile(path2)) {
        std::cerr << "Error: Cannot load image texture\n";
        exit(1);
    }
}

void Loading::setBackground(unsigned int screenWidth, unsigned int screenHeight) {
    background.setTexture(*backgroundTexture);
    transition.setTexture(*transitionTexture);
    sf::Vector2u bg_img = backgroundTexture->getSize();
    sf::Vector2u tr_img = transitionTexture->getSize();

    float scaleX_bg = static_cast<float>(screenWidth) / bg_img.x;
    float scaleY_bg = static_cast<float>(screenHeight) / bg_img.y;
    float scale_bg = std::min(scaleX_bg, scaleY_bg);

    float  scaleX_tr = static_cast<float>(screenWidth) / tr_img.x;
    float  scaleY_tr = static_cast<float>(screenHeight) / tr_img.y;
    float scale_tr = std::min(scaleX_tr, scaleY_tr);

    background.setScale(scale_bg, scale_bg);
    transition.setScale(scale_tr, scale_tr);

    float spriteWidth = bg_img.x * background.getScale().x;
    float spriteHeight = bg_img.y * background.getScale().y;
    float posX = (screenWidth - spriteWidth) / 2;
    float posY = (screenHeight - spriteHeight) / 2;
    background.setPosition(posX, posY);

    spriteWidth = tr_img.x * transition.getScale().x;
    spriteHeight = tr_img.y * transition.getScale().y;
    posX = (screenWidth - spriteWidth) / 2;
    posY = (screenHeight - spriteHeight) / 2;
    transition.setPosition(posX, posY);
}

bool Loading::checkUserInput(sf::RenderWindow& window, const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) { // 如果按下的键不是 ESC 键，则退出循环
        if (event.key.code != sf::Keyboard::Escape) {
            return true;
        }else if(event.key.code == sf::Keyboard::Escape){
            if (showExitConfirmation(window)) {
                std::cout << "Exiting the game" << std::endl;
                exit(0);
            }
        }
    }// 检测鼠标事件
    if (event.type == sf::Event::MouseButtonPressed) {
        // 任何鼠标按键的点击都会导致退出循环
        return true;
    }
    return false;
}

bool Loading::showExitConfirmation(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("../assets/font/Jersey_15/Jersey15-Regular.ttf")) {
        std::cerr << "Error: Cannot load font file\n";
        return false;
    }

    sf::RectangleShape background(sf::Vector2f(400.f, 150.f)); // 背景大小
    background.setFillColor(sf::Color(0, 0, 0, 150)); // 半透明背景
    background.setPosition(window.getSize().x / 2 - 200, window.getSize().y / 2 - 75); // 居中

    sf::Text text("Really, you want to leave?", font, 24);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x / 2 - text.getLocalBounds().width / 2, window.getSize().y / 2 - 50);

    sf::Text option1("Exit!", font, 24);
    option1.setFillColor(sf::Color::White);
    option1.setPosition(window.getSize().x / 2 - background.getSize().x / 4 - option1.getLocalBounds().width / 2, window.getSize().y / 2 + 20);

    sf::Text option2("Back!", font, 24);
    option2.setFillColor(sf::Color::White);
    option2.setPosition(window.getSize().x / 2 + background.getSize().x / 4 - option2.getLocalBounds().width / 2, window.getSize().y / 2 + 20);


    while (true) {
        //window.clear(sf::Color::White);
        window.draw(background);
        window.draw(text);
        window.draw(option1);
        window.draw(option2);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false; // 确保在窗口关闭时退出
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (option1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    return true; // 用户选择“是”
                } else if (option2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    return false; // 用户选择“否”
                }
            }
        }
    }
}

void Loading::gameInit() {
    sf::VideoMode desktop = getSizeofScreen();
    sf::RenderWindow window(desktop, "Plants vs Zombies", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    setBackground(windowWidth, windowHeight);
    transition.setColor(sf::Color(255, 255, 255, 255)); // 将过渡图片的透明度设置为完全不透明

    bool transitionCompleted = false;
    setTop(window.getSystemHandle());

    while (window.isOpen()) {
        window.clear(); // 清空窗口
        if (!transitionCompleted) {
            int alpha = transition.getColor().a;
            if (alpha > 0) {
                alpha -= 5;
                transition.setColor(sf::Color(255, 255, 255, alpha));
                window.draw(transition); // 绘制过渡图片
            } else {
                transitionCompleted = true;
            }
        } else {
            window.draw(background); // 绘制背景
        }
        window.display(); // 显示窗口

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || checkUserInput(window, event)) {
                window.close();
            }
        }
    }
}





