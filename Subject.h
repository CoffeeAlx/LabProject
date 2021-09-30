#pragma once
#include <vector>
#include "Observer.h"

class Subject {
 public:
  virtual ~Subject(){};
  virtual void Attach(Observer *obs) = 0;
  virtual void Detach(Observer *obs) = 0;
  virtual void Notify(bool editable) = 0;
};
