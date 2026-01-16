
    /**
     * @brief Class for LaTeX presentation documents (Beamer)
     */
    class Presentation : public Document
    {
    public:
        /**
         * @brief Theme for Beamer presentations
         */
        enum class Theme
        {
            DEFAULT,
            BERKELEY,
            MADRID,
            ANTIBES,
            COPENHAGEN,
            BERLIN,
            MANHATTAN,
            WARSAW,
            SINGAPORE
        };

        /**
         * @brief Color theme for Beamer presentations
         */
        enum class ColorTheme
        {
            DEFAULT,
            BEAVER,
            CRANE,
            DOLPHIN,
            DOVE,
            FLY,
            SEAGULL,
            WOLVERINE
        };

        /**
         * @brief Transition effect for slides
         */
        enum class Transition
        {
            NONE,
            FADE,
            PUSH,
            COVER,
            UNCOVER,
            SPLIT,
            BLINDS,
            WIPE
        };

        Presentation(const std::string &title = "", const std::string &author = "",
                     const std::string &date = "\\today", Language language = Language::ENGLISH,
                     Theme theme = Theme::DEFAULT, ColorTheme colorTheme = ColorTheme::DEFAULT)
            : Document(DocumentType::PRESENTATION, title, author, date, language),
              m_theme(theme), m_colorTheme(colorTheme)
        {
            // Add default packages commonly used in presentations
            addPackage("graphicx");
            addPackage("hyperref");
            addPackage("listings"); // Add listings package for code block support
            addPackage("xcolor");   // Add xcolor package for code coloring
        }

        void setInstitute(const std::string &institute)
        {
            m_institute = institute;
        }

        void setSubtitle(const std::string &subtitle)
        {
            m_subtitle = subtitle;
        }

        void setTheme(Theme theme)
        {
            m_theme = theme;
        }

        void setColorTheme(ColorTheme colorTheme)
        {
            m_colorTheme = colorTheme;
        }

        void setNavigation(bool show)
        {
            m_showNavigation = show;
        }

        void setTransition(Transition transition)
        {
            m_transition = transition;
        }

        void addSlide(const std::string &title, const std::string &content)
        {
            m_slides.push_back({title, {content}});
        }

        void addSlide(const std::string &title, const std::vector<std::string> &content)
        {
            m_slides.push_back({title, content});
        }

        /**
         * @brief Add a section to the presentation
         *
         * Add a section that will appear in the presentation structure and in the table of contents.
         * A section title slide will also be created if createFrame is true.
         *
         * @param title Title of the section
         * @param createFrame If true, create a slide with the section title
         */
        void addSection(const std::string &title, bool createFrame = true)
        {
            m_structure.push_back({Section::Level::SECTION, title, createFrame});
        }

        /**
         * @brief Add a subsection to the presentation
         *
         * Add a subsection that will appear in the presentation structure and in the table of contents.
         * A subsection title slide will also be created if createFrame is true.
         *
         * @param title Title of the subsection
         * @param createFrame If true, create a slide with the subsection title
         */
        void addSubsection(const std::string &title, bool createFrame = true)
        {
            m_structure.push_back({Section::Level::SUBSECTION, title, createFrame});
        }

        /**
         * @brief Add a subsubsection to the presentation
         *
         * @param title Title of the subsubsection
         * @param createFrame If true, create a slide with the subsubsection title
         */
        void addSubsubsection(const std::string &title, bool createFrame = false)
        {
            m_structure.push_back({Section::Level::SUBSUBSECTION, title, createFrame});
        }

        std::string generatePreamble() const override;
        std::string generateDocument() const override;

    private:
        std::string m_institute;
        std::string m_subtitle;
        Theme m_theme;
        ColorTheme m_colorTheme;
        Transition m_transition = Transition::NONE;
        bool m_showNavigation = true;
        std::vector<std::pair<std::string, std::vector<std::string>>> m_slides;
        std::vector<std::tuple<Section::Level, std::string, bool>> m_structure; // level, title, create a slide

        std::string getThemeName() const;
        std::string getColorThemeName() const;
        std::string getTransitionName() const;
        std::string getLevelCommand(Section::Level level) const;
    };

    