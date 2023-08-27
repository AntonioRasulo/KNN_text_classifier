#pragma once

#include<map>
#include<string>

namespace utility {
    enum class documentType;
}

namespace document{

    class Document {

        std::map<std::string, int> m_bagOfWords;

        /* Map containing the word and their tf parameter in the document */
        std::map<std::string, long double> m_wordTf;

        std::map<std::string, long double> m_wordTfIdf;

        utility::documentType m_type;

        std::string m_name;

    public:

        Document();
        Document(const std::string& name);

        void calculateTfParameters();

        void addWord(const std::string& word);

        void setDocumentType(const utility::documentType& type) { m_type = type; }

        void print();

        /* Getters */
        const std::map<std::string, int>& getBagOfWords() const {
            return m_bagOfWords;
        }

        const std::map<std::string, long double>& getBagOfTf() const {
            return m_wordTf;
        }

        const std::map<std::string, long double>& getTfIdf() const {
            return m_wordTfIdf;
        }

        void setTfIdf(const std::string& word, long double tfIdf) { m_wordTfIdf[word] = tfIdf; }

        const std::string& getName() const { return m_name; }
        const utility::documentType& getType() const { return m_type; }

    };

}
