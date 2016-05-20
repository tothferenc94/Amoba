#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include <vector>
#include <string>
#include "CountBox.h"
#include "ChooseBox.h"
#include "textbox.h"
#include "Button.h"
#include "JatekMester.h"

using namespace std;
using namespace genv;

void event_loop(vector<Widget*>& widgets)
{
    event ev;
    int focus = -1;
    while(gin >> ev )
    {
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            for (size_t i=0; i<widgets.size(); i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0; i<widgets.size(); i++)
        {
            widgets[i]->draw();
        }
        gout << refresh;
    }
}


int main()
{
    gout.open(650,650);
    vector<Widget*> w;
    vector<ExampleCheckBox*> v;

    for(int k=0; k<40; k++){
           for(int l=0; l<40; l++){
            ExampleCheckBox * b1 = new ExampleCheckBox(10+k*15,50+l*15,17,17);
            v.push_back(b1);
            w.push_back(b1);
           }};

    Lambda* b2 = new Lambda(100,5,100,30,[&v]()
        {
            for(int i=0; i<1600; i++){
                v[i]->valtas = !v[i]->valtas;
                if(v[i]->_checked){
                    v[i]->aktiv=false;
                }
            }
        });

    w.push_back(b2);
    event_loop(w);
    return 0;
}
