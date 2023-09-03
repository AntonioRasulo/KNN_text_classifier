#include "MinkowskiClassifier.hpp"
#include "Document.hpp"
#include "General.hpp"
#if defined(__linux__) 
#include <cmath>
#endif

namespace KNN {

    MinkowskiClassifier::MinkowskiClassifier(int p) : m_p(p)
    {
        #if defined(__linux__) 
            m_classifierType = "/Minkowski";
        #elif _WIN32 || _WIN64
            m_classifierType = "\\Minkowski";
        #endif
    }

    nearestVector MinkowskiClassifier::calculateDistance(const document::Document& docUnderTest)
    {
        nearestVector tmpVec;

        /* Iterate throught the training docs */
        for (const auto& trainingDoc : m_trainingSet)
        {
            double result = 0.0;
            std::map<std::string, long double> bagUnderTest = docUnderTest.getTfIdf();
            std::map<std::string, long double> trainingBag = trainingDoc.getTfIdf();

            /* Create map word -> tf*idf for the trainingDoc */
            for (const auto& [wordUnderTest, tfIdf] : bagUnderTest)
            {
                result += pow(tfIdf - trainingBag[wordUnderTest], m_p);
            }

            tmpVec.push_back(std::make_pair(trainingDoc, pow(result, (double)1/m_p)));

        }

        std::sort(tmpVec.begin(), tmpVec.end(), compareResults);

        nearestVector returnVec;

        for (int i = 0; i < m_k && i < tmpVec.size(); i++)
        {
            returnVec.push_back(tmpVec[i]);
        }

        return returnVec;

    }

}
