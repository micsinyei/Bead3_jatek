#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED
#include "widgets.hpp"

class Circle: public  Widget{
int r;
 public:
 Circle(int kx, int ky,int r);
  virtual void Draw() const ;
  virtual void Handle(genv::event ev) ;
  void Setx(int newx);
  void Sety(int newy);
};


#endif // CIRCLE_HPP_INCLUDED
