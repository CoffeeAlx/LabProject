#include "Subject.h"

#include <algorithm>

using namespace std;

void Subject::Attach(Note *note)
{
    obslist.push_back(note);
}
void Subject::Detach(Note *note)
{
    obslist.erase(std::remove(obslist.begin(), obslist.end(), note), obslist.end());
}

void Subject::Notify(bool editable)
{
    for(vector<Note*>::const_iterator iter = obslist.begin(); iter != obslist.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->Update(editable);
        }
    }
}

