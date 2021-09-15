#ifndef OBSERVERNOTES_SUBJECT_H
#define OBSERVERNOTES_SUBJECT_H

#include <vector>
#include <list>

#include "Note.h"

class Subject
{
public:
    std::vector<Note*> obslist;
    virtual void Attach(Note *note)=0;
    virtual void Detach(Note *note)=0;
    virtual void Notify(bool editable)=0;
protected:
    virtual ~Subject() = default;

};

#endif //OBSERVERNOTES_SUBJECT_H
