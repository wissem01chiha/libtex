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
