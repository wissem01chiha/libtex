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

#ifndef TEX_BIBLIOGRAPHY_H
#define TEX_BIBLIOGRAPHY_H

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct tex_bibliography tex_bibliography;

  int bibliography_create (tex_bibliography **bibliography,
                           const char *bib_file, int style,
                           const char *custom_style, int err);
  int bibliography_delete (tex_bibliography *bibliography);

  int bibliography_set_bib_file (tex_bibliography *bibliography,
                                 const char *bib_file, int use_external_file);
  int bibliography_add_entry (tex_bibliography *bibliography,
                              const char *entry_type, const char *key,
                              const char **fields, const char **values,
                              size_t field_count);
  int bibliography_set_style (tex_bibliography *bibliography, int style);
  int bibliography_set_custom_style (tex_bibliography *bibliography,
                                     const char *custom_style);
  int bibliography_generate (tex_bibliography *bibliography,
                             const char *output_dir);

#ifdef __cplusplus
};
#endif

#endif // TEX_BIBLIOGRAPHY_H

//      * @brief Class to manage bibliographies in LaTeX documents
//      */
//     class Bibliography
//     {
//     public:
//         /**
//          * @brief Constructor for an external .bib file
//          * @param bibFile Path to the .bib file (without extension)
//          * @param style Bibliography style
//          */
//         Bibliography(const std::string &bibFile, BibStyle style =
//         BibStyle::PLAIN)
//             : m_bibFile(bibFile), m_style(style), m_customStyle(""),
//             m_useExternalFile(true) {}

//         /**
//          * @brief Default constructor (empty bibliography)
//          */
//         Bibliography()
//             : m_bibFile("references"), m_style(BibStyle::PLAIN),
//             m_customStyle(""), m_useExternalFile(false) {}

//         /**
//          * @brief Constructor for bibliography with custom style
//          * @param bibFile Path to the .bib file (without extension)
//          * @param customStyle Name of the custom .bst style file (without
//          extension)
//          */
//         Bibliography(const std::string &bibFile, const std::string
//         &customStyle)
//             : m_bibFile(bibFile), m_style(BibStyle::CUSTOM),
//             m_customStyle(customStyle), m_useExternalFile(true) {}

//         /**
//          * @brief Set the .bib file
//          * @param bibFile Path to the .bib file (without extension)
//          * @param useExternalFile If true, use an existing file. If false,
//          generate the file.
//          */
//         void setBibFile(const std::string &bibFile, bool useExternalFile =
//         true)
//         {
//             m_bibFile = bibFile;
//             m_useExternalFile = useExternalFile;
//         }

//         /**
//          * @brief Add a bibliography entry manually
//          * @param entry Bibliography entry
//          */
//         void addEntry(const BibEntry &entry)
//         {
//             m_entries.push_back(entry);
//             m_useExternalFile = false; // Use manual entries
//         }

//         /**
//          * @brief Set the bibliography style
//          * @param style Bibliography style
//          */
//         void setStyle(BibStyle style)
//         {
//             m_style = style;
//             if (style != BibStyle::CUSTOM)
//             {
//                 m_customStyle = "";
//             }
//         }

//         /**
//          * @brief Set a custom bibliography style
//          * @param customStyle Name of the custom .bst style file (without
//          extension)
//          */
//         void setCustomStyle(const std::string &customStyle)
//         {
//             m_style = BibStyle::CUSTOM;
//             m_customStyle = customStyle;
//         }

//         /**
//          * @brief Get the .bib file name
//          * @return Path to the .bib file (without extension)
//          */
//         std::string getBibFile() const;

//         /**
//          * @brief Get configuration commands for the preamble
//          * @return String containing LaTeX commands to configure the
//          bibliography
//          */
//         std::string getPreambleConfig() const;

//         /**
//          * @brief Get commands to include the bibliography in the document
//          * @param title Optional title for the bibliography section (if
//          empty, the default language title is used)
//          * @return String containing LaTeX commands to include the
//          bibliography
//          */
//         std::string getIncludeCommands(const std::string &title = "") const;

//         /**
//          * @brief Generate the .bib file from manual entries
//          * @param outputDir Output directory (optional)
//          * @return true if the file was created successfully, false otherwise
//          */
//         bool generateBibFile(const std::string &outputDir = "") const;

//     private:
//         std::string m_bibFile;
//         BibStyle m_style;
//         std::string m_customStyle;
//         bool m_useExternalFile;
//         std::vector<BibEntry> m_entries;

//         std::string getStyleName() const;
//     };

//     /**
//      * @brief Reference entry for bibliography
//      */
//     class BibEntry
//     {
//     public:
//         enum class EntryType
//         {
//             ARTICLE,
//             BOOK,
//             INPROCEEDINGS,
//             TECHREPORT,
//             PHDTHESIS,
//             MASTERSTHESIS,
//             MISC
//         };

//         BibEntry(const std::string &key, EntryType type)
//             : m_key(key), m_type(type) {}

//         void addField(const std::string &field, const std::string &value)
//         {
//             m_fields[field] = value;
//         }

//         std::string getKey() const
//         {
//             return m_key;
//         }

//         EntryType getType() const
//         {
//             return m_type;
//         }

//         const std::map<std::string, std::string> &getFields() const
//         {
//             return m_fields;
//         }

//         std::string generate() const;

//         static std::string getTypeString(EntryType type);

//     private:
//         std::string m_key;
//         EntryType m_type;
//         std::map<std::string, std::string> m_fields;
//     };
