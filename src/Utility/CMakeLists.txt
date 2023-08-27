cmake_minimum_required(VERSION 3.16)

add_library(Utility "")

target_sources(Utility
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/CLI.cpp
        ${CMAKE_CURRENT_LIST_DIR}/General.cpp
)

target_include_directories(Utility
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
