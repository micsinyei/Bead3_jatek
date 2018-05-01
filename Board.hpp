#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED
#include "widgets.hpp"

class Board: public  Widget{
protected:
    int b[7][6];
    int boxsize,circlesize;
 public:
 Board(int x, int y, int w, int h);
  virtual void Draw() const ;
  virtual void Handle(genv::event ev) ;
  virtual void SetBoard(int col,int row,int value);

};


#endif // BOARD_HPP_INCLUDED
