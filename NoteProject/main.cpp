#include <iostream>
#include "Collection.h"
#include "Note.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{   int choice;
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
        {       Note note;
                note.InsertNote(collection,important);
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
