#ifndef NOTE_H
#define NOTE_H
#include <iostream>
#include "Subject.h"
#include "Collection.h"

class Collection;
using std::string;
using std::cout;
using std::endl;
using std::cin;

class Note : public Subject
{
public:

    //C'tor & D'tor
    ~Note();
    Note();

    //Getter & Setter
    string getText()const;
    string getTitle()const;
    bool getStatus()const;
    void setText(string text);
    void setTitle(string title);
    int getCount();
    void setCount(int s);

    //Other Methods
    void InsertNote(Collection &collection, Collection &important);

private:
    int state;
    string text;
    string title;
    bool status = 0;    //di default è modificabile
                        //false = 0 -> modificabile
                        //true = 1 -> non modificabile
};

#endif //NOTE_H
