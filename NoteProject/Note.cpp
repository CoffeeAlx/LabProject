#include "Note.h"

//C'tor & D'tor
Note::~Note(){}
Note::Note(){}

//Getter & Setter
string Note::getText()const
{return text;}

string Note::getTitle()const
{return title;}

bool Note::getStatus()const
{return status;}

void Note::setText(string text)
{this->text = text;}

void Note::setTitle(string title)
{this->title = title;}

int Note::getCount()
{return state;}

void Note::setCount(int s )
{state = s;}

//Other Methods

void Note::InsertNote(Collection &collection, Collection &important, int &a, int &b)
{
    Note note;
    cout << "Give it a title"<<endl;
    cin >> note.title;
    cout << "Type in your note"<<endl;
    cin.ignore();
    std::getline(cin,note.text);
    cout<<"Title: \n"<<note.title<<endl;
    cout<<"Text: \n"<<note.text<<endl;

    int choice;
    cout<<"Do you want to prevent the note from being modified?"<<endl;
    cout<<"Be careful, once decided you can no longer go back"<<endl;
    cout<<"1 for yes, 0 for no"<<endl;
    cin>>choice;
    if(choice==1)
    {
        note.status = 1;
    }

    cout<<"In which collection do you want to put the note?"<<endl;
    cout<<"Press 1 for 'Important' or 0 for 'Others'"<<endl;
    cin>>choice;
    if(choice==1)
    {
        cout<<"Putting the note into a collection..."<<endl;
        a++;
        important.AddNote(note);
        Subject *subject = new Note();
        subject->Sub(&important);
        subject->setCount(a);
        subject->notify();
        cout << "Notes in the collection: " << important.getCount() <<endl;
    }
    else
    {
        cout<<"Putting the note into a collection..."<<endl;
        b++;
        collection.AddNote(note);
        Subject *subject = new Note();
        subject->Sub(&collection);
        subject->setCount(b);
        subject->notify();
        cout << "Notes in the collection: " << collection.getCount() <<endl;
    }


 }

void Note::DeleteNote(Collection &collezione, int Num)
{
    int index;
    cout<<"Input the number of the note you want to delete (Beware, the firs note is labeled with a 0)"<<endl;
    cin>>index;
    collezione.RemoveNote(index);
    cout<<"Note deleted succesfully"<<endl;
    Subject *subject = new Note();
    subject->Sub(&collezione);
    subject->setCount(Num);
    subject->notify();
    cout << "Notes in the collection: " << collezione.getCount() <<endl;
    delete subject;
}
