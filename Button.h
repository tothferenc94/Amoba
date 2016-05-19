#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"

class Button : public Widget {
protected:
    bool _checked;
public:
    Button(int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
    virtual void action(genv::event ev);
};


#endif // BUTTON_H_INCLUDED
