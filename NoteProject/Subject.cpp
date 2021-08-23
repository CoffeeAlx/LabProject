#include "Subject.h"

Subject::~Subject(){}

void Subject::Sub(Observer *observer)
{
    ObsList.push_back(observer);
}

void Subject::Unsub(const int index)
{
    ObsList.erase( ObsList.begin() + index );
}

void Subject::notify()
{
    for(unsigned int i=0; i<ObsList.size(); i++)
    {
        ObsList.at(i)->update(this);
    }
}

int Subject::getCount(){};
void Subject::setCount(int s){};


