#ifndef CHOOSEBOX_H_INCLUDED
#define CHOOSEBOX_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <string>

class ChooseBox : public Widget
{
protected:
    bool _checked;
    int FontSize;
    std::vector<std::string> vektor;
    int hatter;
    unsigned int gorgo;
    int rgb;
    std::string kiir;

public:
    ChooseBox(int x, int y, int sx, int sy, std::vector<std::string> v);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
    virtual void action(genv::event ev);
};

#endif // CHOOSEBOX_H_INCLUDED
