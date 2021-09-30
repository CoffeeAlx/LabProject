#pragma once

#include <iostream>
#include <string>
#include "Observer.h"

using namespace std;

class Note
{
private:
    string title;
    string text;
    bool editable = false; //editable by deafult

public:
    //C'tor & D'tor
    Note();
    Note(const Note &n);
    Note(const bool& editable);
    ~Note();

    //Getter & Setter
    void SetText(const string &text);
    void SetTitle(const string &title);
    void SetEditable(const bool &editable);
    string GetText()const;
    bool GetEditable()const;
    string GetTitle()const;

};



