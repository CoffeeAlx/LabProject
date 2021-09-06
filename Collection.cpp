#include "Collection.h"

using namespace std;

//C'tor & D'tor

Collection::Collection()
{
    cout << "Give it a name"<<endl;
    cin >> name;
    this->name = name;
    cout<<"Collection created succesfully"<<endl;
}

Collection::Collection(string name)
{
    this->name = name;
}

Collection::~Collection(){}

//Getter and Setter

string Collection::getName()const
{return name;}

void Collection::setName(string name)
{this->name = name;}

//Methods

bool Collection::Add(Note &note)
{
    bool choice;
    cout<<"Do you want to set the note as NOT editable?"<<endl;
    cout<<"1 for yes, 0 for no"<<endl;
    cin>>choice;
    if(choice==1)
    {
        note.setEditable(1);
        collection.push_back(note);
        return 1;
    }
    else
    {   collection.push_back(note);
        return 0;
    }


}

void Collection::PutInto(vector <Note> &allnotes, vector <Collection> &allcollections)
{
    string temp;
    bool found = false;
    bool choice;
    unsigned int i,j;

    cout<<"Type in the title of the note you are looking for"<<endl;
    cin>>temp;
    for(j=0; j<allnotes.size(); j++)
    {
        if(allnotes[j].getTitle()==temp)
        {
        cout<<"Found"<<endl;
        found=true;
        break;
        }
    }

    if(found==false)
    {
        cout<<"Not found"<<endl;
        return;
    }
    else
    {
        found=false;
        cout<<"Type in the title of the collection you are looking for"<<endl;
        cin>>temp;
        for(i=0; i<allcollections.size(); i++)
        {
            if(allcollections[i].getName()==temp)
            {
            cout<<"Found"<<endl;
            found=true;
            break;
            }
        }
    }

    if(found==false)
    {
        cout<<"Not found"<<endl;
        return;
    }
    else
    {
        choice = allcollections[i].Add(allnotes[j]);
        allcollections[i].Attach(&allnotes[j]);
        if(choice==1)
        {allcollections[i].ChangeEditable(1);}
        cout<<"The note has been put into the collection"<<endl;
        allnotes.erase(allnotes.begin() + j);
    }
}

void Collection::PrintNotes()
{
    for (unsigned int i = 0; i < collection.size(); i++)
    {
    cout <<"Title:  "<< collection[i].getTitle()<<endl;
    cout <<"Text:   "<< collection[i].getText()<<endl;
    cout <<"Editable:   "<< collection[i].getEditable()<<endl;
    }
}

void Collection::Print(vector <Note> &allnotes, vector <Collection> &allcollections)
{
    cout<<"Notes that are not into a collection: "<<endl;
    for (unsigned int i = 0; i < allnotes.size(); i++)
    {
    cout <<"Title:  "<< allnotes[i].getTitle()<<endl;
    cout <<"Text:   "<< allnotes[i].getText()<<endl;
     cout <<"Editable:  "<< allnotes[i].getEditable()<<endl;
    }

    for(unsigned int i = 0; i < allcollections.size(); i++)
    {
    cout<<"Notes in the collection named: " <<allcollections[i].getName()<<endl;
    allcollections[i].PrintNotes();
    }

}

void Collection::EditNote(string title)
{
    string text;
    for(unsigned int i=0; i<collection.size(); i++)
    {
        if(collection[i].getTitle()==title)
        {
            if(collection[i].getEditable()==1)
            {
                cout<<"You can't edit this note"<<endl;
                return;
            }
            else
            {
                cout<<"Found"<<endl;
                cout<<"Type in your note"<<endl;
                cin.ignore();
                std::getline(cin,text);
                collection[i].setText(text);
                cout <<"Note edited succesfully"<<endl;
                return;
                }
            }
    }
}

void Collection::Edit(vector <Note> &allnotes, vector <Collection> &allcollections)
{
    string title, text;
    cout<<"Type in the title of the note you are looking for"<<endl;
    cin>>title;

        for(unsigned int i=0; i<allnotes.size(); i++)
        {
            if(allnotes[i].getTitle()==title)
            {
                cout<<"Found"<<endl;
                cout<<"Type in your note"<<endl;
                cin.ignore();
                std::getline(cin,text);
                allnotes[i].setText(text);
                cout <<"Note edited succesfully"<<endl;
                return;
            }
        }

        for(unsigned int i=0; i<allcollections.size(); i++)
        {
           allcollections[i].EditNote(title);
        }
}

void Collection::RemoveNote(string title)
{
    for(unsigned int i=0; i<collection.size(); i++)
    {
        if(collection[i].getTitle()==title)
        {
            collection.erase(collection.begin() + i);
            cout<<"Note deleted succesfully"<<endl;
        }
    }
}

void Collection::Remove(vector <Note> &allnotes, vector <Collection> &allcollections)
{
    string title;
    cout<<"Type in the title of the note you want to delete"<<endl;
    cin>>title;

        for(unsigned int i=0; i<allnotes.size(); i++)
        {
            if(allnotes[i].getTitle()==title)
            {
                allnotes.erase(allnotes.begin() + i);
                cout<<"Note deleted succesfully"<<endl;
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
    Notify(editable);
}

void Collection::Attach(Note *note)
{
    obslist.push_back(note);
}
void Collection::Detach(Note *note)
{
    obslist.erase(std::remove(obslist.begin(), obslist.end(), note), obslist.end());
}

void Collection::Notify(bool editable)
{
    for(vector<Note*>::const_iterator iter = obslist.begin(); iter != obslist.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->Update(editable);
        }
    }
}
