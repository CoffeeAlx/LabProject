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
    string GetName()const;

    //Methods
    void Move( vector <Note> &allnotes,  vector <Collection> &allcollections);
    bool Add(Note &note, bool choice);

    void Print(const vector <Note> &allnotes,const vector <Collection> &allcollections);
    void PrintNotes() const;

    void Edit( vector <Note> &allnotes,  vector <Collection> &allcollections);
    bool EditNote(const string &title, const string &text);

    void Remove( vector <Note> &allnotes, vector <Collection> &allcollections);
    bool RemoveNote(const string &title);

    //Observer Methods
    void ChangeEditable();

    virtual void Attach(Note *note) override;
    virtual void Detach(Note *note) override;
    virtual void Notify() override;

};

