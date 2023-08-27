cmake_minimum_required(VERSION 3.16)

########################################################################
# PROJECT EXE
########################################################################

add_executable(main
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_include_directories(main
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(main
PRIVATE
Utility
Document
Classifier
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Utility)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Document)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Classifier)
