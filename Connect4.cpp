#include <iostream>
#include <string>
#include "Connect4.hpp"
using namespace genv;

Connect4::Connect4(int x,int y) {
    ///ablak megnyitása
    gout.open(x,y);
    ///Pálya
    b=new Board(10,50,420,420);
    gameOver=false;
    exit=false;
    ///gombok
    b_exit= new Button(510,450,80,20,"Kilepes",TEXT);
    newgame=new Button(510,50,80,20,"Uj jatek",TEXT);
    b_exit->Draw();
    newgame->Draw();
    ///kilépés
    b_exit->Action([this]() {
        exit=true;

    });
    ///uj jatek
    newgame->Action([this]() {
        gout<<move_to(0,0)<<color(0,0,0)<<box_to(559,479);
        turn=0;
        gameOver=false;
        b->initBoard();
        b->Draw();
        newgame->Draw();
        b_exit->Draw();
        player1->Draw();
        player2->Draw();
        gout<<refresh;
    });
    ///labels
    player1= new Label(10,10,100,20,"Jatekos 1.",inactive);
    player2= new Label(400,10,100,20,"Jatekos 2.",inactive);
    eredmeny = new Label(155,10,200,20,"A gyoztes",inactive);
    player1->Draw();
    player2->Draw();
    gout << refresh;
}

void Connect4::event_loop() {

    event ev;
    while(gin>>ev && exit ==false) {
        ///gombok handlerje
        b_exit->Handle(ev);
        newgame->Handle(ev);
        if(turn==0) {
            player2->SetNormal();
            player1->SetFocus();
        } else {
            player1->SetNormal();
            player2->SetFocus();
        }
        player1->Draw();
        player2->Draw();
        gout<< refresh;
        ///egér lenyomása
        if(ev.type == ev_mouse&& ev.button == btn_left) {
            while(gameOver==false) {

                ///melyik oszlop felett van
                for(int i=0; i<b->COLUMNS; i++) {
                    if(24+(70*i)<ev.pos_x&&ev.pos_x< 24+70+(70*i)) {
                        ///lehet-e abba az oszlopba tenni
                        if(b->Islegalmove(i)) {
                            b->addGamePiece(i,turn);
                            b->Draw();
                            ///ha betelt a tabla
                            if(b->isFull()) {
                                gameOver=true;
                                eredmeny->SetText("Dontetlen");
                                eredmeny->Draw();
                            }
                            /// valaki nyert
                            if(b->CheckWinner(turn)) {
                                gameOver=true;
                                winner=turn;
                                eredmeny->SetText("A gyoztes ");
                                eredmeny->Draw();

                            }
                            /// következő jatekos
                            turn++;
                            turn%=2;
                            gout << refresh;
                        }
                    }
                }
                break; /// ki lépjünk ciklusból
            }
        }
        if(ev.type==ev_key) {
            //std::cout<<ev.keycode<<std::endl;
            if(ev.keycode==key_escape) {
                b_exit->CallAction();
                break;
            } else if(ev.keycode==114) {
                newgame->CallAction();
            }
        }
    }
}
