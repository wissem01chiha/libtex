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

// /**
//      * @brief Class to represent a document template
//      */
//     class DocumentTemplate
//     {
//     public:
//         /**
//          * @brief Constructor for document template
//          * @param name Name of the template
//          */
//         DocumentTemplate(const std::string &name) : m_name(name) {}

//         /**
//          * @brief Add a package to the template
//          * @param package Package name
//          * @param options Package options
//          */
//         void addPackage(const std::string &package, const std::string &options = "")
//         {
//             m_packages[package] = options;
//         }

//         /**
//          * @brief Add custom preamble content to the template
//          * @param content Preamble content
//          */
//         void addPreambleContent(const std::string &content)
//         {
//             m_preambleContent.push_back(content);
//         }

//         /**
//          * @brief Set page geometry
//          * @param options Geometry options (e.g., "margin=1in")
//          */
//         void setGeometry(const std::string &options)
//         {
//             m_geometry = options;
//         }

//         /**
//          * @brief Set header and footer style
//          * @param style Header/footer style (e.g., "fancy")
//          */
//         void setHeaderFooterStyle(const std::string &style)
//         {
//             m_headerFooterStyle = style;
//         }

//         /**
//          * @brief Set header content
//          * @param left Left header content
//          * @param center Center header content
//          * @param right Right header content
//          */
//         void setHeader(const std::string &left, const std::string &center, const std::string &right)
//         {
//             m_headerLeft = left;
//             m_headerCenter = center;
//             m_headerRight = right;
//         }

//         /**
//          * @brief Set footer content
//          * @param left Left footer content
//          * @param center Center footer content
//          * @param right Right footer content
//          */
//         void setFooter(const std::string &left, const std::string &center, const std::string &right)
//         {
//             m_footerLeft = left;
//             m_footerCenter = center;
//             m_footerRight = right;
//         }

//         /**
//          * @brief Apply template to a document
//          * @param doc Document to apply template to
//          */
//         template <typename T>
//         void applyTo(T &doc) const
//         {
//             // Add packages
//             for (const auto &package : m_packages)
//             {
//                 doc.addPackage(package.first, package.second);
//             }

//             // Add geometry if specified
//             if (!m_geometry.empty())
//             {
//                 doc.addPackage("geometry", m_geometry);
//             }

//             // Add header/footer if specified
//             if (!m_headerFooterStyle.empty())
//             {
//                 doc.addPackage("fancyhdr");
//                 std::stringstream headerFooterConfig;
                
//                 // Define \thetitle and \theauthor commands if they do not exist
//                 headerFooterConfig << "\\providecommand{\\thetitle}{" << doc.getTitle() << "}\n";
//                 headerFooterConfig << "\\providecommand{\\theauthor}{" << doc.getAuthor() << "}\n";
//                 headerFooterConfig << "\\pagestyle{" << m_headerFooterStyle << "}\n";

//                 if (!m_headerLeft.empty() || !m_headerCenter.empty() || !m_headerRight.empty())
//                 {
//                     headerFooterConfig << "\\lhead{" << m_headerLeft << "}\n";
//                     headerFooterConfig << "\\chead{" << m_headerCenter << "}\n";
//                     headerFooterConfig << "\\rhead{" << m_headerRight << "}\n";
//                 }

//                 if (!m_footerLeft.empty() || !m_footerCenter.empty() || !m_footerRight.empty())
//                 {
//                     headerFooterConfig << "\\lfoot{" << m_footerLeft << "}\n";
//                     headerFooterConfig << "\\cfoot{" << m_footerCenter << "}\n";
//                     headerFooterConfig << "\\rfoot{" << m_footerRight << "}\n";
//                 }

//                 doc.addInPreamble(headerFooterConfig.str());
//             }

//             // Add custom preamble content
//             for (const auto &content : m_preambleContent)
//             {
//                 doc.addInPreamble(content);
//             }
//         }

//         /**
//          * @brief Get the name of the template
//          * @return Name of the template
//          */
//         std::string getName() const
//         {
//             return m_name;
//         }

//     private:
//         std::string m_name;
//         std::map<std::string, std::string> m_packages;
//         std::vector<std::string> m_preambleContent;
//         std::string m_geometry;
//         std::string m_headerFooterStyle;
//         std::string m_headerLeft;
//         std::string m_headerCenter;
//         std::string m_headerRight;
//         std::string m_footerLeft;
//         std::string m_footerCenter;
//         std::string m_footerRight;
//     };