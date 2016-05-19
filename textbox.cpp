#include "graphics.hpp"
#include "textbox.h"
#include <fstream>

using namespace genv;
using namespace std;

TextBox::TextBox(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked=false;
    FontSize=15;
}

void TextBox::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

        gout << color(255,255,255);

        gout.load_font("LiberationSans-Regular.ttf",FontSize);
        gout << move_to(_x,_y);
        for(unsigned int key=0;key<keycode.size();key++){


            gout << text(keycode[key]);






    }
}


void TextBox::handle(event ev)
{
    if (ev.keycode == key_enter)
    {
        ofstream fajl;
        fajl.open("adatok.txt");

        for(int j=0; j<keycode.size(); j++)
        {
            fajl << keycode[j] << "\n";
        }

        fajl.close();
    }

    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;

    }
    if(ev.keycode>33 && ev.keycode<400){


            keycode.push_back(ev.keycode);


        }
    if(ev.keycode==8 && keycode.size()>0){

        keycode.pop_back();

    }
}
bool TextBox::is_checked() const
{
    return _checked;
}
void TextBox::action(event ev)
{
}


