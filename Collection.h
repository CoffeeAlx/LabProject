#pragma once
#include "Subject.h"

#include <algorithm>

using namespace std;

class Note;

class Collection : public Subject
{
private:
    string name;
    vector <Note> collection;

public:

    //C'tor & D'tor
    Collection();
    Collection(string name);
    virtual ~Collection();

    //Getter and Setter
    void setName(string name);
    string getName()const;

    //Methods
    void PutInto(vector <Note> &allnotes, vector <Collection> &allcollections);
    bool Add(Note &note);

    void Print(vector <Note> &allnotes,vector <Collection> &allcollections);
    void PrintNotes();

    void Edit(vector <Note> &allnotes, vector <Collection> &allcollections);
    void EditNote(string title);

    void Remove(vector <Note> &allnotes, vector <Collection> &allcollections);
    void RemoveNote(string title);

    //Observer Methods
    void ChangeEditable(bool editable);

    virtual void Attach(Note *note) override;
    virtual void Detach(Note *note) override;
    virtual void Notify(bool editable) override;

};


