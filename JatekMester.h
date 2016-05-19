#ifndef JATEKMESTER_H_INCLUDED
#define JATEKMESTER_H_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"
#include "string"
#include "examplecheckbox.hpp"
#include "vector"

class Jatekmester : public Widget {

public:
    bool jatekos;
    int lerakott;
    int uj;
    std::vector<ExampleCheckBox*> v;
    Jatekmester(std::vector<ExampleCheckBox*> v);
    virtual void handle(genv::event ev);
    virtual void action(genv::event ev);

};

#endif // JATEKMESTER_H_INCLUDED
