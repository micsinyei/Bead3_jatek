#include "Button.hpp"
#include <iostream>
using namespace genv;
Button::Button(int x, int y, int w, int h, std::string label_i,Icon type):Widget(x,y,w,h) {
    label=label_i;
    i=type;
}
Button::Button(int x, int y, int w, int h,Icon type):Widget(x,y,w,h) {
    i=type;
    //std::cout<<"Gomb const test "<<std::endl;
}
void Button::Draw() const {
    //std::cout<<"draw out"<<std::endl;
    // std::cout<<"draw out"<<i<<std::endl;;

    switch(i) {
    case TEXT: {
        //std::cout<<"text out"<<std::endl;
        int tmp_h=gout.cdescent()-gout.cascent();
        int distance_h=(height-tmp_h)/2;
        gout<<move_to(x,y)<<color(0,128,120)<<box(width,height);
        gout << move_to(x,y+distance_h)<<color(255,255,255)<<text(label);

        break;
    }
    case ARROW_DOWN: {
        gout<<move_to(x,y)<<color(128,0,0)<<box(width,height);
        break;
    }
    case ARROW_UP: {
        gout<<move_to(x,y)<<color(0,122,0)<<box(width,height);
        break;
    }
    }

}

void Button::Action(std::function<void()> Onclick) {
    onclick = Onclick;
}

void Button::Handle(event ev) {

    if (ev.type == ev_mouse&& ev.button == btn_left && Selected(ev.pos_x, ev.pos_y)) {
        //std::cout<<"belép"<<std::endl;
        onclick();
        gout << refresh;
    }
}

void Button::CallAction() const {
    onclick();
}

