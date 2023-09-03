#ifndef COSINE_SIMILARITY_H
#define COSINE_SIMILARITY_H

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

#endif
