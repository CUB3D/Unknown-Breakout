#cmake_minimum_required(VERSION 3.9)
#set(CMAKE_CXX_STANDARD 17)
#
##---- \/ CHANGE THIS \/ ----
#
#set(UK_DIR /home/cub3d/Development/git/Unknown-1.0-CPP)
#set(EXECUTABLE_NAME Breakout)
#
##---- \/ DONT CHANGE THIS \/ ----
#
#project("Unknown Game")
#
#set(UK_INCLUDE "${UK_DIR}/Output/lib/${CMAKE_HOST_SYSTEM_NAME}/include")
#
#set(UK_LIB "${UK_DIR}/Output/lib/${CMAKE_HOST_SYSTEM_NAME}/")
#
#set(RJ_INCLUDE ${UK_DIR}/Libs/RapidJson/include/rapidjson)
#
#set(DEBUG_DIR ${PROJECT_SOURCE_DIR}/run/Debug)
#set(RELEASE_DIR ${PROJECT_SOURCE_DIR}/run/Release)
#
#set(CMAKE_MODULE_PATH ${UK_DIR}/tools/build/cmake-scripts)
#
## Enable debugging on g++
#if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb -O3")
#endif()
#
## Emscripten support
#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    # TODO: add simd when it is supported with wasm
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isystem -s USE_SDL=2 -s USE_SDL_TTF=2 -s USE_SDL_IMAGE=2 -s USE_LIBPNG=1 -s USE_WEBGL2=1 -s WASM=1 -s DEMANGLE_SUPPORT=1 -s FULL_ES2=1 -s FULL_ES3=1 NO_EXIT_RUNTIME=0 -s SDL2_IMAGE_FORMATS='[\"png\"]'")
#
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --preload-file '/home/cub3d/Nextcloud/Development/Tetris/run/Debug/Config.json@Config.json'")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --preload-file '/home/cub3d/Nextcloud/Development/Tetris/run/Debug/res/0.png@res/0.png'")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --preload-file '/home/cub3d/Nextcloud/Development/Tetris/run/Debug/res/1.png@res/1.png'")
#
#    # Need to have a .html,.js or .wasm ending for emscripten to compile to anything other than llvm bytecode
#    set(EXECUTABLE_NAME ${EXECUTABLE_NAME}.html)
#endif()
#
## Find SDL2
#find_package(SDL2 REQUIRED)
#if(SDL2_FOUND)
#    message("SDL2 Found: ${SDL2_INCLUDE_DIR}:${SDL2_LIBRARY}")
#endif()
#
## Find SDL2_image
#find_package(SDL2_image REQUIRED)
#if(SDL2_IMAGE_FOUND)
#    message("SDL2_image Found: ${SDL2_IMAGE_INCLUDE_DIR}:${SDL2_IMAGE_LIBRARY}")
#endif()
#
## Find SDL2_ttf
#find_package(SDL2_ttf REQUIRED)
#if(SDL2_TTF_FOUND)
#    message("SDL2_ttf Found: ${SDL2_TTF_INCLUDE_DIR}:${SDL2_TTF_LIBRARY}")
#endif()
#
## Find SDL2_mixer
#find_package(SDL2_mixer REQUIRED)
#if(SDL_MXIXER_FOUND)
#    message("SDL2_mixer: ${SDL2_MIXER_INCLUDE_DIR}:${SDL2_MIXER_LIBRARY}")
#endif()
#
## Find python
#find_package(PythonLibs)
#if(PYTHONLIBS_FOUND)
#    message("Python found: ${PYTHON_INCLUDE_DIRS}:${PYTHON_LIBRARIES}")
#endif()
#
#set(Reflex_INCLUDE ${UK_DIR}/Libs/Reflex)
#
#if(WIN32)
#    #set(Python3_FOUND TRUE)
#    #set(Python3_INCLUDE_DIRS B:\\Programs\\python3.6.6\\include)
#    #set(Python3_LIBRARIES B:\\Programs\\python3.6.6\\libs\\Python36.lib)
#    set(PYTHONLIBS_FOUND TRUE)
#    set(PYTHON_INCLUDE_DIRS B:\\Programs\\python3.6.6\\include)
#    set(PYTHON_LIBRARIES B:\\Programs\\python3.6.6\\libs\\Python36.lib)
#endif()
#
##TODO: Make work on windows and add REQUIRED
#
##find_package(Python3 COMPONENTS Development)
##if(Python3_FOUND)
##    message("Python found: ${Python3_INCLUDE_DIRS}:${Python3_LIBRARIES}")
##endif()
#
##TODO: Add this back in when cmake 3.12 is available
#
#find_package(PythonLibs)
#if(PYTHONLIBS_FOUND)
#    message("Python found: ${PYTHON_INCLUDE_DIRS}:${PYTHON_LIBRARIES}")
#endif()
#
#set(PYTHON_INCLUDE_DIRS /usr/include/python3.7m)
#set(PYTHON_LIBRARIES /usr/lib/libpython3.7m.so)
#
## Find box2d
#if(UNIX)
#    find_package(Box2D REQUIRED)
#endif()
#if(WIN32)
#    find_package(Box2DWin REQUIRED)
#endif()
#
#if(TRAVIS)
#    set(BOX2D_LIBRARY /usr/lib/x86_64-linux-gnu/libBox2D.so)
#endif(TRAVIS)
#
#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    set(BOX2D_INCLUDE_DIR ${UK_DIR}/Libs/Box2D/Box2D)
#    set(BOX2D_LIBRARY  ${UK_DIR}/Libs/Box2D/Box2D/Build/gmake2/bin/Debug/libBox2D.a)
#endif()
#
#message("Found box2d: ${BOX2D_INCLUDE_DIR}:${BOX2D_LIBRARY}")
#
#if(UNIX)
#    set(UNIX_LIBS pthread dl util m stdc++fs)
#endif()
#
#if(WIN32)
#    set(WIN32_LIBS ${SDL2MAIN_LIBRARY})
#endif()
#
#SET(COMBINED_LIBS ${SDL2_TTF_LIBRARY} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY} ${PYTHON_LIBRARIES} ${BOX2D_LIBRARY} ${UNIX_LIBS} ${WIN32_LIBS})
#SET(COMBINED_INCLUDE ${UK_INCLUDE} ${RJ_INCLUDE} ${PYTHON_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${BOX2D_INCLUDE_DIR} ${Reflex_INCLUDE})
#
#message("LIBS: ${COMBINED_LIBS}")
#message("INCLUDE: ${COMBINED_INCLUDE}")
#
#include_directories(${COMBINED_INCLUDE})
#link_directories(${UK_LIB})
#
#FILE(GLOB_RECURSE GAME_SRC "src/*.c*")
#
#add_executable(${EXECUTABLE_NAME} ${GAME_SRC})
#target_link_libraries(${EXECUTABLE_NAME} UK ${COMBINED_LIBS} pthread dl util m stdc++fs)
#set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DEBUG_DIR})

set(GAME_SRC BreakoutScene.cpp main.cpp "../Libraries/Unknown-1.0-CPP/Unknown 1.0++/src/Scene/SceneElementPrototype.cpp" "../Libraries/Unknown-1.0-CPP/Unknown 1.0++/src/Scene/SceneElementPrototype.h" MainMenuScene.cpp MainMenuScene.h)
add_executable(Breakout ${GAME_SRC})
target_link_libraries(Breakout Unknown_Engine)
