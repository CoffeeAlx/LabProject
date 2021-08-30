#include "Collection.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

//C'tor & D'tor
Collection::~Collection(){}
Collection::Collection(){}

//Getter & Setter
void Collection::setCount(int state)
{this->Count=state;}

int Collection::getCount()
{return Count;}

vector <Note> Collection::getAllNotes()
{return AllNotes;}

//Other Methods

void Collection::update(Subject *sbj)
{
    Count = sbj->getCount();
    cout << "Notes number updated." <<endl;
}

void Collection::AddNote(Note &NewNote)
{
  AllNotes.push_back(NewNote);
}

void Collection::RemoveNote(int index)
{

  AllNotes.erase(AllNotes.begin() + index);

}
void Collection::Print()
{
    for (unsigned int i = 0; i < AllNotes.size(); i++)
    {
    cout<<"Note number:" <<i<<endl;
    cout <<"Title: \n"<< AllNotes[i].getTitle()<<endl;
    cout <<"Text: \n"<< AllNotes[i].getText()<<endl;
    }
}

void Collection::EditNote()
{
    string title, text;
    int a;
    bool found =false;
    cout<<"Type in the title of the note you want to edit"<<endl;
    cin>>title;
    for(unsigned int i=0; i<AllNotes.size(); i++)
    {
        if(AllNotes[i].getTitle()==title)
        {
        cout<<"Note found"<<endl;
        a=i;
        found=true;
        break;
        }
    }

    if(found)
    {
        if(AllNotes[a].getStatus()==1)
        {
        cout<<"You can't edit this note"<<endl;
        return;
        }
        else
        {
        cout << "Type in your note"<<endl;
        cin.ignore();
        std::getline(cin,text);
        AllNotes[a].setText(text);
        cout <<"Title: \n"<< AllNotes[a].getTitle()<<endl;
        cout <<"Text: \n"<< AllNotes[a].getText()<<endl;
        return;
        }
    }
    else
    {
        cout<<"Not found"<<endl;
        return;
    }
}










