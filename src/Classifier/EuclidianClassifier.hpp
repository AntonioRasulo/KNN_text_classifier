#pragma once

#include "Classifier.hpp"

namespace document {
    class Document;
}

namespace KNN {

    class EuclidianClassifier : public Classifier
    {

    public:

        EuclidianClassifier();

        nearestVector calculateDistance(const document::Document& docUnderTest);
    };

}
