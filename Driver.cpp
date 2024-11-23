#include "Board.h"
#include "Tile.h"
#include <iostream>


int main(){
    srand(time(0));
    Board board(2,{0,1});
    board.displayBoard({0,1});
    cout << endl;
    board.movePlayer(0,0);
    board.displayBoard({0,1});
    return 0;
} 
