#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <iostream>
#include <list>

#include "Observer.h"

class Subject
{
private:
    std::vector<Observer*> ObsList;
public:
    virtual ~Subject();
    void Sub(Observer *observer);
    void Unsub(const int index);
    void notify();
    virtual int getCount() = 0;
    virtual void setCount(int s) = 0;
};

#endif // SUBJECT_H
