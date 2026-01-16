/**
    BSD 2-Clause License

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

typedef enum  
{
    ARTICLE =0,
    REPORT,
    BOOK,
    PRESENTATION
} tex_document_t;


typedef enum   
{
    ENGLISH =0,  
    FRENCH,
    GERMAN,
    SPANISH,
    ITALIAN,
    PORTUGUESE,
    DUTCH,
    RUSSIAN,
    CHINESE,
    JAPANESE,
    ARABIC
} tex_language_t;

typedef enum    
{
    PLAIN,   // Basic style with numbered references
    ALPHA,   // Alpha-style with author-year labels
    ABBRV,   // Abbreviated style
    ACM,     // Association for Computing Machinery style
    IEEE,    // Institute of Electrical and Electronics Engineers style
    APA,     // American Psychological Association style
    CHICAGO, // Chicago style
    MLA,     // Modern Language Association style
    HARVARD, // Harvard style
    CUSTOM   // Custom style with user-defined .bst file
} tex_bibstyle_t;


typedef enum   
{
    CHAPTER = -1,     // For chapters (only for reports and books)
    SECTION = 0,      // For sections
    SUBSECTION = 1,   // For subsections
    SUBSUBSECTION = 2 // For subsubsections
} tex_sectionlevel_t;


typedef enum
{
    ITEMIZE,
    ENUMERATE,
    DESCRIPTION
}tex_list_t;


typedef enum
{
    ARTICLE,
    BOOK,
    INPROCEEDINGS,
    TECHREPORT,
    PHDTHESIS,
    MASTERSTHESIS,
    MISC
} tex_bib_t;


    /**
         * @brief Enum for theorem-like environment types
         */
        enum class Type
        {
            THEOREM,
            LEMMA,
            PROPOSITION,
            COROLLARY,
            DEFINITION,
            EXAMPLE,
            REMARK,
            PROOF,
            CUSTOM
        };
