#ifndef COLLECTION_H
#define COLLECTION_H
#include "Observer.h"
#include "Subject.h"
#include "Note.h"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
class Note;

class Collection : public Observer
{
public:
    friend class Note;

    //C'tor & D'tor
    ~Collection();
    Collection();

    //Getter & Setter
    void setCount(int state);
    int getCount();
    vector <Note> getAllNotes();

    //Other Methods
    void update( Subject *sbj );
    void AddNote(Note &NewNote);
    void Print();
    void EditNote();
    void DeleteNote();
    void InsertNote(int NotesNumber);
    void RemoveNote(int index);

private:
    int Count;
    vector <Note> AllNotes;

};

#endif //COLLECTION_H
