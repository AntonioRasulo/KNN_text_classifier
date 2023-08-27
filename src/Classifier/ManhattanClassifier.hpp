#pragma once

#include "Classifier.hpp"

namespace document {
    class Document;
}

namespace KNN {

    class ManhattanClassifier : public Classifier
    {

    public:

        ManhattanClassifier();

        nearestVector calculateDistance(const document::Document& docUnderTest);
    };

}
