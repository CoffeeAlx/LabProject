#include "Collection.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int choice;
    string name;
    Collection * pointer = new Collection("Pointer");
    vector <Note> allnotes;
    vector <Collection> allcollections;

    do{
        cout<<"###################################"<<endl;
        cout<<"# 1. Create a new note            #"<<endl;
        cout<<"# 2. Create a new collection      #"<<endl;
        cout<<"# 3. Put a note into a collection #"<<endl;
        cout<<"# 4. Print your notes             #"<<endl;
        cout<<"# 5. Edit a note                  #"<<endl;
        cout<<"# 6. Delete a note                #"<<endl;
        cout<<"# 0. Exit                         #"<<endl;
        cout<<"###################################"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: {
                Note * note = new Note(0);
                allnotes.push_back(*note);
            }break;
            case 2: {
                cout << "Give it a name"<<endl;
                cin >> name;
                Collection * collection = new Collection(name);
                allcollections.push_back(*collection);
            }break;
            case 3: {
                pointer->Move(allnotes, allcollections);
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
            case 0:{
                delete pointer;
                return 0;}
        }
    }while(choice!=0);



}
