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
    bool editable = 0;  //editabile di default

public:
    Note();
    void Update(bool editable);
    void setText(string text);
    void setTitle(string title);
    void setEditable(bool editable);
    string getText()const;
    bool getEditable()const;
    string getTitle()const;
};


