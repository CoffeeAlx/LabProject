#include "Note.h"

#include <string>

using namespace std;

//Getter & Setter
void Note::SetText(const string &text)
{this->text = text;}

void Note::SetEditable(const bool &editable)
{this->editable = editable;}

string Note::GetText()const
{return text;}

string Note::GetTitle()const
{return title;}

bool Note::GetEditable()const
{return editable;}

//C'tor
Note::Note()
{
    cout << "Give it a title"<<endl;
    cin >> title;
    this->title = title;
    cout << "Type in your note"<<endl;
    cin.ignore();
    getline(cin,text);
    this->text = text;
    cout<<"Note created succesfully"<<endl;
}

Note::~Note(){}

Note::Note(const string& title, const string& text)
{
    this->title = title;
    this->text = text;
}

//Observer

void Note::Update()
{
    cout << "The state of the Note has changed"<<endl;
}


