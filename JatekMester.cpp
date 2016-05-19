#include "JatekMester.h"
#include "graphics.hpp"
#include "string"
#include "vector"
using namespace genv;
using namespace std;

Jatekmester::Jatekmester(vector<ExampleCheckBox*> v): Widget(0,0,0,0)
{
    jatekos = false;
    lerakott = 0;
    uj = 0;
}

void Jatekmester::handle(event ev)
{
    for(int k=0; k<1600; k++){
        lerakott = 0;
         if(v[k]->_checked == true){
            lerakott++;
         }
    }
    if(lerakott > uj){
        for(int l=0; l<1600; l++){
            v[l]->valtas = !v[l]->valtas;
        }
    uj = lerakott;
    }
}

void Jatekmester::action(event ev)
{
}
