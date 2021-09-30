#pragma once
#include <iostream>
#include "Collection.h"
#include "Observer.h"

using namespace std;

class Viewer : public Observer {
 public:
  Viewer(Collection &sbj) : subject(sbj) {
    this->subject.Attach(this);
  }

  virtual ~Viewer(){}

  void Update() override
  {cout << "The state of the Note has Changed"<<endl;}

  void RemoveFromList()
  {subject.Detach(this);}

private:
    Collection &subject;


};














