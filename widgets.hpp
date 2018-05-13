#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED
#include "graphics.hpp"

class Widget {
protected:
    int x, y, width, height;
    bool focus;
public:
    Widget(int kx, int ky, int w, int h);
    virtual bool Selected(int mouse_x, int mouse_y);
    virtual void Draw() const = 0;
    virtual void Handle(genv::event ev) =  0;

};


#endif
