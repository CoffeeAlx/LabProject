
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

Collection::Collection(const string &name)
{
    this->name = name;
}

Collection::~Collection(){}

//Getter and Setter

string Collection::GetName()const
{return name;}

void Collection::SetName(const string &name)
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
        note.SetEditable(true);
        collection.push_back(note);
        return true;
    }
    else
    {   collection.push_back(note);
        return false;
    }


}

void Collection::PutInto( vector <Note> &allnotes, vector <Collection> &allcollections)
{
    string temp;
    bool found = false;
    bool choice;
    unsigned int i,j;

    cout<<"Type in the title of the note you are looking for"<<endl;
    cin>>temp;
    for(j=0; j<allnotes.size(); j++)
    {
        if(allnotes[j].GetTitle()==temp)
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
            if(allcollections[i].GetName()==temp)
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

string Collection::EditNote(const std::string & title)
{
    std::string text;
    for (unsigned int i = 0; i < collection.size(); i++)
    {
        if (collection[i].GetTitle() == title)
        {
            if (collection[i].GetEditable())
            {
                std::cout << "You can't edit this note" << std::endl;
                return text;
            }
            else
            {
                std::cout << "Found" << std::endl;
                std::cout<<"Type in your note" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, text);
                collection[i].SetText(text);
                std::cout << "Note edited succesfully" << std::endl;
                return text;
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
        if(allnotes[i].GetTitle()==title)
        {
            cout<<"Found"<<endl;
            cout<<"Type in your note"<<endl;
            cin.ignore();
            std::getline(cin,text);
            allnotes[i].SetText(text);
            cout <<"Note edited succesfully"<<endl;
            return;
        }
    }

    for(unsigned int i=0; i<allcollections.size(); i++)
    {
        allcollections[i].EditNote(title);
    }
}

void Collection::RemoveNote(const string &title)
{
    for(unsigned int i=0; i<collection.size(); i++)
    {
        if(collection[i].GetTitle()==title)
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
        if(allnotes[i].GetTitle()==title)
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


