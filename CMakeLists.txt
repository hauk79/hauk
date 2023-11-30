cmake_minimum_required(VERSION 3.26)
project(hauk)

# 컴파일 옵션 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(LIBRARY_NAME ${PROJECT_NAME})

# 공유 라이브러리 빌드 설정
add_library(${LIBRARY_NAME} SHARED
        src/library.cpp
)

# 라이브러리를 포함하는 디렉토리 추가
target_include_directories(${LIBRARY_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(${LIBRARY_NAME}
PROPERTIES
OUTPUT_NAME "hauk"
)
