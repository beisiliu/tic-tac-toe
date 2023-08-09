# 指定cmake的最低要求的版本号
cmake_minimum_required(VERSION 3.21)

# 设置工程名变量
set(projectName tic-tac-toe)
set(CMAKE_CXX_FLAGS "-std=c++20")
set(CMAKE_BUILD_TYPE "Release")

# 指定工程名
project(${projectName})

# 查找响应的包
find_package(SDL2 REQUIRED COMPONENTS SDL2)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

# 编译
add_executable(${projectName} main.cpp loadTexture.cpp mainGame.cpp mouseEvent.cpp rendererDraw.cpp)

# 连接库
target_link_libraries(${projectName} PRIVATE SDL2::SDL2)
target_link_libraries(${projectName} PRIVATE SDL2_image::SDL2_image)
target_link_libraries(${projectName} PRIVATE SDL2_mixer::SDL2_mixer)
target_link_libraries(${projectName} PRIVATE SDL2_ttf::SDL2_ttf)