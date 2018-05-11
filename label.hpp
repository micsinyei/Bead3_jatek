#ifndef LABEL_HPP_INCLUDED
#define LABEL_HPP_INCLUDED
#include "widgets.hpp"
enum Color{active,inactive,focused};
class Label : public Widget{
protected:
  std::string text_out;
  Color activity;
  virtual std::string checklength(std::string s);
public:
  Label(int kx, int ky, int w, int h, std::string s,Color c);
  Label(int kx, int ky, std::string s);
  virtual void SetText(std::string s);
  virtual std::string GetText() const;
  virtual void Draw() const ;
  virtual void Handle(genv::event ev) ;
  virtual void SetActive();
  virtual void SetNormal();
  virtual void SetFocus();
};

#endif // LABEL_HPP_INCLUDED
