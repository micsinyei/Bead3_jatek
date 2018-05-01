#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED
#include "widgets.hpp"

class Circle: public  Widget{
int r;
    mutable int x0,y0,p;
 public:
 Circle(int kx, int ky,int r);
  virtual void Draw() const ;
  virtual void Handle(genv::event ev) ;

};


#endif // CIRCLE_HPP_INCLUDED
