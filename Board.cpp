#include "Board.hpp"
#include "graphics.hpp"
#include <iostream>
#include "Circle.hpp"
using namespace genv;
Board::Board(int x, int y, int w, int h):Widget(x,y,w,h){
    for(int i=0;i<7;i++){
        for(int j=0;j<6;j++){
            b[i][j]=0;
        }
    }
    boxsize=70;
    circlesize=boxsize/2-5;
    //b[0][0]=1;
    //b[6][5]=2;

}
void Board::Handle(genv::event ev){
  for(int i=0;i<7;i++){
  gout<<move_to(x,y-boxsize)<<color(0,0,0)<<box(width,boxsize);
        if(x+(boxsize*i)<ev.pos_x&&ev.pos_x< x+boxsize+(boxsize*i)){
            gout<<move_to(x+(boxsize*i),y-boxsize)<<color(0,0,0)<<box(boxsize,boxsize);
            gout <<color(255,255,255);
            Circle(x+boxsize/2+(boxsize*i),y-boxsize+boxsize/2,circlesize);
        }
    }
    // mouse_x>x && mouse_x<x+width && mouse_y>y && mouse_y<y+height;
    //ev.pos_x, ev.pos_y
}
void Board::Draw() const {

gout<<color(255,255,255);
for(int i=0;i<7;i++){
        for(int j=0;j<6;j++){
            if( b[i][j]==0){
                gout<<move_to(x+(boxsize*i),y+(boxsize*j))<<color(0,0,204)<<box(boxsize,boxsize);
                gout <<color(255,255,255);
                Circle(x+boxsize/2+(boxsize*i),y+boxsize/2+(boxsize*j),circlesize);
            }else if( b[i][j]==1){
                gout<<move_to(x+(boxsize*i),y+(boxsize*j))<<color(0,0,204)<<box(boxsize,boxsize);
                gout <<color(228,0,0);
                Circle(x+boxsize/2+(boxsize*i),y+boxsize/2+(boxsize*j),circlesize);
            } else if( b[i][j]==2){
                 gout<<move_to(x+(boxsize*i),y+(boxsize*j))<<color(0,0,204)<<box(boxsize,boxsize);
                gout <<color(255,255,0);
                Circle(x+boxsize/2+(boxsize*i),y+boxsize/2+(boxsize*j),circlesize);
            }


        }
    }

}
void Board::SetBoard(int col,int row,int v){
    b[col][row]=v;
}
