#include "widgets.hpp"
#include "graphics.hpp"

using namespace genv;

Widget::Widget(int kx, int ky, int w, int h) {
  x = kx;
  y = ky;
  width = w;
  height = h;
  focus=false;
}

bool Widget::Selected(int mouse_x, int mouse_y) {
    return mouse_x>x && mouse_x<x+width && mouse_y>y && mouse_y<y+height;
}

