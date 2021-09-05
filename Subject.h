#pragma once

#include <vector>
#include <list>

#include "Note.h"

class Subject
{
    std::vector<Note*> obslist;

public:
    void Attach(Note *note);
    void Detach(Note *note);
    void Notify(bool editable);
};


