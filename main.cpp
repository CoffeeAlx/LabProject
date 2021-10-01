#include "Collection.h"
#include "Viewer.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int choice,editable;
    string name, title;
    Collection * pointer = new Collection("Pointer");
    Viewer *observer = new Viewer(*pointer);
    vector <Note> allnotes;
    vector <Collection> allcollections;

    do{
        cout<<"####################################"<<endl;
        cout<<"# 1. Create a new note             #"<<endl;
        cout<<"# 2. Create a new collection       #"<<endl;
        cout<<"# 3. Put a note into a collection  #"<<endl;
        cout<<"# 4. Print your notes              #"<<endl;
        cout<<"# 5. Edit a note                   #"<<endl;
        cout<<"# 6. Delete a note                 #"<<endl;
        cout<<"# 7. Move a note in a collection   #"<<endl;
        cout<<"# 8. Exit                          #"<<endl;
        cout<<"####################################"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: {
                Note note(0);
                allnotes.push_back(note);
            }break;
            case 2: {
                cout << "Give it a name"<<endl;
                cin >> name;
                Collection collection(name);
                allcollections.push_back(collection);
            }break;
            case 3: {
                cout<<"Type in the title of the note you are looking for"<<endl;
                cin>>title;
                cout<<"Type in the title of the collection you are looking for"<<endl;
                cin>>name;
                cout<<"Do you want to set the note as NOT editable?"<<endl;
                cout<<"1 for yes, 0 for no"<<endl;
                cin>> editable;
                choice = pointer->Move(title,name,editable,allnotes, allcollections);
                if(choice){pointer->ChangeEditable(1);}
            }break;
            case 4: {
                pointer->Print(allnotes, allcollections);
            }break;
            case 5: {
                pointer->Edit(allnotes, allcollections);
            }break;
            case 6: {
                pointer->Remove(allnotes, allcollections);
            }break;
            case 7: {
                Note note;
                cout << "Type in the name of the collection where the target note is"<<endl;
                cin >> name;
                for(unsigned int i=0; i<allcollections.size();i++)
                {
                    if(allcollections[i].GetName()==name)
                    {
                       cout << "Type in the name of the note you want to move"<<endl;
                       cin >> name;
                       note = allcollections[i].Search(name);
                    }
                }

                cout << "Type in the name of the target collection"<<endl;
                cin >> name;
                for(unsigned int i=0; i<allcollections.size();i++)
                {
                    if(allcollections[i].GetName()==name)
                    {
                        allcollections[i].MoveTo(note);
                    }
                }
            }break;
            case 8:{
                delete pointer;
                delete observer;
                return 0;}
        }
    }while(choice!=8);



}
