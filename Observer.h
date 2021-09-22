#pragma once

class Observer
{
public:
    virtual void Update(bool editable) = 0;
protected:
    virtual ~Observer() = default;
};

