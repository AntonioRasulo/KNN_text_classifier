cmake_minimum_required(VERSION 3.16)

add_library(Classifier "")

target_sources(Classifier
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Classifier.cpp
        ${CMAKE_CURRENT_LIST_DIR}/EuclidianClassifier.cpp
        ${CMAKE_CURRENT_LIST_DIR}/CosineSimilarityClassifier.cpp
        ${CMAKE_CURRENT_LIST_DIR}/ManhattanClassifier.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MinkowskiClassifier.cpp
)

target_include_directories(Classifier
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/../Document/
        ${CMAKE_CURRENT_LIST_DIR}/../Utility/
)
