#ifndef CONNECT4_HPP_INCLUDED
#define CONNECT4_HPP_INCLUDED
#include "Board.hpp"
#include "graphics.hpp"
class Connect4{
protected:
    Board *b;
    int turn;
    bool game;

public:
    Connect4(int x, int y) ;
    void event_loop() ;
};

#endif // CONNECT4_HPP_INCLUDED
