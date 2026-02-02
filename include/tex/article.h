/**
    Copyright (c) 2026, wissem chiha

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef TEX_ARTICLE_H
#define TEX_ARTICLE_H

#include "document.h"

#ifdef __cplusplus
extern "C"
{
#endif

  // /**
  //  * @brief Class for LaTeX article documents
  //  */
  // class Article : public Document
  // {
  // public:
  //     Article(const std::string &title = "", const std::string &author = "",
  //             const std::string &date = "\\today", Language language =
  //             Language::ENGLISH)
  //         : Document(DocumentType::ARTICLE, title, author, date, language)
  //     {
  //         // Add default packages commonly used in articles
  //         addPackage("geometry", "margin=1in");
  //         addPackage("amsmath");
  //         addPackage("graphicx");
  //     }

  //     void setAbstract(const std::string &abstract)
  //     {
  //         m_abstract = abstract;
  //     }

  //     /**
  //      * @brief Add custom content to the document preamble
  //      * @param content Content to add to the preamble
  //      */
  //     void addInPreamble(const std::string &content)
  //     {
  //         m_customPreamble.push_back(content);
  //     }

  //     /**
  //      * @brief Add a keyword to the article
  //      * @param keyword Keyword to add
  //      */
  //     void addKeyword(const std::string &keyword)
  //     {
  //         m_keywords.push_back(keyword);
  //     }

  //     /**
  //      * @brief Enable or disable the index in the document
  //      * @param include If true, enable the index
  //      */
  //     void includeIndex(bool include = true)
  //     {
  //         m_includeIndex = include;
  //         if (include)
  //         {
  //             addPackage("imakeidx");
  //         }
  //     }

  //     /**
  //      * @brief Enable or disable the table of contents in the document
  //      * @param include If true, enable the table of contents
  //      */
  //     void includeTableOfContents(bool include = true)
  //     {
  //         m_includeTableOfContents = include;
  //     }

  //     std::string generatePreamble() const override;

  //     void createBibFile() const;

  //     void setBibliography(const Bibliography& bibliography);

  //     std::string generateDocument() const override;

  // private:
  //     std::string m_abstract;
  //     std::vector<std::string> m_customPreamble; // To store custom preamble
  //     content std::vector<std::string> m_keywords;       // To store keywords
  //     bool m_includeIndex = false;               // To enable/disable the
  //     index bool m_includeTableOfContents = false;     // To enable/disable
  //     the table of contents
  // };

#ifdef __cplusplus
};
#endif

#endif // TEX_ARTICLE_H