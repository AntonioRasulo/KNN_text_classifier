#ifndef WORD_H
#define WORD_H

#include <string>
#include <map>

namespace document {

    class Word {
    
        std::string m_word;
    
        /* Map that tells how many times the word is present in a document */
        std::map<std::string, int> m_WordOccurrency;

        /* idf parameter of the word */
        long double m_idf;

    public:

        Word(const std::string& word){m_word = word;}

        void updateWordOccurrency(const std::string& docName) {

            m_WordOccurrency[docName]++;

        }

        /* Getters */
        int getNumDocContainingWord() const {
            return m_WordOccurrency.size();
        }
        
        const std::string& getWord() const { return m_word; }

        long double getIdf() const { return m_idf; }

        /* Setters */
        void setIdf(long double idf) { m_idf = idf; }

    };

}

#endif
