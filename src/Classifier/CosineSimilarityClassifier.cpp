#include "CosineSimilarityClassifier.hpp"
#include "Document.hpp"
#include "General.hpp"

namespace KNN {

    CosineSimilarityClassifier::CosineSimilarityClassifier()
    {
        m_classifierType = "\\CosineSimilarity";
    }

    nearestVector CosineSimilarityClassifier::calculateDistance(const document::Document& docUnderTest)
    {
        nearestVector tmpVec;

        /* Iterate throught the training docs */
        for (const auto& trainingDoc : m_trainingSet)
        {
            double result = 0.0;
            long double magnitudeDocUnderTest = 1.0;
            long double magnitudeTrainingDoc = 1.0;
            std::map<std::string, long double> bagUnderTest = docUnderTest.getTfIdf();
            std::map<std::string, long double> trainingBag = trainingDoc.getTfIdf();

            /* Create map word -> tf*idf for the trainingDoc */
            for (const auto& [wordUnderTest, tfIdf] : bagUnderTest)
            {
                magnitudeDocUnderTest += pow(tfIdf,2);
                result += tfIdf * trainingBag[wordUnderTest];
            }

            /* Calculate magnitudeTrainingDoc */
            for (const auto& [word, tfIdf] : trainingBag)
            {
                magnitudeTrainingDoc += pow(tfIdf, 2);
            }

            result /= sqrt(magnitudeDocUnderTest * magnitudeTrainingDoc);

            result = 1 - result;

            tmpVec.push_back(std::make_pair(trainingDoc, sqrt(result)));

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
