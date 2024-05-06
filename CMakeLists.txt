cmake_minimum_required(VERSION 3.28)
project(PvsZ)

set(CMAKE_CXX_STANDARD 20)

# 可执行文件和源文件
add_executable(PvsZ src/main.cpp
        Pages/Loading.cpp
        Plants/Plant.cpp
        Zombies/Zombie.cpp
        BattlesScenes/Scenes.cpp
        Pages/Menu.cpp
        Pages/UniversalPageFeatures/Initialization.cpp
        src/logic/GameLogic.cpp
        Pages/Managers/MusicManager.cpp
        Pages/Managers/MusicManager.h
        Pages/Managers/PictureManager.cpp
        Pages/Managers/PictureManager.h
)

target_include_directories(PvsZ PRIVATE
        Pages/includes
        Plants
        Zombies
        BattlesScenes
        Pages/UniversalPageFeatures
        src/logic
)

include_directories(Pages/includes)

# 包含目录
include_directories(${PROJECT_SOURCE_DIR}/extern-lib/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/include)

# 库目录
link_directories(${PROJECT_SOURCE_DIR}/extern-lib/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/lib)

# 链接 SFML 库
set(SFML_DIR "${PROJECT_SOURCE_DIR}/extern-lib/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

# ...
target_link_libraries(PvsZ
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)

# 定位所有 DLL 文件
file(GLOB SFML_DLL_FILES "${PROJECT_SOURCE_DIR}/extern-lib/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/bin/*.dll")
# 在项目构建后自动复制 SFML DLL 文件到输出目录
foreach(DLL_FILE ${SFML_DLL_FILES})
    add_custom_command(TARGET PvsZ POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${DLL_FILE}
            $<TARGET_FILE_DIR:PvsZ>)
endforeach()


# 在项目构建后自动复制特定的 SFML DLL 文件到输出目录
#set(SPECIFIC_DLLS "a.dll" "b.dll" "c.dll" "d.dll")
#foreach(DLL_NAME ${SPECIFIC_DLLS})
#    add_custom_command(TARGET PvsZ POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy_if_different
#            "${PROJECT_SOURCE_DIR}/extern-lib/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/bin/${DLL_NAME}"
#            $<TARGET_FILE_DIR:PvsZ>)
#endforeach()