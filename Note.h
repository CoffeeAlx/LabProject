#pragma once

#include <iostream>
#include <string>
#include <list>

#include "Observer.h"

using namespace std;

class Collection;

class Note : Observer
{
    friend class Collection;

    string title;
    string text;
    bool editable = 0;  //editable by default

public:
    //C'tor & D'tor
    Note();
    virtual ~Note();

    //Getter & Setter
    void setText(string text);
    void setTitle(string title);
    void setEditable(bool editable);
    string getText()const;
    bool getEditable()const;
    string getTitle()const;

    //Observer
    void Update(bool editable);
};

