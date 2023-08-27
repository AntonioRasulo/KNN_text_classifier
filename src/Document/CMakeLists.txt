cmake_minimum_required(VERSION 3.16)

add_library(Document "")

target_sources(Document
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Document.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Word.cpp
)

target_include_directories(Document
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/../Utility/
)
