//
//  main.cpp
//  Project 1
//
//  Created by Peter Whitman on 2/14/17.
//  Copyright © 2017 Peter Whitman. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <ctype.h>

using namespace std;

int main(int argc, const char * argv[])
{
    ifstream f;
    f.open(argv[1]);
    
    if(f.is_open() == false) //Checks if the file is open
    {
        cout << ".txt file is not open" << endl;
        cout << endl;
    }
    
    if (f.is_open())
    {
        cout << "Hello! the .txt file is open" << endl;
        cout << endl;
        string story;
        size_t fs;
        f.seekg(0, f.end); // Sends you all the way to the end of the file
        fs = f.tellg(); // Now that you are at the end of the file it tells you where you are in a file or the file size at the end
        f.seekg(0, f.beg); // Goes back to the beginning of the file
        story.resize(fs); // Now that we know the size of the file we can resize a file to that size
        f.read(&story[0], fs);
        f.close();
        
        unordered_map<string, int> m; //A map takes a key and a value pair. In the case of this project the key is the word and the value is its count.
        stringstream ss(story);
        string word;
        int count = 1;
        while (ss.good())
        {
            ss >> word;
            string tmp;
            for (int i = 0; i < word.size(); i++) //
            {
                char c = word[i];
                if ((!isalpha(c))) // Check to see if text is an alpha, if it isn't skip
                {
                    continue;
                }
                else //push all alpha text into string tmp -- convert uppercase characters into lower case characters
                {
                    tmp.push_back(tolower(word[i]));
                }
            }
            count++;
            if (m.find(tmp) == m.end()) // For every clean word in file look to see if the word has been seen before.
            {
                m[tmp] = 1;
            }
            else // If it has, increment its counter
            {
                m[tmp]++;
            }
        }
        
        cout << "Word counter: " << count << endl; //Prints the total number of words
        cout << "Insertion counter: " << m.size() << endl; //Prints the size of the map (the number of unique words)
        for (int i = 2; i < argc; i++)
        {
            cout << "Count of: " << "\"" << argv[i] << "\"" << " is: " << m[argv[i]] << endl; //Prints the number of instances of a specific word
        }
        return 0;
    }
}




