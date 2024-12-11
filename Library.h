#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
using namespace std;

struct Library
{
    int split(string input_string, char separator, string arr[], const int ARR_SIZE);
    int runSpinner(int player_index);
    void printMenu();
    int runMenu(string choice);
};

#endif
