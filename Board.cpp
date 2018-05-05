#include "Board.hpp"
#include "graphics.hpp"
#include <iostream>
#include "Circle.hpp"
using namespace genv;
Board::Board(int kx, int ky, int w, int h):Widget(kx,ky,w,h) {
    std::cout<<"test";
    for(int i=0; i<COLUMNS; i++) {
        for(int j=0; j<ROWS; j++) {
            b[i][j]=3;
        }
    }
    boxsize=70;
    circlesize=boxsize/2-5;
    width=x+7*boxsize;
    //b[0][0]=1;
    //b[6][5]=2;
    Draw();
    std::cout<<"test";
}
void Board::Handle(genv::event ev) {
    /*
      for(int i=0;i<7;i++){

            if(x+(boxsize*i)<ev.pos_x&&ev.pos_x< x+boxsize+(boxsize*i)){
            gout<<move_to(x,y-boxsize)<<color(0,0,0)<<box(width,boxsize);
            std::cout<<width+x<<" "<<ev.pos_x<<std::endl;
                gout<<move_to(x+(boxsize*i),y-boxsize)<<color(0,0,0)<<box(boxsize,boxsize);
                gout <<color(255,255,255);
                Circle(x+boxsize/2+(boxsize*i),y-boxsize+boxsize/2,circlesize);
            }
        }
        // mouse_x>x && mouse_x<x+width && mouse_y>y && mouse_y<y+height;
        //ev.pos_x, ev.pos_y*/
}
void Board::Draw() const {
    std::cout<<"test";
    gout<<color(255,255,255);
    for(int i=0; i<7; i++) {
        for(int j=0; j<6; j++) {
            if( b[i][j]==3) {
                gout<<move_to(x+(boxsize*i),y+(boxsize*j))<<color(0,0,204)<<box(boxsize,boxsize);
                gout <<color(255,255,255);
                Circle(x+boxsize/2+(boxsize*i),y+boxsize/2+(boxsize*j),circlesize);
            } else if( b[i][j]==1) {
                gout<<move_to(x+(boxsize*i),y+(boxsize*j))<<color(0,0,204)<<box(boxsize,boxsize);
                gout <<color(228,0,0);
                Circle(x+boxsize/2+(boxsize*i),y+boxsize/2+(boxsize*j),circlesize);
            } else if( b[i][j]==0) {
                gout<<move_to(x+(boxsize*i),y+(boxsize*j))<<color(0,0,204)<<box(boxsize,boxsize);
                gout <<color(255,255,0);
                Circle(x+boxsize/2+(boxsize*i),y+boxsize/2+(boxsize*j),circlesize);
            }


        }
    }

}
void Board::addGamePiece(const int col, const int gamePiece) {
    int ind=ROWS-1;
    while(b[col][ind]!=3) {
        ind--;
    }
    if(ind<0) {
        std::cout<<"egg are not supposed to be green"<<std::endl;
    } else {
        b[col][ind]=gamePiece;
    }
}
bool Board::CheckWinner(int turn) {
///vertical
    for(int i=0; i<COLUMNS-4; i++) {
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
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
