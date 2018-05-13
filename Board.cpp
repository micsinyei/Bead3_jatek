#include "Board.hpp"
#include <iostream>
using namespace genv;
Board::Board(int kx, int ky, int w, int h):Widget(kx,ky,w,h) {
    initBoard();
    boxsize=70; ///egy darab negyzet merete
    circlesize=boxsize/2-5; /// a kor beleferjen a nyeztebe
    width=x+7*boxsize; ///szelesseg a dobozok alapjan
    Draw();
}
void Board::initBoard(){
    /// Board feltoltese 3-sokkal mivel a jatekos majd 0 és 1 lesz
    for(int i=0; i<COLUMNS; i++) {
        for(int j=0; j<ROWS; j++) {
            b[i][j]=3;
        }
    }

}
void Board::Handle(genv::event ev) {

     /* for(int i=0;i<7;i++){

            if(x+(boxsize*i)<ev.pos_x&&ev.pos_x< x+boxsize+(boxsize*i)){
            gout<<move_to(x,y-boxsize)<<color(0,0,0)<<box(width,boxsize);
                if( player==1) {
                gout<<move_to(x+(boxsize*i),y-boxsize)<<color(0,0,0)<<box(boxsize,boxsize);
                gout <<color(228,0,0);
                Circle(x+boxsize/2+(boxsize*i),y-boxsize+boxsize/2,circlesize);
            } else if( player==0) {
                gout<<move_to(x+(boxsize*i),y-boxsize)<<color(0,0,0)<<box(boxsize,boxsize);
                gout <<color(255,255,0);
                Circle(x+boxsize/2+(boxsize*i),y-boxsize+boxsize/2,circlesize);
            }

            }
        }
        // mouse_x>x && mouse_x<x+width && mouse_y>y && mouse_y<y+height;
        //ev.pos_x, ev.pos_y*/
}
void Board::Draw() const {
    gout<<color(255,255,255);
    for(int i=0; i<7; i++) {
        for(int j=0; j<6; j++) {
        ///ha üres
            if( b[i][j]==3) {
                gout<<move_to(x+(boxsize*i),y+(boxsize*j))<<color(0,0,204)<<box(boxsize,boxsize);
                gout <<color(255,255,255);
                Circle(x+boxsize/2+(boxsize*i),y+boxsize/2+(boxsize*j),circlesize);
            } else if( b[i][j]==0) {/// egyik játékos
                gout<<move_to(x+(boxsize*i),y+(boxsize*j))<<color(0,0,204)<<box(boxsize,boxsize);
                gout <<color(228,0,0);
                Circle(x+boxsize/2+(boxsize*i),y+boxsize/2+(boxsize*j),circlesize);
            } else if( b[i][j]==1) {/// másik jatekos
                gout<<move_to(x+(boxsize*i),y+(boxsize*j))<<color(0,0,204)<<box(boxsize,boxsize);
                gout <<color(255,255,0);
                Circle(x+boxsize/2+(boxsize*i),y+boxsize/2+(boxsize*j),circlesize);
            }


        }
    }

}
void Board::addGamePiece(const int col, const int gamePiece) {
    int ind=ROWS-1;
    /// kovetkezo ures helyre teszi
    while(b[col][ind]!=3) {
        ind--;
    }
    b[col][ind]=gamePiece;

}
bool Board::CheckWinner(int turn) {

///vertical
    for(int i=0; i<COLUMNS-3; i++) {
        for(int j=0; j<ROWS; j++) {
            if(b[i][j]==turn) {
                if(b[i+1][j]==turn) {
                    if(b[i+2][j]==turn) {
                        if(b[i+3][j]==turn) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    ///horizontal
    for(int i=0; i<COLUMNS; i++) {
        for(int j=0; j<ROWS-3; j++) {
            if(b[i][j]==turn) {
                if(b[i][j+1]==turn) {
                    if(b[i][j+2]==turn) {
                        if(b[i][j+3]==turn) {
                            return true;;
                        }
                    }
                }
            }
        }
    }
    ///diag up left to right down
    for (int row=0; row<ROWS-3; row++) {
        for(int col=0; col<COLUMNS-3; col++) {
            if(b[col][row]==turn &&
                b[col+1][row+1]==turn &&
                b[col+2][row+2]==turn &&
                b[col+3][row+3]==turn
             ){return true;}
        }
    }
    ///diag up right to left down
    for (int row=0; row<ROWS-3; row++) {
        for(int col=COLUMNS-1; col>2; col--) {
            if(b[col][row]==turn &&
                b[col-1][row+1]==turn &&
                b[col-2][row+2]==turn &&
                b[col-3][row+3]==turn
             ){
             return true;
             }
        }
    }



    return false;
}
bool Board::Islegalmove(int col) {
    /// az oszlop nem telt-e be
   /* int ind=ROWS-1;
    while(b[col][ind]!=3) {
        ind--;
    }
    if(ind<0) {
        return false;
    } else {
        return true;
    }*/
    if(b[col][0]==3){
        return true;
    }
    else{
        return false;
    }
}

bool Board::isFull() {
/// a board betelt-e

/*int index=0;
    while(b[index][0]!=3){
        index++;
    }
    if(index<COLUMNS){
        return false;
    }
    else{
        return true;
    }*/
    int index=0;
    while(Islegalmove(index)==false){
        index++;
    }
    if(index<COLUMNS){
        return false;
    }
    else{
        return true;
    }
}
