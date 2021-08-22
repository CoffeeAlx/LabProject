#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer
{
public:
    virtual ~Observer() {}
    virtual int getCount() = 0;
    virtual void update(Subject *sbj) = 0;
};

#endif // OBSERVER_H
