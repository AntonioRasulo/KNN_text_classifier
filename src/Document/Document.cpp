#include "Document.hpp"
#include <iostream>
namespace document {

    Document::Document() : m_bagOfWords(), m_type(), m_name()
    {

    }

    Document::Document(const std::string& name) : m_bagOfWords(), m_type(), m_name(name)
    {

    }

    void Document::calculateTfParameters()
    {
        for (auto& [word,occurrance] : m_bagOfWords)
        {
            m_wordTf[word] = (long double)occurrance / (long double)m_bagOfWords.size();
        }
    }

    void Document::addWord(const std::string& word)
    {
        m_bagOfWords[word]++;
    }

    void Document::print()
    {
        for (auto& [key, value] : m_bagOfWords)
        {
            std::cout << key << " " << value << std::endl;
        }

        std::cout << "---------------------------------" << std::endl;

    }

}
