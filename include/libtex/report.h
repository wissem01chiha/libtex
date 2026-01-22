/**
    Copyright (c) 2026, wissem chiha 

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LIBTEX_REPORT_H
#define LIBTEX_REPORT_H

#include "document.h"

#ifdef __cplusplus
extern "C" {
#endif


    class Report  
    {
    public:
        Report(const std::string &title = "", const std::string &author = "",
               const std::string &date = "\\today", Language language = Language::ENGLISH)
            : Document(DocumentType::REPORT, title, author, date, language)
        {
            // Add default packages commonly used in reports
            addPackage("geometry", "margin=1in");
            addPackage("amsmath");
            addPackage("graphicx");
            addPackage("hyperref");
            addPackage("tocloft");
        }

        void setAbstract(const std::string &abstract)
        {
            m_abstract = abstract;
        }

        void includeTableOfContents(bool include = true)
        {
            m_includeTableOfContents = include;
        }

        void includeListOfFigures(bool include = true)
        {
            m_includeListOfFigures = include;
        }

        void includeListOfTables(bool include = true)
        {
            m_includeListOfTables = include;
        }

        std::string generatePreamble() const override;
        std::string generateDocument() const override;

    private:
        std::string m_abstract;
        bool m_includeTableOfContents = false;
        bool m_includeListOfFigures = false;
        bool m_includeListOfTables = false;
    };

#ifdef __cplusplus
};
#endif

#endif // LIBTEX_REPORT_H