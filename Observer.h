#ifndef OBSERVERNOTES_OBSERVER_H
#define OBSERVERNOTES_OBSERVER_H

class Observer
{
public:
    virtual void Update(bool editable) = 0;
protected:
    virtual ~Observer() = default;
};

#endif //OBSERVERNOTES_OBSERVER_H
