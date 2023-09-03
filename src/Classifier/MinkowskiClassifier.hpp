#ifndef MINKOWSKI_H
#define MINKOWSKI_H

#include "Classifier.hpp"

namespace document {
    class Document;
}

namespace KNN {

    class MinkowskiClassifier : public Classifier
    {

        int m_p;

    public:

        MinkowskiClassifier(int p = 1);

        nearestVector calculateDistance(const document::Document& docUnderTest);

        void setP(int p) { m_p = p; }

    };

}

#endif
