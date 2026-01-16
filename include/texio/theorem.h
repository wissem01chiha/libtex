
    /**
     * @brief Class for mathematical theorem environments
     */
    class TheoremEnvironment : public Environment
    {
    public:
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

        /**
         * @brief Constructor for theorem environment
         * @param type Type of theorem environment
         * @param content Content of the theorem
         * @param title Optional title for the theorem
         */
        TheoremEnvironment(Type type, const std::string &content, const std::string &title = "")
            : Environment(getEnvironmentName(type)), m_type(type), m_content(content), m_title(title), m_customType("") {}

        /**
         * @brief Constructor for custom theorem environment
         * @param customType Name of the custom theorem environment
         * @param content Content of the theorem
         * @param title Optional title for the theorem
         */
        TheoremEnvironment(const std::string &customType, const std::string &content, const std::string &title = "")
            : Environment(customType), m_type(Type::CUSTOM), m_content(content), m_title(title), m_customType(customType) {}

        /**
         * @brief Set the content of the theorem
         * @param content Content of the theorem
         */
        void setContent(const std::string &content)
        {
            m_content = content;
        }

        /**
         * @brief Set the title of the theorem
         * @param title Title of the theorem
         */
        void setTitle(const std::string &title)
        {
            m_title = title;
        }

        /**
         * @brief Generate LaTeX code for the theorem environment
         * @return String containing LaTeX code
         */
        std::string generate() const override;

        /**
         * @brief Get the theorem environment setup for document preamble
         * @param language The document language for localization
         * @return String containing LaTeX commands for theorem environment setup
         */
        static std::string getTheoremSetup(Language language = Language::ENGLISH);

    private:
        Type m_type;
        std::string m_content;
        std::string m_title;
        std::string m_customType;

        static std::string getEnvironmentName(Type type);
    };
