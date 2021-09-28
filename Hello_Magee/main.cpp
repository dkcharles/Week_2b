/*
 * Hello World main.cpp     
 *
 * v0.1                     
 * Author: Dr Darryl Charles
 * Date: Summer 2021
 *
 * Copyright notice: Public Domain 
 */

#include <iostream>
using namespace std; // string and cout are part of the std (standard) namespace

int main()
{
    string name;
    string helloMessage = "Hello, there!! What is your first name?\n";
    string personalMessage = "It's nice to meet you ";
    
    cout << helloMessage;
    cin >> name;
    cout << personalMessage << name << "\n\n";
    cout << "The first letter in your name is " << name[0] << "\n\n";
    cout << "Your name has " << name.length() << " letters in it" << "\n\n";

    /*
    try the following instead of plain cin - what is the difference? 
    char input[100];
    cin.getline(input,sizeof(input));
    */
}
