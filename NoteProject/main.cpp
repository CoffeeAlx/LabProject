#include <iostream>
#include "Collection.h"
#include "Note.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int a = 0;          //Keeps the number of notes in the "Others" collection
    int b = 0;          //Keeps the number of notes in the "Others" collection
    int choice;
    Note* nt=new Note();
    Collection others;
    Collection important;

    do{
     cout<<"########################"<<endl;
     cout<<"# 0. Create a new note #"<<endl;
     cout<<"# 1. Print your notes  #"<<endl;
     cout<<"# 2. Edit a note       #"<<endl;
     cout<<"# 3. Delete a note     #"<<endl;
     cout<<"# 4. Exit              #"<<endl;
     cout<<"########################"<<endl;
     cin>>choice;

        switch(choice)
        {
        case 0:
        {       nt->InsertNote(others,important,a,b);
        }break;
        case 1:
        {       cout<<"These are the notes in your 'Important' collection"<<endl;
                important.Print();
                cout<<"These are the notes in your 'Others' collection"<<endl;
                others.Print();
        }break;
        case 2:
        {       cout<<"Where is the note you want to edit?"<<endl;
                cout<<"Press 1 for 'Important' or 0 for 'Others'"<<endl;
                cin>>choice;
                if(choice==0)
                {
                    others.EditNote();
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
                    nt->DeleteNote(others, b);
                }
                else
                {   a--;
                    nt->DeleteNote(important, a);
                }
        }break;
        case 4:
        {        delete nt;
                 return 0;
        }
        }
    }while(choice!=4);

    /*
    //Unit Testing
    Note* nt=new Note();
    Collection collection;
    Collection important;

    nt->InsertNote(collection,important,a,b);
    //Inserendola in collection
    collection.EditNote();
    //Editandola
    collection.EditNote();
    //Cancellandola
    b--;
    nt->DeleteNote(collection, b);

    delete nt;
    return 0;
    */

return 0;

}
