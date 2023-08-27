#pragma once

#include "Classifier.hpp"

namespace document {
    class Document;
}

namespace KNN {

    class CosineSimilarityClassifier : public Classifier
    {

    public:

        CosineSimilarityClassifier();

        nearestVector calculateDistance(const document::Document& docUnderTest);
    };

}
