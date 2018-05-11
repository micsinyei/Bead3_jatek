#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "widgets.hpp"
#include <functional>
enum Icon { ARROW_DOWN, ARROW_UP,TEXT };
class Button : public Widget{
protected:
 std::function<void()> onclick;
 Icon i;
 std::string label;
public:
    Button(int kx, int ky, int w, int h, std::string label_i,Icon type);
    Button(int kx, int ky, int w, int h, Icon type);
  virtual void Draw() const ;
  virtual void Handle(genv::event ev) ;
  virtual void Action(std::function<void()>);
  virtual void CallAction() const;
};


#endif // BUTTON_HPP_INCLUDED
