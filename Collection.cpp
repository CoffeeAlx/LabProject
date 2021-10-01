#include "Collection.h"
#include "Viewer.h"
using namespace std;

//C'tor & D'tor

Collection::Collection(){}

Collection::Collection(const string &name)
{
    this->name = name;
}

Collection::~Collection(){}

//Getter and Setter

string Collection::GetName()const
{return name;}

//Methods
bool Collection::Add(Note &note, bool choice)
{
    if(choice==1)
    {
        note.SetEditable(true);
        collection.push_back(note);
        return true;
    }
    else
    {   collection.push_back(note);
        return false;
    }
}

bool Collection::Move(const string&title, const string&name,const bool &editable, vector <Note> &allnotes, vector <Collection> &allcollections)
{
    bool choice;
    for(unsigned int j=0; j<allnotes.size(); j++)
    {
        if(allnotes[j].GetTitle()==title)
        {
            for(unsigned int i=0; i<allcollections.size(); i++)
            {
                if(allcollections[i].GetName()==name)
                {
                    choice = allcollections[i].Add(allnotes[j], editable);
                    cout<<"The note has been put into the collection"<<endl;
                    allnotes.erase(allnotes.begin() + j);
                    if(choice){return 1;}
                    else{return 0;}
                }
            }
        }
    }

    return false;
}

Note Collection::Search(const string &title)
{
    Note note;
    for(unsigned int i = 0; i < collection.size(); i++)
    {
        if(collection[i].GetTitle()==title)
        {
            note = collection[i];
            collection.erase(collection.begin() + i);
            break;
        }
    }

    return note;
}

bool Collection::MoveTo(Note &note)
{
    collection.push_back(note);
    return true;
}

void Collection::PrintNotes() const
{
    int sum=0;
    for (unsigned int i = 0; i < collection.size(); i++)
    {
        if(collection[i].GetEditable()==0)
            sum++;
    }

    cout <<"There is/are " <<collection.size()<< " note(s) in this collection"<<endl;
    cout <<"Of these, the modifiable one(s) are(is) "<< sum <<endl;

    for (unsigned int i = 0; i < collection.size(); i++)
    {
        cout <<"Title:  "<< collection[i].GetTitle()<<endl;
        cout <<"Text:   "<< collection[i].GetText()<<endl;
        cout <<"Editable:   "<< collection[i].GetEditable()<<endl;
    }
}

void Collection::Print(const vector <Note> &allnotes,const vector <Collection> &allcollections)
{
    cout<<"There is/are " << allnotes.size() <<" note(s) that is/are not into a collection"<<endl;

    for (unsigned int i = 0; i < allnotes.size(); i++)
    {
        cout <<"Title:  "<< allnotes[i].GetTitle()<<endl;
        cout <<"Text:   "<< allnotes[i].GetText()<<endl;
        cout <<"Editable:  "<< allnotes[i].GetEditable()<<endl;
    }

    for(unsigned int i = 0; i < allcollections.size(); i++)
    {
        cout<<"Collection: " <<allcollections[i].GetName()<<endl;
        allcollections[i].PrintNotes();
    }

}

bool Collection::EditNote(const string&title, const string&text)
{
    for (unsigned int i = 0; i < collection.size(); i++)
    {
        if (collection[i].GetTitle() == title)
        {
            if (collection[i].GetEditable())
            {
                cout << "You can't edit this note" << endl;
                return false;
            }
            else
            {
                collection[i].SetText(text);
                cout << "Note edited succesfully" << endl;
                return true;
            }
        }
    }

    return false;
}

void Collection::Edit(vector <Note> &allnotes, vector <Collection> &allcollections)
{
    string title, text;
    cout<<"Type in the title of the note you are looking for"<<endl;
    cin>>title;
    cout<<"Type in your note"<<endl;
    cin.ignore();
    std::getline(cin,text);

    for(unsigned int i=0; i<allnotes.size(); i++)
    {
        if(allnotes[i].GetTitle()==title)
        {
            allnotes[i].SetText(text);
            cout <<"Note edited succesfully"<<endl;
            break;
        }
    }

    for(unsigned int i=0; i<allcollections.size(); i++)
    {
        allcollections[i].EditNote(title, text);
    }
}

bool Collection::RemoveNote(const string &title)
{
    for(unsigned int i=0; i<collection.size(); i++)
    {
        if(collection[i].GetTitle()==title)
        {
            collection.erase(collection.begin() + i);
            cout<<"Note deleted succesfully"<<endl;
            return true;
        }
    }

    return false;
}

void Collection::Remove(vector <Note> &allnotes, vector <Collection> &allcollections)
{
    string title;
    cout<<"Type in the title of the note you want to delete"<<endl;
    cin>>title;

    for(unsigned int i=0; i<allnotes.size(); i++)
    {
        if(allnotes[i].GetTitle()==title)
        {
            allnotes.erase(allnotes.begin() + i);
            cout<<"Note deleted succesfully"<<endl;
            break;
        }
    }

    for(unsigned int i=0; i<allcollections.size(); i++)
    {
        allcollections[i].RemoveNote(title);
    }
}

//Observer Methods

void Collection::ChangeEditable(bool editable)
{
    Notify();
}

void Collection::Attach(Observer* obs)
{
    obslist.push_back(obs);
}
void Collection::Detach(Observer* obs)
{
    obslist.erase(std::remove(obslist.begin(), obslist.end(), obs), obslist.end());
}

void Collection::Notify()
{
    for(vector<Observer*>::const_iterator iter = obslist.begin(); iter != obslist.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->Update();
        }
    }
}


