#include "Classifier.hpp"
#include "General.hpp"
#include "Document.hpp"
#include <stdexcept>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
namespace KNN {

    void Classifier::initTrainingSet(const std::string& documentsPath)
    {
        /* Iterate through the folders */
        for (const auto& entry : std::filesystem::directory_iterator(documentsPath)) {
            /* Iterate though the files */
            for (const auto& fileName : std::filesystem::directory_iterator(entry)) {
                try {
                    m_trainingSet.push_back(populateWordDictionary(fileName.path().string(), entry));
                }
                catch (std::runtime_error& ex) {
                    throw ex;
                }
            }
        }
    }

    document::Document Classifier::populateWordDictionary(const std::string& filePath, const std::filesystem::directory_entry& dir)
    {
        m_totalNumberOfDoc++;
        std::string docName = filePath.substr(filePath.find_last_of("\\\\") + 1);

        std::fstream fs(filePath);

        if (!fs.is_open())
        {
            std::stringstream ss;
            ss << "Error in opening file: " << filePath;
            throw std::runtime_error(ss.str());
        }

        document::Document doc(docName);
        std::string word;

        while (fs >> word)
        {
            std::string cleanedWord;

            utility::stripUnicode(word);

            for (auto& c : word) {
                if (std::ispunct(c)) {
                    c = ' ';
                }
            }
            std::stringstream ss(word);
            while (std::getline(ss, cleanedWord, ' ')) {

                for (auto& ch : cleanedWord)
                {
                    ch = tolower(ch);
                }

                if ("" != cleanedWord && cleanedWord.size() > 1 && utility::isWordAccepted(cleanedWord))
                {
                    doc.addWord(cleanedWord);


                    auto it = std::find_if(m_wordVec.begin(), m_wordVec.end(), [&cleanedWord](const document::Word& word) {
                        return word.getWord() == cleanedWord;
                        });

                    if (it == m_wordVec.end())
                    {
                        document::Word w(cleanedWord);
                        m_wordVec.push_back(cleanedWord);

                        it = m_wordVec.end() - 1;
                    }

                    it->updateWordOccurrency(cleanedWord);
                }
            }
        }

        utility::documentType docType;

        if (dir != std::filesystem::directory_entry())
        {
            try {
                docType = utility::stringToEnum.at(dir.path().parent_path().string());
            }
            catch (const std::out_of_range&)
            {
                docType = utility::documentType::UNKNOWN;
            }

            doc.setDocumentType(docType);

        }

        return doc;

    }

    void Classifier::calculateWordsIdf()
    {
        for (document::Word& word : m_wordVec)
        {
            word.setIdf(std::log10((double long)m_totalNumberOfDoc / (double long)word.getNumDocContainingWord()));
        }
    }

    void Classifier::calculateTfParameters()
    {
        for (document::Document& doc : m_trainingSet)
        {
            doc.calculateTfParameters();
        }
    }

    void Classifier::calculateTrainingSetparameters()
    {

        calculateTfParameters();
        calculateWordsIdf();

        for (document::Document& doc : m_trainingSet)
        {
            calculateDocparameters(doc);
        }
    }

    void Classifier::calculateDocparameters(document::Document& doc)
    {
        for (auto& [word, tf] : doc.getBagOfTf())
        {
            auto it = std::find_if(m_wordVec.begin(), m_wordVec.end(), [&word](const document::Word& wordObj) {
                return word == wordObj.getWord();
                });

            if (it == m_wordVec.end())
            {
                throw std::runtime_error("Error: word not found in Classifier::m_wordVec");
            }

            doc.setTfIdf(word, tf * (it->getIdf()));

        }
    }

    void Classifier::generateOutputFiles(const nearestVector& vec, const std::string& docName)
    {
        if (m_outputPath == "") {
            throw std::runtime_error("Output path has not been assigned.");
        }

        /* Create output folder if not present */
        if (!std::filesystem::is_directory(m_outputPath))
        {
            std::filesystem::create_directory(m_outputPath);
        }

        std::string csvDocName = docName.substr(0, docName.find_last_of(".")) + ".csv";
        std::filesystem::path filepath = m_outputPath + m_classifierType;

        /* If classifier folder present delete it's content, else create the folder */
        if (std::filesystem::is_directory(filepath)) {

            for (const auto& fileName : std::filesystem::directory_iterator(filepath)) {

                if(fileName.path().string() == csvDocName)
                    std::filesystem::remove(fileName);

            }

        }
        else {
        
            std::filesystem::create_directory(filepath.string());
            
        }

        filepath += "\\" + csvDocName;

        /* Create the csv file and print the data */
        std::ofstream fd(filepath);
        fd << "Name,Distance,Type" << std::endl;
        for (auto& docValuePair : vec)
        {
            fd << docValuePair.first.getName() << "," << docValuePair.second <<"," << static_cast<int>(docValuePair.first.getType()) << std::endl;
        }

    }

    int Classifier::m_k = 0;
    int Classifier::m_totalNumberOfDoc = 0;
    std::vector<document::Word> Classifier::m_wordVec;
    vectorDoc Classifier::m_trainingSet;
    std::string Classifier::m_outputPath = "";

    bool compareResults(std::pair<document::Document, long double>& a,
        std::pair<document::Document, long double>& b)
    {
        return a.second < b.second;
    }

}
