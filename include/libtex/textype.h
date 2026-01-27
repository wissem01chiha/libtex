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

#ifndef LIBTEX_TEXTYPE_H
#define LIBTEX_TEXTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  tex_document_t
{
    ARTICLE_DOC =0,
    REPORT_DOC =1,
    BOOK_DOC =2,
    PRESENTATION_DOC =3

} tex_document_t;

typedef enum tex_language_t
{
    ENGLISH =0,  
    FRENCH=1,
    GERMAN=2,
    SPANISH=3,
    ITALIAN=4,
    PORTUGUESE=5,
    DUTCH=6,
    RUSSIAN=7,
    CHINESE=8,
    JAPANESE=9,
    ARABIC=10

} tex_language_t;

typedef enum tex_bibstyle_t
{
    PLAIN =0,    
    ALPHA =1,    
    ABBRV =2,    
    ACM =3,      
    IEEE =4,     
    APA =5,      
    CHICAGO =6,  
    MLA =7,      
    HARVARD =8,  
    CUSTOM_BIBSTYLE =9 

} tex_bibstyle_t;

typedef enum tex_section_t
{
    CHAPTER = 0,      
    SECTION = 1,       
    SUBSECTION = 2,    
    SUBSUBSECTION = 3 

} tex_section_t;

typedef enum tex_list_t
{
    ITEMIZE =0,
    ENUMERATE =1,
    DESCRIPTION =2

} tex_list_t;

typedef enum tex_bib_t
{
    ARTICLE =0,
    BOOK =1,
    INPROCEEDINGS =2,
    TECHREPORT =3,
    PHDTHESIS =4,
    MASTERSTHESIS =5,
    MISC =6

} tex_bib_t;

typedef enum tex_theorem_t
{
    THEOREM =0,
    LEMMA =1,
    PROPOSITION =2,
    COROLLARY =3,
    DEFINITION =4,
    EXAMPLE =5,
    REMARK =6,
    PROOF =7,
    CUSTOM_THEOREM =8

} tex_theorem_t;

typedef enum tex_transition_t
{
    NONE=0,
    FADE=1,
    PUSH=2,
    COVER=3,
    UNCOVER=4,
    SPLIT=5,
    BLINDS=6,
    WIPE=7
} tex_transition_t;

typedef enum tex_color_theme_t
{
    DEFAULT_COLOR=0,
    BEAVER=1,
    CRANE=2,
    DOLPHIN=3,
    DOVE=4,
    FLY=5,
    SEAGULL=6,
    WOLVERINE=7
} tex_color_theme_t;

typedef enum tex_theme_t
{
    DEFAULT_THEME=0,
    BERKELEY=1,
    MADRID=2,
    ANTIBES=3,
    COPENHAGEN=4,
    BERLIN=5,
    MANHATTAN=6,
    WARSAW=7,
    SINGAPORE=8
} tex_theme_t;

#ifdef __cplusplus
};
#endif

#endif // LIBTEX_TEXTYPE_H