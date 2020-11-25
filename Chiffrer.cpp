// Chiffrer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <cctype>
//#define BASE_ALPHABET 65
//#define BASE_NUMBER 48
using namespace std;


int main()
{
    map<char, int> ALPHABET;
    map<char, int> NUMBERS;
    string sample = "Hello World";
    string output = "";
    char b;
    unsigned int rotation = 32;
    unsigned int shift = rotation % 26;
    unsigned int shiftnum = rotation % 10;
    map<char, int>::iterator pos;
    const int BASE_ALPHABET = 65;
    const int BASE_NUMBER = 48;

    
    //Setup the Alphabet
    for(unsigned int i = 0; i < 26; i++)
        ALPHABET.insert(make_pair((char)BASE_ALPHABET + i, i));

    for (unsigned int i = 0; i < 10; i++)
        NUMBERS.insert(make_pair((char)BASE_NUMBER + i, i));
    
    for (unsigned int a = 0; a < sample.length(); a++)
    {
        pos = ALPHABET.find(sample.c_str()[a]);
        if (pos != ALPHABET.end())
        {
            b = (char)(BASE_ALPHABET + ((pos->second + shift > 25) ? (pos->second + shift) - 25 : (pos->second + shift)));
            output += b;
            continue;
        }

        pos = ALPHABET.find((char)toupper(sample.c_str()[a]));
        if (pos != ALPHABET.end())
        {
            b = (char)(BASE_ALPHABET + ((pos->second + shift > 25) ? (pos->second + shift) - 25 : (pos->second + shift)));
            output += (char)tolower(b);
            continue;
        }

        pos = NUMBERS.find(sample.c_str()[a]);
        if (pos != NUMBERS.end())
        {
            b = (char)(BASE_NUMBER + ((pos->second + shiftnum > 10) ? (pos->second + shiftnum) - 10 : (pos->second + shiftnum)));
            output += b;
            continue;
        }

        pos = ALPHABET.find(sample.c_str()[a]);
        if (pos != ALPHABET.end())
        {
            b = (char)(BASE_ALPHABET + ((pos->second + shift > 25) ? (pos->second + shift) - 25 : (pos->second + shift)));
            output += b;
            continue;
        }
        b = sample.c_str()[a];
        output += b;
    }
    std::cout << output << endl;
}

