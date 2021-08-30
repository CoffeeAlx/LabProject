#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <iostream>
#include <list>

#include "Observer.h"

class Subject
{
public:
    std::list<Observer*> ObsList;
    virtual ~Subject();
    virtual void Sub(Observer *observer)=0;
    virtual void Unsub(Observer *observer)=0;
    virtual void notify()=0;
    virtual int getCount() = 0;
    virtual void setCount(int s) = 0;
};

#endif // SUBJECT_H
