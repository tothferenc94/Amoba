#ifndef TEXTBOX_H_INCLUDED
#define TEXTBOX_H_INCLUDED


#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>

class TextBox : public Widget {
protected:
    bool _checked;
    double FontSize;
    std::vector<char> keycode;
public:
    TextBox(int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual void action(genv::event ev);
    virtual bool is_checked() const ;
};


#endif // TEXTBOX_H_INCLUDED
