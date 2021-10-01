#pragma once
#include "Subject.h"
#include "Note.h"
#include <algorithm>

using namespace std;

class Collection : public Subject
{
private:
    vector<Observer*> obslist;
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
    bool Move(const string&title, const string&name,bool editable,vector <Note> &allnotes,vector <Collection> &allcollections);
    bool Add(Note &note, bool choice);

    Note Search(const string &title);
    bool MoveTo(Note &note);

    void Print(const vector <Note> &allnotes,const vector <Collection> &allcollections);
    void PrintNotes() const;

    void Edit( vector <Note> &allnotes,  vector <Collection> &allcollections);
    bool EditNote(const string &title, const string &text);

    void Remove( vector <Note> &allnotes, vector <Collection> &allcollections);
    bool RemoveNote(const string &title);

    //Observer Methods
    void ChangeEditable(bool editable);

    void Attach(Observer *obs)override;
    void Detach(Observer *obs) override;
    void Notify() override;

};

