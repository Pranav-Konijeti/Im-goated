#include <iostream>
#include <string>
#include "Library.h"

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
