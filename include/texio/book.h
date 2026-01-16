
    /**
     * @brief Class for LaTeX book documents
     */
    class Book : public Document
    {
    public:
        Book(const std::string &title = "", const std::string &author = "",
             const std::string &date = "\\today", Language language = Language::ENGLISH)
            : Document(DocumentType::BOOK, title, author, date, language)
        {
            // Add default packages commonly used in books
            addPackage("geometry", "margin=1in");
            addPackage("amsmath");
            addPackage("graphicx");
            addPackage("hyperref");
            addPackage("tocloft");
            addPackage("bookmark");
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

        void includeIndex(bool include = true)
        {
            m_includeIndex = include;
            if (include)
            {
                addPackage("imakeidx");
            }
        }

        void addPart(const std::string &title)
        {
            m_parts.push_back(title);
            m_currentPart = m_parts.size() - 1;
        }

        void addChapterToPart(const Section &chapter)
        {
            if (m_currentPart >= 0 && m_currentPart < m_parts.size())
            {
                m_partChapters[m_currentPart].push_back(chapter);
            }
        }

        void addAppendix(const Section &appendix)
        {
            m_appendices.push_back(appendix);
        }

        std::string generatePreamble() const override;
        std::string generateDocument() const override;

    private:
        std::string m_abstract;
        bool m_includeTableOfContents = false;
        bool m_includeListOfFigures = false;
        bool m_includeListOfTables = false;
        bool m_includeIndex = false;
        std::vector<std::string> m_parts;
        std::map<size_t, std::vector<Section>> m_partChapters;
        std::vector<Section> m_appendices; // Add a vector to store appendices
        size_t m_currentPart = -1;
    };
