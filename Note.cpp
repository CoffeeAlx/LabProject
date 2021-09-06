#include "Note.h"

#include <string>

using namespace std;

//Getter & Setter
void Note::setText(string text)
{this->text = text;}

void Note::setTitle(string title)
{this->title = title;}

void Note::setEditable(bool editable)
{this->editable = editable;}

string Note::getText()const
{return text;}

string Note::getTitle()const
{return title;}

bool Note::getEditable()const
{return editable;}

//C'tor & D'tor
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

//Observer

void Note::Update(bool editable)
{
    this->editable = editable;
    cout << "The state of the Note has changed"<<endl;
}







