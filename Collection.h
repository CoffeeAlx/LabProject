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
    explicit Collection(const string &name);
    virtual ~Collection();

    //Getter and Setter
    void SetName(const string &name);
    string GetName()const;

    //Methods
    void PutInto( vector <Note> &allnotes,  vector <Collection> &allcollections);
    bool Add(Note &note);

    void Print(const vector <Note> &allnotes,const vector <Collection> &allcollections);
    void PrintNotes() const;

    void Edit( vector <Note> &allnotes,  vector <Collection> &allcollections);
    string EditNote(const string &title);

    void Remove( vector <Note> &allnotes, vector <Collection> &allcollections);
    void RemoveNote(const string &title);

    //Observer Methods
    void ChangeEditable(bool editable);

    virtual void Attach(Note *note) override;
    virtual void Detach(Note *note) override;
    virtual void Notify(bool editable) override;

};

