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

#ifndef ALGORITHM_H
#define ALGORITHM_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char caption;
  char label;
} tex_algorithm;

#ifdef __cplusplus
};
#endif

#endif  // ALGORITHM_H

// class Algorithm : public Environment
// {
// public:
//   /**
//    * @brief Constructor for algorithm environment
//    * @param caption Caption for the algorithm
//    */
//   Algorithm (const std::string &caption = "")
//       : Environment ("algorithm"), m_caption (caption)
//   {
//   }

//   /**
//    * @brief Set the caption of the algorithm
//    * @param caption Caption of the algorithm
//    */
//   void
//   setCaption (const std::string &caption)
//   {
//     m_caption = caption;
//   }

//   /**
//    * @brief Set the label of the algorithm
//    * @param label Label of the algorithm
//    */
//   void
//   setLabel (const std::string &label)
//   {
//     m_label = label;
//   }

//   /**
//    * @brief Add a line of pseudocode to the algorithm
//    * @param line Line of pseudocode
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addLine (const std::string &line, int indent = 0)
//   {
//     m_lines.push_back ({ line, indent });
//   }

//   /**
//    * @brief Add a comment line to the algorithm
//    * @param comment Comment text
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addComment (const std::string &comment, int indent = 0)
//   {
//     m_lines.push_back ({ "\\" + std::string (indent > 0 ? ">\\" : "")
//                              + "Comment{" + comment + "}",
//                          indent });
//   }

//   /**
//    * @brief Add a for loop to the algorithm
//    * @param condition Loop condition
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addForLoop (const std::string &condition, int indent = 0)
//   {
//     m_lines.push_back ({ "\\For{" + condition + "}", indent });
//     // m_lines.push_back({"\\Do", indent});
//   }

//   /**
//    * @brief Add a while loop to the algorithm
//    * @param condition Loop condition
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addWhileLoop (const std::string &condition, int indent = 0)
//   {
//     m_lines.push_back ({ "\\While{" + condition + "}", indent });
//     // m_lines.push_back({"\\Do", indent});
//   }

//   /**
//    * @brief Add an if statement to the algorithm
//    * @param condition If condition
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addIf (const std::string &condition, int indent = 0)
//   {
//     m_lines.push_back ({ "\\If{" + condition + "}", indent });
//     // m_lines.push_back({"\\Then", indent});
//   }

//   /**
//    * @brief Add an else statement to the algorithm
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addElse (int indent = 0)
//   {
//     m_lines.push_back ({ "\\Else", indent });
//   }

//   /**
//    * @brief Add an else if statement to the algorithm
//    * @param condition Else if condition
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addElseIf (const std::string &condition, int indent = 0)
//   {
//     m_lines.push_back ({ "\\ElsIf{" + condition + "}", indent });
//     // m_lines.push_back({"\\Then", indent});
//   }

//   /**
//    * @brief Add an end statement to the algorithm (for closing loops, if
//    * statements, etc.)
//    * @param statement Type of statement to end (e.g., "For", "If", "While")
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addEnd (const std::string &statement, int indent = 0)
//   {
//     m_lines.push_back ({ "\\End" + statement, indent });
//   }

//   /**
//    * @brief Add a return statement to the algorithm
//    * @param value Return value
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addReturn (const std::string &value, int indent = 0)
//   {
//     m_lines.push_back ({ "\n\\Return{" + value + "}", indent });
//   }

//   /**
//    * @brief Add a break statement to the algorithm
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addBreak (int indent = 0)
//   {
//     m_lines.push_back ({ "\\Break", indent });
//   }
//   /**
//    * @brief Add a continue statement to the algorithm
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addContinue (int indent = 0)
//   {
//     m_lines.push_back ({ "\\Continue", indent });
//   }

//   /**
//    * @brief Add a function definition to the algorithm
//    * @param name Function name
//    * @param args Function arguments
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addFunction (const std::string &name, const std::string &args, int indent = 0)
//   {
//     m_lines.push_back ({ "\\Function{" + name + "}(" + args + ")", indent });
//     // m_lines.push_back({"\\Do", indent});
//   }
//   /**
//    * @brief Add a function end statement to the algorithm
//    * @param indent Indentation level (0 = no indent)
//    */
//   void
//   addFunctionEnd (int indent = 0)
//   {
//     m_lines.push_back ({ "\\EndFunction", indent });
//   }

//   /**
//    * @brief Generate LaTeX code for the algorithm environment
//    * @return String containing LaTeX code
//    */
//   std::string generate () const override;

//   /**
//    * @brief Get the algorithm package inclusion commands for document preamble
//    * @return String containing LaTeX commands for algorithm package setup
//    */
//   static std::string getAlgorithmPackages ();

// private:
//   std::string m_caption;
//   std::string m_label;
//   std::vector<std::pair<std::string, int> >
//       m_lines; // Line content, indentation level
// };
