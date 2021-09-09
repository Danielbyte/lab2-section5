#include "Word.h"
#include "Line.h"
#include "Paragraph.h"
#include "FileReader.h"
#include <iostream>
#include <string>
#include <vector>

//Exercise 5.4

int main()
{
    //string that will contain file name to be opened
    auto fileName=""s;

    cout<<"Please enter file name: ";
    cin>>fileName;
    auto file_reader = FileReader{fileName};
    auto _paragraph = Paragraph{};
    file_reader.readFileInto(_paragraph);


    auto _searchWord="random"s;
    while(_searchWord!=".")
    {
        cout<< "Please enter a word to search for or \".\" to quit: ";

        cin>>_searchWord;
        cout<<endl;

        if(_searchWord!=".")
        {
            auto[found, line_numbers] = _paragraph.contains(Word{_searchWord});

            if(found)
            {
                cout<<"Word found: ";

                //dummy variable to help output line numbers in columns
                auto dummy=0;

                for(const auto& i: line_numbers)
                {
                    if(dummy == 0)
                    {
                        cout<<"line "<<i<<endl;
                        dummy++;
                    }
                    else
                        cout<<"            line "<<i<<endl;
                }
                //dummy=0;
            }

            else
                cout<<"Word not found"<<endl;
        }
        cout<<endl;
    }

    return 0;

}

//If a word appears twice in a line, the design would still return the line number at which
//those two words appear. The only short coming is that it may not output the number of times
//at which the word appears. to improve this, a separate vector/variable could be implemented in the
//paragraph class to store the number of times a word appears. This means that the tuple
//function would now return three values, that is :if word is found,line number and number of times
//particular word appears.

