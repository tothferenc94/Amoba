#include "examplecheckbox.hpp"
#include "graphics.hpp"
using namespace genv;

ExampleCheckBox::ExampleCheckBox(int x, int y, int sx, int sy): Widget(x,y,sx,sy)
{
    _checked=false;
    valtas=false;
}

void ExampleCheckBox::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    if (_checked && valtas)
    {
        gout.load_font("LiberationSans-Regular.ttf",15);
        gout << move_to(_x+4, _y) << color(255,255,255) << text('x');
    }
    else if(_checked && !valtas){
        gout.load_font("LiberationSans-Regular.ttf",15);
        gout << move_to(_x+4, _y) << color(255,255,255) << text('o');
    }
}

void ExampleCheckBox::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' '))
    {
        _checked=true;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
    {
        _checked=true;
    }
}
bool ExampleCheckBox::is_checked() const
{
    return _checked;
}
void ExampleCheckBox::action(event ev)
{
}
