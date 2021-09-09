// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <string>
#include <algorithm>

using std::string;

Word::Word(const string& word): word_{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (word_.empty()) throw WordContainsNoLetters{};

	// make word object case insensitive by converting every character
	// to a lower case
	transform(word_.begin(), word_.end(), word_.begin(), ::tolower);

	//ignore punctuations in word object
      remove_punctuation();

      //word object cannot be only punctuations
      unsigned long number_of_charsIn_wordObject = count_if(word_.begin(), word_.end(), ::ispunct);

      if (number_of_charsIn_wordObject == word_.size()) throw WordContainsNoLetters{};

      //word object cannot contain a space
      char space = ' ';
      auto number_of_spaces = count(word_.begin(), word_.end(), space);
      if (number_of_spaces > 0) throw WordContainsSpace{};

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	if (word_ == rhs.word_)
		return true;
	else
		return false;
}

bool Word::isQueryable() const
{
    auto word_length = word_.size();
    if (word_length >= 3)
    {
        return true;
    }
    else
	return false;
}

void Word::remove_punctuation()
{
      for(int i=0,length=word_.size(); i<length; i++)
    {
        if (ispunct(word_[i]))//if character is a punctuation,remove it
        {
            word_.erase(i--,1); //post decrement i to make it correspond to decreased word size
            length=word_.size();
        }
    }
}
