#include "Circle.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
Circle::Circle(int x,int y,int rad):Widget(x,y,0,0){
r=rad;
y0=r;
x0=0;
p=3-2*r;
Draw();
}
void Circle::Handle(genv::event ev){

}
void Circle::Draw() const {
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
    gout<< refresh;
}
