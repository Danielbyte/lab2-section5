// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
   paragraph_.push_back(line);
}

tuple<bool, vector<int>> Paragraph::contains(const Word& search_word) const
{
    auto line_number = vector<int>{};
    bool isFound = false;
    if (paragraph_.empty())
    {
        return {isFound, line_number};
    }

    for (auto i = 0u; i < paragraph_.size(); i++)
    {
        auto lineNumber = i+1; //line numbers start at 1.
        if (paragraph_[i].contains(search_word))
        {
            line_number.push_back(lineNumber);
            isFound = true;
        }
    }

    return {isFound, line_number};
}
