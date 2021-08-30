#include "Subject.h"

Subject::~Subject(){}

void Subject::Sub(Observer *observer)
{
    ObsList.push_back(observer);
}

void Subject::Unsub(Observer *observer)
{
    ObsList.remove(observer);
}

void Subject::notify()
{
    for(auto i:ObsList)
    {
        i->update(this);
    }
}

int Subject::getCount(){};
void Subject::setCount(int s){};


