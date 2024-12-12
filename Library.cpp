// Worked with Eddie Chiu

#include <iostream>
#include <string>
#include "Library.h"
#include "Player.h"
#include "Board.h"

// split function 
int Library::split(string input_string, char separator, string arr[], const int ARR_SIZE){
    int length = input_string.length();
    int start = 0;
    int size = 0;
    int splits = 1;

    if(input_string.empty()){
        return 0;
    }

    for(int i = 0; i < length; i++){
        if(input_string[i] == separator){
            if(size < ARR_SIZE){
                arr[size] = input_string.substr(start, i - start);
                start = i + 1;
                splits++;
                size++;
            }
        }
    }

    if(size < ARR_SIZE){
        arr[size] = input_string.substr(start, length - start);
    }
    
    if(splits > ARR_SIZE){
        return -1;
    }
    return splits;
}

// random number generator between 1 and 6 (spinner)
int Library::runSpinner(int player_index){
    srand(time(0));
    int rNum = rand() % 6 + 1;
    return rNum;
}

// prints menu options
void Library::printMenu(){
    cout << endl << "Main Menu" << endl;
    cout << "Select an option to continue" << endl << endl;
    cout << "1. Check Player Progress: Review Pride Point and Leadership Trait stats." << endl;
    cout << "2. Review Character: Check your character name and age." << endl;
    cout << "3. Check Position: Display board to view current position." << endl;
    cout << "4. Review your Advisor: Check who your current advisor is on the game." << endl;
    cout << "5. Move Forward: For each player's turn, access this option to spin the virtual spinner." << endl;
    cout << endl;
}

// prints the menu and returns the option the player selects
int Library::runMenu(string choice){
    choice = "0";

    while(true){
        printMenu();
        cin >> choice;


        if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5"){
            cout << "Invalid input. Please select a valid option." << endl;
        }else{
            return stoi(choice);
        }
    }
}
