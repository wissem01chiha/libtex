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

#ifndef TEX_BOOK_H
#define TEX_BOOK_H

#include "document.h"

#ifdef __cplusplus
extern "C" {
#endif

// class Book
// {
// public:
//     Book(const std::string &title = "", const std::string &author = "",
//          const std::string &date = "\\today", Language language =
//          Language::ENGLISH)
//         : Document(DocumentType::BOOK, title, author, date, language)
//     {
//         // Add default packages commonly used in books
//         addPackage("geometry", "margin=1in");
//         addPackage("amsmath");
//         addPackage("graphicx");
//         addPackage("hyperref");
//         addPackage("tocloft");
//         addPackage("bookmark");
//     }

//     void setAbstract(const std::string &abstract)
//     {
//         m_abstract = abstract;
//     }

//     void includeTableOfContents(bool include = true)
//     {
//         m_includeTableOfContents = include;
//     }

//     void includeListOfFigures(bool include = true)
//     {
//         m_includeListOfFigures = include;
//     }

//     void includeListOfTables(bool include = true)
//     {
//         m_includeListOfTables = include;
//     }

//     void includeIndex(bool include = true)
//     {
//         m_includeIndex = include;
//         if (include)
//         {
//             addPackage("imakeidx");
//         }
//     }

//     void addPart(const std::string &title)
//     {
//         m_parts.push_back(title);
//         m_currentPart = m_parts.size() - 1;
//     }

//     void addChapterToPart(const Section &chapter)
//     {
//         if (m_currentPart >= 0 && m_currentPart < m_parts.size())
//         {
//             m_partChapters[m_currentPart].push_back(chapter);
//         }
//     }

//     void addAppendix(const Section &appendix)
//     {
//         m_appendices.push_back(appendix);
//     }

//     std::string generatePreamble() const override;
//     std::string generateDocument() const override;

// private:
//     std::string m_abstract;
//     bool m_includeTableOfContents = false;
//     bool m_includeListOfFigures = false;
//     bool m_includeListOfTables = false;
//     bool m_includeIndex = false;
//     std::vector<std::string> m_parts;
//     std::map<size_t, std::vector<Section>> m_partChapters;
//     std::vector<Section> m_appendices; // Add a vector to store appendices
//     size_t m_currentPart = -1;
// };

#ifdef __cplusplus
};
#endif

#endif  // TEX_BOOK_H