// Ascii_Animation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
* References
* https://en.wikipedia.org/wiki/Escape_sequences_in_C
* https://en.cppreference.com/w/cpp/language/ascii
* https://en.wikipedia.org/wiki/ASCII_art
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>

int main()
{
    char ch = 42;
    std::cout << int(ch) << " is the ASCII code for "<< ch << "\n\n";

    // this uses an Ascii code to print a character or control/escape character
    /*
    for (int iterate = 0; iterate < 96; iterate++)
    {
        std::cout << iterate << " is the ASCII code for " << char(iterate) << "\n";
    }
    */

    std::ifstream dataStream;
    std::string line;
    std::vector<std::vector<std::string> > data;

    dataStream.open("star1.csv");
    if (dataStream.is_open())
    {
        while (std::getline(dataStream, line))
        {
            std::stringstream lineStream(line);
            std::string character;
            std::vector<std::string> parsedRow;
            while (std::getline(lineStream, character, ','))
            {
                parsedRow.push_back(character);
                if (character != "0") std::cout << char(std::stoi(character));
                else std::cout << " ";
            }
            std::cout << std::endl;
            data.push_back(parsedRow);
        }
    }
    printf("done!");
}

