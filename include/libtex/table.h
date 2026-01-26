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

#ifndef LIBTEX_TABLE_H
#define LIBTEX_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

// /**
//      * @brief Class for LaTeX tables
//      */
//     class Table : public Environment
//     {
//     public:
//         Table(const std::vector<std::string> &headers, const std::string &position = "h")
//             : Environment("table"), m_headers(headers)
//         {
//             m_options["position"] = position;
//         }

//         void setCaption(const std::string &caption)
//         {
//             m_caption = caption;
//         }

//         void setLabel(const std::string &label)
//         {
//             m_label = label;
//         }

//         void addRow(const std::vector<std::string> &row)
//         {
//             m_rows.push_back(row);
//         }

//         std::string generate() const override;

//     private:
//         std::vector<std::string> m_headers;
//         std::vector<std::vector<std::string>> m_rows;
//         std::string m_caption;
//         std::string m_label;
//         std::map<std::string, std::string> m_options;
//     };

#ifdef __cplusplus
};
#endif

#endif // LIBTEX_TABLE_H