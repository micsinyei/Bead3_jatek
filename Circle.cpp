#include "Circle.hpp"
#include <iostream>
using namespace genv;
Circle::Circle(int x,int y,int rad):Widget(x,y,0,0){
r=rad;
Draw();
}
void Circle::Handle(genv::event ev){

}
void Circle::Draw() const {
int y0=r;
int x0=0;
int p=3-2*r;
while(x0 <= y0)
    {
        gout<<move_to(x+x0,y+y0)<<line_to(x-x0,y+y0)<<dot;
        gout<<move_to(x-x0,y+y0)<<line_to(x+x0,y+y0)<<dot;
        gout<<move_to(x+x0,y-y0)<<line_to(x-x0,y-y0)<<dot;
        gout<<move_to(x-x0,y-y0)<<line_to(x+x0,y-y0)<<dot;

        gout<<move_to(x+y0,y+x0)<<line_to(x-y0,y+x0)<<dot;
        gout<<move_to(x-y0,y+x0)<<line_to(x+y0,y+x0)<<dot;
        gout<<move_to(x+y0,y-x0)<<line_to(x-y0,y-x0)<<dot;
        gout<<move_to(x-y0,y-x0)<<line_to(x+y0,y-x0)<<dot;

        if(p < 0){

            p += 4 * x0++ + 6;
        }else{

            p += 4 * (x0++ - y0--) + 10;

}
    }
}
void Circle::Setx(int newx){
    x=newx;
}
void Circle::Sety(int newy){
    y=newy;
}
