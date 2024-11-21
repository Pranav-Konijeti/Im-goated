#include "Board.h"


int main(){
    srand(time(0));
    Board board(2,1);
    board.initializeBoard();
    board.displayTrack(0);
    cout << endl;
    board.displayTrack(1);
    cout << endl;
    board.displayTrack(0);
    cout << endl;
    board.displayTrack(1);
    cout << endl;

    return 0;
}
