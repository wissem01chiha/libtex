/**
     * @brief Base class for all LaTeX documents
     */
    class Document
    {
    public:
        Document(DocumentType type, const std::string &title = "",
                 const std::string &author = "", const std::string &date = "\\today",
                 Language language = Language::ENGLISH);
        virtual ~Document() = default;

        void setTitle(const std::string &title)
        {
            m_title = title;
        }

        void setAuthor(const std::string &author)
        {
            m_author = author;
        }

        void setDate(const std::string &date)
        {
            m_date = date;
        }

        void setLanguage(Language language)
        {
            m_language = language;
        }

        Language getLanguage() const
        {
            return m_language;
        }

        std::string getTitle() const
        {
            return m_title;
        }

        std::string getAuthor() const
        {
            return m_author;
        }

        void addPackage(const std::string &package, const std::string &options = "")
        {
            m_packages[package] = options;
        }

        void addSection(const Section &section)
        {
            m_sections.push_back(section);
        }

        void addEnvironment(std::shared_ptr<Environment> env)
        {
            m_environments.push_back(env);
        }

        void addRawContent(const std::string &content)
        {
            m_rawContent.push_back(content);
        }

        virtual std::string generatePreamble() const;
        virtual std::string generateDocument() const;
        virtual std::string generate() const;

        bool saveToFile(const std::string &Path, const std::string &filePath) const;

        /**
         * @brief Add a citation to the document
         * @param key Citation key from the bibliography
         * @return Citation command string
         */
        std::string cite(const std::string &key)
        {
            m_usedCitations.insert(key);
            return "\\cite{" + key + "}";
        }

        /**
         * @brief Add a citation with page numbers
         * @param key Citation key from the bibliography
         * @param pages Page numbers
         * @return Citation command string
         */
        std::string citePages(const std::string &key, const std::string &pages)
        {
            m_usedCitations.insert(key);
            return "\\cite[" + pages + "]{" + key + "}";
        }

        /**
         * @brief Add a bibliography to the document
         * @param bibliography Bibliography object
         */
        void setBibliography(const Bibliography &bibliography)
        {
            m_bibliography = bibliography;
        }

        /**
         * @brief Add theorem setup to the document preamble
         */
        void enableTheorems()
        {
            m_theoremsEnabled = true;
        }

        /**
         * @brief Add algorithm support to the document preamble
         */
        void enableAlgorithms()
        {
            m_algorithmsEnabled = true;
        }

        /**
         * @brief Add custom preamble content
         * @param content Preamble content
         */
        void addInPreamble(const std::string &content)
        {
            m_customPreamble.push_back(content);
        }

        /**
         * @brief Add a figure to the document
         * @param imagePath Path to the image file
         * @param caption Caption for the figure
         * @param label Label for references (optional)
         * @param width Width of the image (e.g., "0.8\\textwidth")
         * @param position Position specifier (e.g., "h", "ht", "htbp")
         * @return Pointer to the created Figure object
         */
        std::shared_ptr<Figure> addFigure(const std::string &imagePath, 
                                         const std::string &caption,
                                         const std::string &label = "",
                                         const std::string &width = "0.8\\textwidth",
                                         const std::string &position = "htbp");
        
        /**
         * @brief Add a table to the document
         * @param headers Vector of column headers
         * @param caption Caption for the table
         * @param label Label for references (optional)
         * @param position Position specifier (e.g., "h", "ht", "htbp")
         * @return Pointer to the created Table object
         */
        std::shared_ptr<Table> addTable(const std::vector<std::string> &headers,
                                       const std::string &caption,
                                       const std::string &label = "",
                                       const std::string &position = "htbp");

        /**
         * @brief Add a list to the document
         * @param type Type of list (itemize, enumerate, description)
         * @return Pointer to the created List object
         */
        std::shared_ptr<List> addList(List::ListType type = List::ListType::ITEMIZE);
        
        /**
         * @brief Add an equation to the document
         * @param content Equation content in LaTeX format
         * @param label Label for references (optional)
         * @param numbered Whether the equation should be numbered
         * @return Pointer to the created Equation object
         */
        std::shared_ptr<Equation> addEquation(const std::string &content,
                                             const std::string &label = "",
                                             bool numbered = true);
        
        /**
         * @brief Add an inline equation to the document
         * @param content Equation content in LaTeX format
         * @return Formatted string containing the inline equation
         */
        std::string addInlineEquation(const std::string &content);
        
        /**
         * @brief Add an algorithm to the document
         * @param caption Caption for the algorithm
         * @param label Label for references (optional)
         * @return Pointer to the created Algorithm object
         */
        std::shared_ptr<Algorithm> addAlgorithm(const std::string &caption,
                                               const std::string &label = "");
        
        /**
         * @brief Add a theorem environment to the document
         * @param type Type of theorem environment
         * @param content Content of the theorem
         * @param title Optional title for the theorem
         * @return Pointer to the created TheoremEnvironment object
         */
        std::shared_ptr<TheoremEnvironment> addTheorem(TheoremEnvironment::Type type,
                                                     const std::string &content,
                                                     const std::string &title = "");

    protected:
        DocumentType m_type;
        std::string m_title;
        std::string m_author;
        std::string m_date;
        Language m_language;
        std::map<std::string, std::string> m_packages;
        std::vector<Section> m_sections;
        std::vector<std::shared_ptr<Environment>> m_environments;
        std::vector<std::string> m_rawContent;
        std::vector<std::string> m_customPreamble;
        std::set<std::string> m_usedCitations;
        Bibliography m_bibliography;
        bool m_theoremsEnabled = false;
        bool m_algorithmsEnabled = false;

        std::string getDocumentClass() const;
        std::string getLanguageConfiguration() const;
    };
