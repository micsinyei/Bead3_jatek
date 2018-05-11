#include "label.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>
using namespace genv;
using namespace std;

Label::Label(int kx, int ky, int w, int h, string s,Color c):Widget(kx, ky, w, h) {
    text_out =checklength(s);
    activity=c;
}
Label::Label(int kx, int ky, string s):Widget(kx, ky, 0, 0) {
    text_out =s;
    width=gout.twidth(s);
    height=gout.cdescent()+gout.cascent();
}
void Label:: SetText(string s) {
    text_out=checklength(s);
    Draw();
}
string Label:: GetText() const {
//std::cout<<" gettext meghiva "<< text_out<<std::endl;
    return text_out;
}

void Label::Draw() const {
    int tmp_h=gout.cdescent()-gout.cascent();
    int distance_h=(height-tmp_h)/2;
    switch(activity) {
    case inactive: {
        gout<<move_to(x,y)<<color(0,128,120)<<box(width,height);
        gout << move_to(x,y+distance_h)<<color(255,255,255)<<text(text_out);

        break;
    }
    case active: {
        gout<<move_to(x,y)<<color(128,10,0)<<box(width,height);
        gout << move_to(x,y+distance_h)<<color(255,255,255)<<text(text_out);
        break;
    }
    case focused:{
      gout<<move_to(x,y)<<color(34,139,34)<<box(width,height);
        gout << move_to(x,y+distance_h)<<color(255,255,255)<<text(text_out);
        break;
    }
    }

}
void Label:: Handle(genv::event ev) {

}
void Label:: SetActive() {
    activity=active;
}
void Label:: SetNormal() {
    activity=inactive;
}
void Label:: SetFocus() {
    activity=focused;
}
string Label::checklength(string s){
    int st=0;///elso karakter
    int ends=width/8;///utolsó karakter a 8-as egy darab karakter szélessége
    if(gout.twidth(s)>width){
    string tmps=s.substr(st,ends);
    return tmps;
    }else{
        return s;
    }
}
