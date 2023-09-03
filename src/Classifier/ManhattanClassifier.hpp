#ifndef MANHATTAN_H
#define MANHATTAN_H

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

#endif
