#ifndef OBSERVERNOTES_NOTE_H
#define OBSERVERNOTES_NOTE_H

#include <iostream>
#include <string>
#include <list>

#include "Observer.h"

using namespace std;

class Collection;

class Note : Observer
{
    string title;
    string text;
    bool editable = false;  //editable by default

public:
    //C'tor & D'tor
    Note();
    virtual ~Note();

    //Getter & Setter
    void SetText(const string &text);
    void SetTitle(const string &title);
    void SetEditable(const bool &editable);
    string GetText()const;
    bool GetEditable()const;
    string GetTitle()const;

    //Observer
    void Update(bool editable) override;
};


#endif //OBSERVERNOTES_NOTE_H
