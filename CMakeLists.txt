﻿cmake_minimum_required(VERSION 3.26)
project(hauk)

# 컴파일 옵션 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# 라이브러리 설정
set(LIBRARY_NAME ${PROJECT_NAME})
set(PCH_FILE_HEADER "src/hauk/pch.hpp")

# 소스 설정
set(SRC_HAUK_GAME
        src/hauk/game/Application.cpp
        src/hauk/game/Player.cpp
)
set(SRC_HAUK_GAME_STATE
        src/hauk/game/state/StateStack.cpp
        src/hauk/game/state/State.cpp
)
set(SRC_HAUK_GAME_RESOURCE
        include/hauk/game/resource/ResourceIdentifiers.hpp
)
set(SRC_HAUK_GAME_UTIL
        src/hauk/game/util/util.cpp
)
set(SRC_HAUK_GAME_ENTITY
        src/hauk/game/entity/Entity.cpp
        src/hauk/game/entity/SceneNode.cpp
        src/hauk/game/entity/SpriteNode.cpp
        src/hauk/game/entity/TextNode.cpp
        src/hauk/game/entity/ParticleNode.cpp
        src/hauk/game/entity/EmitterNode.cpp
        src/hauk/game/entity/Animation.cpp
)
set(SRC_HAUK_GAME_DATA
        src/hauk/game/data/ParticleData.cpp
)
set(SRC_HAUK_GAME_INPUT
        src/hauk/game/input/Command.cpp
        src/hauk/game/input/CommandQueue.cpp
)
set(SRC_HAUK_GAME_GUI
        src/hauk/game/gui/Component.cpp
        src/hauk/game/gui/Container.cpp
        src/hauk/game/gui/Label.cpp
        src/hauk/game/gui/Button.cpp
)
set(SRC_HAUK_GAME_EFFECT
        src/hauk/game/effect/PostEffect.cpp
        src/hauk/game/effect/BloomEffect.cpp
)
set(SRC_HAUK_THREAD
        src/hauk/thread/ParallelTask.cpp
)

# 공유 라이브러리 빌드 설정
add_library(${LIBRARY_NAME} SHARED
        ${SRC_HAUK_GAME}
        ${SRC_HAUK_GAME_STATE}
        ${SRC_HAUK_GAME_RESOURCE}
        ${SRC_HAUK_GAME_UTIL}
        ${SRC_HAUK_GAME_ENTITY}
        ${SRC_HAUK_GAME_DATA}
        ${SRC_HAUK_GAME_INPUT}
        ${SRC_HAUK_GAME_GUI}
        ${SRC_HAUK_GAME_EFFECT}

        ${SRC_HAUK_THREAD}
)

# 프리컴파일 헤더 설정
target_precompile_headers(${LIBRARY_NAME}
        PUBLIC ${PCH_FILE_HEADER}
)

# 라이브러리를 포함하는 디렉토리 추가
target_include_directories(${LIBRARY_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# 라이브러리 파일 이름 설정
set_target_properties(${LIBRARY_NAME}
PROPERTIES
OUTPUT_NAME ${LIBRARY_NAME}
)

# Detect and add SFML
find_package(SFML 2 COMPONENTS graphics window system audio network REQUIRED)
# Find any version 2.X of SFML
if (SFML_FOUND)
    target_link_libraries(${LIBRARY_NAME}
            sfml-graphics
    )
endif(SFML_FOUND)
