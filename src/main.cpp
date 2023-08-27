#include "CLI.hpp"
#include "Classifier.hpp"
#include "EuclidianClassifier.hpp"
#include "CosineSimilarityClassifier.hpp"
#include "ManhattanClassifier.hpp"
#include "MinkowskiClassifier.hpp"
#include "Document.hpp"
#include <stdexcept>
#include <iostream>

int main(int argc, char** argv) {

    std::string trainingSetPath;
    std::string inputDocumentPath;
    std::string outputPath;
    unsigned int k;
    unsigned int p;
    document::Document documentUnderTest;

    /* Get path to training set, to document under test and k. */
    try {
        trainingSetPath = utility::checkAndGetCmdOption(argv, argc + argv, "-set");
        inputDocumentPath = utility::checkAndGetCmdOption(argv, argc + argv, "-input");
        k = std::stoul(utility::checkAndGetCmdOption(argv, argc + argv, "-k"));
        outputPath = utility::checkAndGetCmdOption(argv, argc + argv, "-output");
        p = std::stoul(utility::checkAndGetCmdOption(argv, argc + argv, "-p"));
    }
    catch (std::runtime_error& ex)
    {
        std::cerr << ex.what() << std::endl;
        return -1;
    }
    catch (std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
        return -1;
    }
    catch (std::out_of_range& ex)
    {
        std::cerr << ex.what() << std::endl;
        return -1;
    }

    /* Get a Document class of the document under test. */
    try {
        documentUnderTest = KNN::Classifier::populateWordDictionary(inputDocumentPath);
    }
    catch (std::runtime_error& ex) {
        std::cerr << ex.what() << std::endl;
    }

    /* Train the KNN model. */
    try {
        KNN::Classifier::initTrainingSet(trainingSetPath);
    }
    catch (std::runtime_error& ex) {
        std::cerr << ex.what() << std::endl;
    }
    documentUnderTest.calculateTfParameters();

    /* Set K */
    KNN::Classifier::setk(k);
    KNN::Classifier::setOutputPath(outputPath);


    KNN::Classifier::calculateTrainingSetparameters();
    KNN::Classifier::calculateDocparameters(documentUnderTest);

    /* Euclidian classifier */
    KNN::EuclidianClassifier euclidianClassifier;

    KNN::nearestVector vec = euclidianClassifier.calculateDistance(documentUnderTest);

    euclidianClassifier.generateOutputFiles(vec, documentUnderTest.getName());

    /* Cosine similarity classifier */

    KNN::CosineSimilarityClassifier cosineClassifier;

    vec = cosineClassifier.calculateDistance(documentUnderTest);

    cosineClassifier.generateOutputFiles(vec, documentUnderTest.getName());

    /* Manhattan Classifier */
    KNN::ManhattanClassifier manClassifier;

    vec = manClassifier.calculateDistance(documentUnderTest);

    manClassifier.generateOutputFiles(vec, documentUnderTest.getName());

    /* Minkowski Classifier */
    if (p == 0) {
        p = 1;
    }

    KNN::MinkowskiClassifier minkowskiClassifier(p);

    vec = minkowskiClassifier.calculateDistance(documentUnderTest);

    minkowskiClassifier.generateOutputFiles(vec, documentUnderTest.getName());

}
