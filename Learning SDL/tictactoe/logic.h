#ifndef _LOGIC__H
#define _LOGIC__H

#define BOARD_SIZE 5
#define EMPTY_CELL ' '
#define O_CELL 'o'
#define X_CELL 'x'

struct Tictactoe{
    char board[BOARD_SIZE][BOARD_SIZE];
    char nextMove = O_CELL;

    void init(){
    for (int i = 0; i < BOARD_SIZE; i++){
            for (int j = 0; j < BOARD_SIZE; j++) board[i][j] = EMPTY_CELL;
    }
    }
    void move(int row, int col){
        if ( row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE){
        board[row][col] = nextMove;
        nextMove = ( nextMove == O_CELL ) ? X_CELL : O_CELL;
    }
    }
};
#endif
