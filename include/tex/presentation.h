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

#ifndef TEX_PRESENTATION_H
#define TEX_PRESENTATION_H

#include "document.h"

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct tex_presentation tex_presentation;

  int presentation_create (tex_presentation **presentation, const char *title,
                           const char *author, const char *date, int language,
                           int theme, int color_theme, int err);
  int presentation_delete (tex_presentation *presentation);

  int presentation_set_institute (tex_presentation *presentation,
                                  const char *institute);
  int presentation_set_subtitle (tex_presentation *presentation,
                                 const char *subtitle);
  int presentation_set_navigation (tex_presentation *presentation, int show);
  int presentation_set_transition (tex_presentation *presentation,
                                   int transition);
  int presentation_add_slide (tex_presentation *presentation, const char *title,
                              const char *content);
  int presentation_generate (tex_presentation *presentation, char **output,
                             size_t *output_size);

#ifdef __cplusplus
};
#endif

  //     Presentation(const std::string &title = "", const std::string &author =
  //     "",
  //                  const std::string &date = "\\today", Language language =
  //                  Language::ENGLISH, Theme theme = Theme::DEFAULT,
  //                  ColorTheme colorTheme = ColorTheme::DEFAULT)
  //         : Document(DocumentType::PRESENTATION, title, author, date,
  //         language),
  //           m_theme(theme), m_colorTheme(colorTheme)
  //     {
  //         // Add default packages commonly used in presentations
  //         addPackage("graphicx");
  //         addPackage("hyperref");
  //         addPackage("listings"); // Add listings package for code block
  //         support addPackage("xcolor");   // Add xcolor package for code
  //         coloring
  //     }

  //     void setInstitute(const std::string &institute)
  //     {
  //         m_institute = institute;
  //     }

  //     void setSubtitle(const std::string &subtitle)
  //     {
  //         m_subtitle = subtitle;
  //     }

  //     void setTheme(Theme theme)
  //     {
  //         m_theme = theme;
  //     }

  //     void setColorTheme(ColorTheme colorTheme)
  //     {
  //         m_colorTheme = colorTheme;
  //     }

  //     void setNavigation(bool show)
  //     {
  //         m_showNavigation = show;
  //     }

  //     void setTransition(Transition transition)
  //     {
  //         m_transition = transition;
  //     }

  //     void addSlide(const std::string &title, const std::string &content)
  //     {
  //         m_slides.push_back({title, {content}});
  //     }

  //     void addSlide(const std::string &title, const std::vector<std::string>
  //     &content)
  //     {
  //         m_slides.push_back({title, content});
  //     }

  //     /**
  //      * @brief Add a section to the presentation
  //      *
  //      * Add a section that will appear in the presentation structure and in
  //      the table of contents.
  //      * A section title slide will also be created if createFrame is true.
  //      *
  //      * @param title Title of the section
  //      * @param createFrame If true, create a slide with the section title
  //      */
  //     void addSection(const std::string &title, bool createFrame = true)
  //     {
  //         m_structure.push_back({Section::Level::SECTION, title,
  //         createFrame});
  //     }

  //     /**
  //      * @brief Add a subsection to the presentation
  //      *
  //      * Add a subsection that will appear in the presentation structure and
  //      in the table of contents.
  //      * A subsection title slide will also be created if createFrame is
  //      true.
  //      *
  //      * @param title Title of the subsection
  //      * @param createFrame If true, create a slide with the subsection title
  //      */
  //     void addSubsection(const std::string &title, bool createFrame = true)
  //     {
  //         m_structure.push_back({Section::Level::SUBSECTION, title,
  //         createFrame});
  //     }

  //     /**
  //      * @brief Add a subsubsection to the presentation
  //      *
  //      * @param title Title of the subsubsection
  //      * @param createFrame If true, create a slide with the subsubsection
  //      title
  //      */
  //     void addSubsubsection(const std::string &title, bool createFrame =
  //     false)
  //     {
  //         m_structure.push_back({Section::Level::SUBSUBSECTION, title,
  //         createFrame});
  //     }

  //     std::string generatePreamble() const override;
  //     std::string generateDocument() const override;

  // private:
  //     std::string m_institute;
  //     std::string m_subtitle;
  //     Theme m_theme;
  //     ColorTheme m_colorTheme;
  //     Transition m_transition = Transition::NONE;
  //     bool m_showNavigation = true;
  //     std::vector<std::pair<std::string, std::vector<std::string>>> m_slides;
  //     std::vector<std::tuple<Section::Level, std::string, bool>> m_structure;
  //     // level, title, create a slide

  //     std::string getThemeName() const;
  //     std::string getColorThemeName() const;
  //     std::string getTransitionName() const;
  //     std::string getLevelCommand(Section::Level level) const;
  // };

#endif // TEX_PRESENTATION_H