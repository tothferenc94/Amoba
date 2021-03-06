#include "ChooseBox.h"
#include "graphics.hpp"
#include <string>
#include <fstream>
using namespace genv;
using namespace std;

ChooseBox::ChooseBox(int x, int y, int sx, int sy, std::vector<std::string> vektors): Widget(x,y,sx,sy)
{
    _checked=false;
    FontSize = sy-10;
    vektor=vektors;
    hatter = y+2;
    gorgo = 1;
    kiir = " ";
    rgb = 0;
}

void ChooseBox::draw() const
{

    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+_size_x-20, _y) << color(255,255,255) << box(20, _size_y/2);
    gout << move_to(_x+_size_x-20, _y+(_size_y)/2) << color(255,255,255) << box(20, _size_y/2);

    gout << move_to(_x+_size_x-16, _y+(_size_y)/7+(_size_y)/8) << color(0,0,0) << line(7.5,(_size_y)/1.8);
    gout << move_to(_x+_size_x-17, _y+(_size_y)/7+(_size_y)/8) << color(0,0,0) << line(7.5,(_size_y)/1.8);
    gout << move_to(_x+_size_x-4, _y+(_size_y)/7+(_size_y)/8) << color(0,0,0) << line(-7.5,(_size_y)/1.8);
    gout << move_to(_x+_size_x-3, _y+(_size_y)/7+(_size_y)/8) << color(0,0,0) << line(-7.5,(_size_y)/1.8);

    if(_checked)
    {

        if(vektor.size() < 2)
        {
            gout << move_to(_x, _y+_size_y) << color(255,255,255) << box(_size_x-20, _size_y);
            gout << move_to(_x+2, _y+_size_y+2) << color(0,0,0) << box(_size_x-24, _size_y-4);
            gout << move_to(_x+2, hatter) << color(rgb,rgb,rgb) << box(_size_x-24, _size_y-4);

            gout.load_font("LiberationSans-Regular.ttf",FontSize);
            gout << move_to(_x+3, _y+_size_y) << color(255,255,255) << text(vektor[0]);
        }

        if(vektor.size() == 2)
        {
            gout << move_to(_x, _y+_size_y) << color(255,255,255) << box(_size_x-20, _size_y*2);
            gout << move_to(_x+2, _y+_size_y+2) << color(0,0,0) << box(_size_x-24, _size_y*2-4);
            gout << move_to(_x+2, hatter) << color(rgb,rgb,rgb) << box(_size_x-24, _size_y-4);

            gout.load_font("LiberationSans-Regular.ttf",FontSize);
            gout << move_to(_x+3, _y+_size_y) << color(255,255,255) << text(vektor[0]);
            gout << move_to(_x+3, _y+2*_size_y) << color(255,255,255) << text(vektor[1]);
        }

        if(vektor.size() >= 3)
        {
            gout << move_to(_x+_size_x-20, _y+_size_y) << color(255,255,255) << box(20, _size_y*3);
            gout << move_to(_x+_size_x-20, _y+_size_y+2) << color(0,0,0) << box(18, _size_y*3-4);
            int _y_gorgo = (3*_size_y/(vektor.size()-2));
            gout << move_to(_x+_size_x-20, _y+_size_y+(gorgo-1)*_y_gorgo) << color(200,200,200) << box(20, _y_gorgo);

            gout << move_to(_x, _y+_size_y) << color(255,255,255) << box(_size_x-20, _size_y*3);
            gout << move_to(_x+2, _y+_size_y+2) << color(0,0,0) << box(_size_x-24, _size_y*3-4);
            gout << move_to(_x+2, hatter) << color(rgb,rgb,rgb) << box(_size_x-24, _size_y-4);

            gout.load_font("LiberationSans-Regular.ttf",FontSize);
            gout << move_to(_x+3, _y+_size_y) << color(255,255,255) << text(vektor[gorgo-1]);
            gout << move_to(_x+3, _y+2*_size_y) << color(255,255,255) << text(vektor[gorgo]);
            gout << move_to(_x+3, _y+3*_size_y) << color(255,255,255) << text(vektor[gorgo+1]);
        }
    }

    if(!_checked)
    {
        gout << move_to(_x, _y+_size_y) << color(0,0,0) << box(_size_x, _size_y*3);
    }

    gout.load_font("LiberationSans-Regular.ttf",FontSize);
    gout << move_to(_x+2,_y+2) << color(255,255,255) << text(kiir);

}

void ChooseBox::handle(event ev)
{

    if (ev.keycode == key_enter)
    {
        ofstream fajl;
        fajl.open("adatok.txt");

        for(unsigned int j=0; j<vektor.size(); j++)
        {
            fajl << vektor[j] << "\n";
        }

        fajl.close();
    }

    if (ev.type == ev_mouse && ev.pos_x > _x+_size_x-20 && ev.pos_x < _x+_size_x && ev.pos_y > _y &&
            ev.pos_y < _y+_size_y && ev.button == btn_left)
    {

        _checked = !_checked;
    }

    if(vektor.size() == 1)
    {


        if (ev.type == ev_mouse && ev.pos_x > _x && ev.pos_x < _x+_size_x-20 && ev.pos_y > _y+_size_y &&
                ev.pos_y < _y+2*_size_y && _checked)
        {

            hatter = _y+_size_y+2;
            rgb = 150;

            if(ev.button == btn_left)
            {
                kiir = vektor[0];
                _checked = !_checked;
            }
        }

    }

    if(vektor.size() == 2)
    {


        if (ev.type == ev_mouse && ev.pos_x > _x && ev.pos_x < _x+_size_x-20 && ev.pos_y > _y+_size_y &&
                ev.pos_y < _y+2*_size_y && _checked)
        {

            hatter = _y+_size_y+2;
            rgb = 150;

            if(ev.button == btn_left)
            {
                kiir = vektor[0];
                _checked = !_checked;
            }
        }
        if (ev.type == ev_mouse && ev.pos_x > _x && ev.pos_x < _x+_size_x-20 && ev.pos_y > _y+2*_size_y &&
                ev.pos_y < _y+3*_size_y && _checked)
        {

            hatter = _y+2*_size_y+2;
            rgb = 150;

            if(ev.button == btn_left)
            {
                kiir = vektor[1];
                _checked = !_checked;
            }
        }

    }

    if(vektor.size() >= 3)
    {

        if (ev.type == ev_mouse && ev.button == btn_wheeldown && gorgo < vektor.size()-2)
        {
            gorgo += 1;
        }

        if (ev.type == ev_mouse && ev.button == btn_wheelup && gorgo > 1)
        {
            gorgo -= 1;
        }

        if (ev.type == ev_mouse && ev.pos_x > _x && ev.pos_x < _x+_size_x-20 && ev.pos_y > _y+_size_y &&
                ev.pos_y < _y+2*_size_y && _checked)
        {

            hatter = _y+_size_y+2;
            rgb = 150;

            if(ev.button == btn_left)
            {
                kiir = vektor[gorgo-1];
                _checked = !_checked;
            }
        }

        if (ev.type == ev_mouse && ev.pos_x > _x && ev.pos_x < _x+_size_x-20 && ev.pos_y > _y+2*_size_y &&
                ev.pos_y < _y+3*_size_y && _checked)
        {

            hatter = _y+2*_size_y+2;
            rgb = 150;

            if(ev.button == btn_left)
            {
                kiir = vektor[gorgo];
                _checked = !_checked;
            }
        }

        if (ev.type == ev_mouse && ev.pos_x > _x && ev.pos_x < _x+_size_x-20 && ev.pos_y > _y+3*_size_y &&
                ev.pos_y < _y+4*_size_y && _checked)
        {

            hatter = _y+3*_size_y+2;
            rgb = 150;

            if(ev.button == btn_left)
            {
                kiir = vektor[gorgo+1];
                _checked = !_checked;
            }
        }
    }
}
bool ChooseBox::is_checked() const
{
    return _checked;
}
void ChooseBox::action(event ev)
{
}
