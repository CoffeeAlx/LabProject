#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

//Classi che rappresentano note.
//Ogni nota è composta da titolo e testo, può essere bloccata per evitarne cancellazione/modifica
//e fa parte di una collezione specificata con nome.
//Può anche far parte di una collezione di note important oltre che di una collezione specifica.
//Usare Observer per indicare quante note stanno in una collezione.

class Subject;
class Note;
class Collection;

class Observer
{
public:
    virtual ~Observer() {}
    virtual int getCount() = 0;
    virtual void update(Subject *sbj) = 0;
};


class Subject
{
private:
    vector<Observer*> ObsList;
public:
    virtual ~Subject(){}

    void Sub(Observer *observer)
    {
        ObsList.push_back(observer);
    }

    void Unsub(const int index)
    {
        ObsList.erase(ObsList.begin() + index);
        cout<<"Deleted"<<endl;
    }

    void notify()
    {
        for(unsigned int i=0; i<ObsList.size(); i++)
        {
            ObsList.at(i)->update(this);
        }
    }

    virtual int getCount() = 0;
    virtual void setCount(int s) = 0;
};


class Note : public Subject
{
public:
    //C'tor & D'tor
    ~Note(){}
    Note(){}

    //Getter & Setter
    string getText()const {return text;}
    string getTitle()const {return title;}
    bool getStatus()const {return status;}
    void setText(string text){this->text = text;}
    void setTitle(string title){this->title = title;}
    int getCount()
    {return state;}
    void setCount(int s )
    {state = s;}

    //Other Methods
    friend void InsertNote(Collection &collection,Collection &important);

private:
    int state;
    string text;
    string title;
    bool status = 0;    //di default è modificabile
                        //false = 0 -> modificabile
                        //true = 1 -> non modificabile
};

class Collection : public Observer
{
public:
    //C'tor & D'tor
    ~Collection(){}
    Collection(){}

    //Getter & Setter
    void setCount(int state)
    {this->Count=state;}
    int getCount()
    {return Count;}
    vector <Note> getAllNotes()
    {return AllNotes;}

    //Other Methods
    void update( Subject *sbj );
    void AddNote(Note& NewNote);
    friend void InsertNote(Collection &collection,Collection &important);
    void Print();
    void EditNote();
    void DeleteNote();

private:
    int Count;
    vector <Note> AllNotes;

};

void Collection::Print()
{
    for (int i = 0; i < AllNotes.size(); i++)
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

void Collection::DeleteNote()
{
    int a;
    cout<<"Input the number of the note you want to delete"<<endl;
    cin>>a;
    AllNotes.erase(AllNotes.begin() + a);
    cout<<"Note deleted succesfully"<<endl;
}


void Collection::update(Subject *sbj)
{
    Count = sbj->getCount();
    cout << "Notes number updated." <<endl;
}

void Collection::AddNote(Note &NewNote)
{
  AllNotes.push_back(NewNote);
}

int n = 0;
int a = 0;
void InsertNote(Collection &collection, Collection &important)
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
        n++;
        important.AddNote(note);
        Subject *subject = new Note();
        subject->Sub(&important);
        subject->setCount(n);
        subject->notify();
        cout << "Notes in the collection: " << important.getCount() <<endl;
    }
    else
    {
        cout<<"Putting the note into a collection..."<<endl;
        a++;
        collection.AddNote(note);
        Subject *subject = new Note();
        subject->Sub(&collection);
        subject->setCount(a);
        subject->notify();
        cout << "Notes in the collection: " << collection.getCount() <<endl;
    }


 }

int main()
{   int choice, n=0;
    Collection collection;
    Collection important;

    do{
     cout<< "0. Create a new note"<<endl;
     cout<< "1. Print your notes"<<endl;
     cout<< "2. Edit a note"<<endl;
     cout<< "3. Delete a note"<<endl;
     cout<< "4. Exit"<<endl;
     cin>>choice;

        switch(choice)
        {
        case 0:
        {
                InsertNote(collection,important);
        }break;
        case 1:
        {       cout<<"These are the notes in your 'Important' collection"<<endl;
                important.Print();
                cout<<"These are the notes in your 'Others' collection"<<endl;
                collection.Print();
        }break;
        case 2:
        {       cout<<"Where is the note you want to edit?"<<endl;
                cin>>choice;
                cout<<"Press 1 for 'Important' or 0 for 'Others'"<<endl;
                if(choice==0)
                {
                    collection.EditNote();
                }
                else
                {
                    important.EditNote();
                }

        }break;
        case 3:
        {       cout<<"Where is the note you want to delete?"<<endl;
                cout<<"Press 1 for 'Important' or 0 for 'Others'"<<endl;
                cin>>choice;
                if(choice==0)
                {
                    collection.DeleteNote();
                }
                else
                {
                    important.DeleteNote();
                }
        }break;
        case 4:
        {return 0;}
        }
    }while(choice!=4);

return 0;

}





