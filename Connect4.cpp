#include "graphics.hpp"
#include <iostream>
#include "Connect4.hpp"
using namespace genv;

Connect4::Connect4(int x,int y) {
    gout.open(x,y);
    b=new Board(24,125,420,420);
    turn=1;
    game=true;
}

void Connect4::event_loop() {
    event ev;
    int turn=0;
    while(gin>>ev && game) {
        if(ev.type == ev_mouse&& ev.button == btn_left) {

            for(int i=0; i<b->COLUMNS; i++) {
                if(24+(70*i)<ev.pos_x&&ev.pos_x< 24+70+(70*i)) {
                    if(b->Islegalmove(i)) {
                        b->addGamePiece(i,turn);
                        b->Draw();
                        game=!b->CheckWinner(turn);
                        std::cout<<b->isFull()<<std::endl;
                        turn++;
                        turn%=2;
                    }
                }
            }
        }
    }
}
