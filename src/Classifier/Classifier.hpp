#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <string>
#include <filesystem>

#if defined(__linux__) 
#include <vector>
#endif

#include "Word.hpp"

namespace document {
    class Document;
}

namespace KNN {

    using vectorDoc = std::vector<document::Document>;
    using nearestVector = std::vector<std::pair<document::Document, long double>>;

    bool compareResults(std::pair<document::Document, long double>& a,
        std::pair<document::Document, long double>& b);

    class Classifier {
    protected:

        static std::string m_outputPath;

        std::string m_classifierType;

        static int m_k;

        static std::vector<document::Word> m_wordVec;

        static int m_totalNumberOfDoc;

        static std::map<std::string, long double> m_tfIdf;

        static vectorDoc m_trainingSet;

        static void calculateWordsIdf();

        static void calculateTfParameters();

    public:

        /*! Method used to parse the documents and populate the training set.
            \input documentsPath is the path to the folder containing the documents.
        */
        static void initTrainingSet(const std::string& documentsPath);

        /* Method that given a filepath provide a Document object */
        static document::Document populateWordDictionary(const std::string& filePath, const std::filesystem::directory_entry& dir = std::filesystem::directory_entry());

        static void calculateTrainingSetparameters();

        static void calculateDocparameters(document::Document& doc);

        void generateOutputFiles(const nearestVector& vec, const std::string& docName);

        virtual nearestVector calculateDistance(const document::Document& docUnderTest) = 0;

        static void setk(int k) { m_k = k; }

        static void setOutputPath(const std::string& path) { m_outputPath = path; }

    };

}

#endif
