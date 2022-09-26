cmake_minimum_required (VERSION 2.8)

project (hello)


set(SOURCES src/testfunc.cpp 
            src/testfunc1.cpp
            src/main.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
            PRIVATE
            ${PROJECT_SOURCE_DIR}/include
            )