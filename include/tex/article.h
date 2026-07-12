/** Copyright (c) 2026, wissem chiha

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

#ifndef ARTICLE_H
#define ARTICLE_H

#include "document.h"
#include "errno.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tex_article tex_article;

struct tex_article {
  tex_document* document;
};

tex_article* article_create(tex_error_t* err);
tex_error_t article_delete(tex_article* art);

// inherited member functions from text_document
tex_error_t article_set_title(tex_article* doc, const char* title);
tex_error_t article_set_author(tex_article* doc, const char* author);
tex_error_t article_set_date(tex_article* doc, const char* date);
tex_error_t article_set_language(tex_article* doc, tex_language_t language);
tex_error_t article_add_content(tex_article* doc, const char* content);
tex_error_t article_add_section(tex_article* doc, const tex_section* sec);

// enable or disable the index in the document
tex_error_t article_enable_index(tex_article* doc);






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

#endif  // ARTICLE_H
