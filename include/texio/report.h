
    /**
     * @brief Class for LaTeX report documents
     */
    class Report : public Document
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
