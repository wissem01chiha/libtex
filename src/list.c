#include "libtex.h"



// /**
//      * @brief Class for LaTeX itemize and enumerate environments
//      */
//     class List : public Environment
//     {
//     public:
//         enum class ListType
//         {
//             ITEMIZE,
//             ENUMERATE,
//             DESCRIPTION
//         };

//         List(ListType type = ListType::ITEMIZE)
//             : Environment(type == ListType::ITEMIZE ? "itemize" : type == ListType::ENUMERATE ? "enumerate"
//                                                                                               : "description"),
//               m_type(type) {}

//         void addItem(const std::string &item, const std::string &label = "")
//         {
//             m_items.push_back(item);
//             if (!label.empty())
//             {
//                 m_itemLabels[m_items.size() - 1] = label;
//             }
//         }

//         std::string generate() const override;

//     private:
//         ListType m_type;
//         std::vector<std::string> m_items;
//         std::map<size_t, std::string> m_itemLabels; // For description lists
//     };

tex_list *list_create(tex_list_t type, int err)
{
    return NULL;
}

int list_delete(tex_list *lst)
{
    return 0;
}
