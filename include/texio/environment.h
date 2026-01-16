 /**
     * @brief Base class for LaTeX environment
     */
    class Environment
    {
    public:
        Environment(const std::string &name) : m_name(name) {}
        virtual ~Environment() = default;

        virtual std::string begin() const
        {
            return "\\begin{" + m_name + "}\n";
        }

        virtual std::string end() const
        {
            return "\\end{" + m_name + "}\n";
        }

        virtual std::string generate() const = 0;

    protected:
        std::string m_name;
    };