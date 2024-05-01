cmake_minimum_required(VERSION 3.28)
project(PvsZ)

set(CMAKE_CXX_STANDARD 20)

# 可执行文件和源文件
add_executable(PvsZ src/main.cpp
        BasePage/Loading.cpp
        plants/Plant.cpp
        zombies/Zombie.cpp
        BattlesScenes/Scenes.cpp
        BasePage/Menu.cpp
        BasePage/BaseClass/Initialization.cpp
        src/logic/GameLogic.cpp
)

target_include_directories(PvsZ PRIVATE
        BasePage/includes
        plants
        zombies
        BattlesScenes
        BasePage/BaseClass
        src/logic
)

include_directories(BasePage/includes)

# 包含目录
include_directories(D:/lib/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/include)

# 库目录
link_directories(D:/lib/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/lib)

# 链接 SFML 库
set(SFML_DIR "D:/lib/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

# ...

target_link_libraries(PvsZ
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)

