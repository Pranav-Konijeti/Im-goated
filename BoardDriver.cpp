#include "Board.h"
#include "Tile.h"
#include <iostream>


int main(){
    srand(time(0));
    Board board(2,{1,0});
    board.displayBoard({1,0});

    return 0;
} 
