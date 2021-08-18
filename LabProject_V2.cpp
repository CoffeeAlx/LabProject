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
//Può anche far parte di una collezione di note importanti oltre che di una collezione specifica.
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
    void setText(string text){this->text = text;}
    void setTitle(string title){this->title = title;}
    int getCount()
    {return state;}
    void setCount(int s )
    {state = s;}

    //Other Methods
    friend void InsertNote(Collection &collection, int n);
    void EditNote(Collection collection, vector <Note>&AllNotes);

private:
    int state;
    string text;
    string title;
    bool status = false;
};
class Collection : public Observer
{
public:
    //C'tor & D'tor
    ~Collection(){}
    Collection(){}

    //Getter & Setter
    int setCount(int state)
    {this->Count=state;}
    int getCount()
    {return Count;}
    vector <Note> getAllNotes()
    {return AllNotes;}

    //Other Methods
    void update( Subject *sbj );
    void AddNote(Note& NewNote);
    friend void InsertNote(Collection &collection, int n);
    void EditNote(Collection collection, vector <Note>&AllNotes);
    void Print()
    {
       for (int i = 0; i < AllNotes.size(); i++)
        {
        cout<<"Note number:" <<i<<endl;
        cout <<"Title: \n"<< AllNotes[i].getTitle()<<endl;
        cout <<"Text: \n"<< AllNotes[i].getText()<<endl;
        }
    }

    //Questo serviva a me per verificare che le note fossero state inserite correttamente nel vector
    //void print(){cout<<"Dim vettore:" <<AllNotes.size()<<endl;}

private:
    int Count;
    vector <Note> AllNotes;

};

void Collection::update( Subject *sbj )
{
    Count = sbj->getCount();
    cout << "Notes number updated." <<endl;
}

void Collection::AddNote(Note &NewNote)
{
  AllNotes.push_back(NewNote);
}

void InsertNote(Collection &collection, int n)
{
    Note note;
    cout << "Give it a title"<<endl;
    cin >> note.title;
    cout << "Type in your note"<<endl;
    cin.ignore();
    std::getline(cin,note.text);
    cout<<"Title: "<<note.title<<endl;
    cout<<"Text: "<<note.text<<endl;

    int choice;
    cout<<"Do you want to prevent the note from being modified?"<<endl;
    cout<<"Be careful, once decided you can no longer go back"<<endl;
    cout<<"0 for yes, 1 for no"<<endl;
    cin>>choice;
    if(choice==0)
    {
        note.status = true;
    }

    cout<<"Putting the note into a collection..."<<endl;
    collection.AddNote(note);
    Subject *subject = new Note();
    subject->Sub(&collection);
    subject->setCount(n);
    subject->notify();
    cout << "Notes in the collection: " << collection.getCount() << std::endl;

    //collection.print();

    delete subject;
 }

void EditNote(Collection collection, vector <Note>&AllNotes)
{
    string title;
    cout<<"Type in the title of the note you want to edit"<<endl;
    cin>>title;

}

int main()
{   int choice, n=0;
    Collection collection;

    do{
     cout<< "0. Create a new note"<<endl;
     cout<< "1. Print your notes"<<endl;
     cout<< "2. Edit a note"<<endl;         //TODO
     cout<< "3. Delete a note"<<endl;       //TODO Observer?
     cout<< "4. Exit"<<endl;
     cin>>choice;

        switch(choice)
        {
        case 0:
        {       n++;
                InsertNote(collection,n);
        }break;
        case 1:
        {       collection.Print();
        }break;

        case 4:
        {   return 0;
        }
        }
    }while(choice!=4);

return 0;

}





