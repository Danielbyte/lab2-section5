// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

Line::Line(const string& line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
	auto temp = ""s;
	stringstream str(line);
	while (std::getline(str, temp, ' '))
    {
       line_.push_back(temp);
    }

}

bool Line::contains(const Word& search_word) const
{
   if (line_.empty())
   {
       return false;
   }

   for (auto element : line_)
   {
       auto temp = Word{element};
       if(temp == search_word && search_word.isQueryable())
       {return true;}

   }
}
