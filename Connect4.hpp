#ifndef CONNECT4_HPP_INCLUDED
#define CONNECT4_HPP_INCLUDED
#include "Board.hpp"
#include "graphics.hpp"
#include "Button.hpp"
#include "label.hpp"
class Connect4{
protected:
    Board *b;
    bool exit;
    Button *b_exit;
    Button *newgame;
    Label *player1;
    Label *player2;
    Label *eredmeny;

    int turn =0;
    int winner;
    bool foundWinner = false;
    bool gameOver = false;
    public:
    bool isWinnerFound() { return foundWinner; }
    bool isGameOver() { return gameOver; }
    Connect4(int x, int y) ;
    void event_loop() ;
};

#endif // CONNECT4_HPP_INCLUDED
