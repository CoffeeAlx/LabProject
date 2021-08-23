#include <iostream>
#include "Collection.h"
#include "Note.h"

using std::cout;
using std::endl;
using std::cin;

int a = 0;          //Keeps the number of notes
int b = 0;

int main()
{   int choice;
    Note note;
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
        {       note.InsertNote(collection,important,a,b);
        }break;
        case 1:
        {       cout<<"These are the notes in your 'Important' collection"<<endl;
                important.Print();
                cout<<"These are the notes in your 'Others' collection"<<endl;
                collection.Print();
        }break;
        case 2:
        {       cout<<"Where is the note you want to edit?"<<endl;
                cout<<"Press 1 for 'Important' or 0 for 'Others'"<<endl;
                cin>>choice;
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
                {   b--;
                    note.DeleteNote(collection, b);
                }
                else
                {   a--;
                    note.DeleteNote(important, a);
                }
        }break;
        case 4:
        {return 0;}
        }
    }while(choice!=4);

return 0;

}
