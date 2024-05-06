//
// Created by 29937 on 2024-05-05.
//

#ifndef PVSZ_PICTUREMANAGER_H
#define PVSZ_PICTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <string>

class PictureManager {
public:
    PictureManager() = default;
    ~PictureManager() = default;
    void loadTexture(const std::string& name, const std::string& filename);
    std::string getTexture(const std::string& name);
    int getTextureNum() const;

private:
    std::map<std::string, std::string> textures;
    //Remember, First picture is background, second is icon.
};

#endif //PVSZ_PICTUREMANAGER_H
