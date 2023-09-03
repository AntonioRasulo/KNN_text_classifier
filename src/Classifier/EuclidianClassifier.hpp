#ifndef EUCLIDIAN_SIMILARITY_H
#define EUCLIDIAN_SIMILARITY_H

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

#endif
