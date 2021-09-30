/*
 * Flow control
 *
 * v0.1
 * Author: Dr Darryl Charles
 * Date: Summer 2021
 *
 * Copyright notice: Public Domain
 */

/*
* Referencesss
* https://en.wikipedia.org/wiki/Escape_sequences_in_C
* https://en.cppreference.com/w/cpp/language/ascii
* https://en.wikipedia.org/wiki/ASCII_art
*/

#include <iostream>
#include <fstream>
#include <sstream>

std::string loadAndPrintAsciiv2(std::string fname);
std::string loadAndPrintAsciiv1(std::string fname);

int main()
{
    std::string fileName1 = "eagle.txt";
    std::string fileName2 = "pattern.txt";
    std::string mySignature1 = "";
    std::string mySignature2 = "";

    // Three types of Ascii Art/Signature below

    // R is to indicate a raw set of characters - e.g. ignore control characters.
    std::string signature = R"(
                        __      _
                      o'')}____//
                       `_/      )
                       (_(_/-(_/

                      )";
    
    std::cout << signature << '\n';

    // load and draw ascii art
    mySignature1 = loadAndPrintAsciiv1(fileName2);
    mySignature2 = loadAndPrintAsciiv2(fileName1);
    std::cout << mySignature1 << "\n\n";
    std::cout << mySignature2 << "\n\n";   
}

// Load ascii art from file and show on screen (load string example )
std::string loadAndPrintAsciiv1(std::string fname)
{
    std::string _mySignature;
    std::ifstream inFile;
    inFile.open(fname);

    if (inFile.is_open())
    {
        std::ostringstream fileString;
        fileString << inFile.rdbuf();
        _mySignature = fileString.str();
    }

    return _mySignature;
}

// Load ascii art from file and show on screen - but account for individual escape characters by loading one char at a time (for loop example)
std::string loadAndPrintAsciiv2(std::string fname)
{
    std::string _mySignature;
    std::ifstream inFile;
    inFile.open(fname);
    char temp;

    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            inFile.get(temp);
            // detect escape characters individually
            switch (temp)
            {
            case '\a':  _mySignature += "\\a"; break;
            case '\b':  _mySignature += "\\b"; break;
            case '\f':  _mySignature += "\\f"; break;
                // case '\n':  _mySignature += "\\n"; break;
            case '\r':  _mySignature += "\\r"; break;
            case '\t':  _mySignature += "\\t"; break;
            case '\v':  _mySignature += "\\v"; break;
                //case '\\':  _mySignature += "\\\\"; break;
                //case '\'':  _mySignature += "\\'"; break;
                //case '\"':  _mySignature += "\\\""; break;
            case '\?':  _mySignature += "\\\?"; break;
            default:
                _mySignature += temp; break;
            }
        }
    }
    return _mySignature;
}
                      

