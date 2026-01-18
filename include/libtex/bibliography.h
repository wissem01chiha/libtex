/**
     * @brief Class to manage bibliographies in LaTeX documents
     */
    class Bibliography
    {
    public:
        /**
         * @brief Constructor for an external .bib file
         * @param bibFile Path to the .bib file (without extension)
         * @param style Bibliography style
         */
        Bibliography(const std::string &bibFile, BibStyle style = BibStyle::PLAIN)
            : m_bibFile(bibFile), m_style(style), m_customStyle(""), m_useExternalFile(true) {}

        /**
         * @brief Default constructor (empty bibliography)
         */
        Bibliography() 
            : m_bibFile("references"), m_style(BibStyle::PLAIN), m_customStyle(""), m_useExternalFile(false) {}

        /**
         * @brief Constructor for bibliography with custom style
         * @param bibFile Path to the .bib file (without extension)
         * @param customStyle Name of the custom .bst style file (without extension)
         */
        Bibliography(const std::string &bibFile, const std::string &customStyle)
            : m_bibFile(bibFile), m_style(BibStyle::CUSTOM), m_customStyle(customStyle), m_useExternalFile(true) {}

        /**
         * @brief Set the .bib file
         * @param bibFile Path to the .bib file (without extension)
         * @param useExternalFile If true, use an existing file. If false, generate the file.
         */
        void setBibFile(const std::string &bibFile, bool useExternalFile = true)
        {
            m_bibFile = bibFile;
            m_useExternalFile = useExternalFile;
        }

        /**
         * @brief Add a bibliography entry manually
         * @param entry Bibliography entry
         */
        void addEntry(const BibEntry &entry)
        {
            m_entries.push_back(entry);
            m_useExternalFile = false; // Use manual entries
        }

        /**
         * @brief Set the bibliography style
         * @param style Bibliography style
         */
        void setStyle(BibStyle style)
        {
            m_style = style;
            if (style != BibStyle::CUSTOM)
            {
                m_customStyle = "";
            }
        }

        /**
         * @brief Set a custom bibliography style
         * @param customStyle Name of the custom .bst style file (without extension)
         */
        void setCustomStyle(const std::string &customStyle)
        {
            m_style = BibStyle::CUSTOM;
            m_customStyle = customStyle;
        }

        /**
         * @brief Get the .bib file name
         * @return Path to the .bib file (without extension)
         */
        std::string getBibFile() const;

        /**
         * @brief Get configuration commands for the preamble
         * @return String containing LaTeX commands to configure the bibliography
         */
        std::string getPreambleConfig() const;

        /**
         * @brief Get commands to include the bibliography in the document
         * @param title Optional title for the bibliography section (if empty, the default language title is used)
         * @return String containing LaTeX commands to include the bibliography
         */
        std::string getIncludeCommands(const std::string &title = "") const;
        
        /**
         * @brief Generate the .bib file from manual entries
         * @param outputDir Output directory (optional)
         * @return true if the file was created successfully, false otherwise
         */
        bool generateBibFile(const std::string &outputDir = "") const;

    private:
        std::string m_bibFile;
        BibStyle m_style;
        std::string m_customStyle;
        bool m_useExternalFile;
        std::vector<BibEntry> m_entries;

        std::string getStyleName() const;
    };


    /**
     * @brief Reference entry for bibliography
     */
    class BibEntry
    {
    public:
        enum class EntryType
        {
            ARTICLE,
            BOOK,
            INPROCEEDINGS,
            TECHREPORT,
            PHDTHESIS,
            MASTERSTHESIS,
            MISC
        };

        BibEntry(const std::string &key, EntryType type)
            : m_key(key), m_type(type) {}

        void addField(const std::string &field, const std::string &value)
        {
            m_fields[field] = value;
        }

        std::string getKey() const
        {
            return m_key;
        }

        EntryType getType() const
        {
            return m_type;
        }

        const std::map<std::string, std::string> &getFields() const
        {
            return m_fields;
        }

        std::string generate() const;

        static std::string getTypeString(EntryType type);

    private:
        std::string m_key;
        EntryType m_type;
        std::map<std::string, std::string> m_fields;
    };

    

  