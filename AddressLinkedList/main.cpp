//
//  main.cpp
//  AddressLinkedList
//
//  Created by Brian Morales on 10/5/17.
//  Copyright © 2017 Brian. All rights reserved.
//

#include "AdressBook.hpp"

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

string getName();
string getPhone();
//void isFull(const AdressBook&);
void isEmpty( AdressBook&);

int main()
{
    AdressBook a;
    char choice;
    
    do
    {
        string name, phone;
        
        cout << "A-dd Contact\n";
        cout << "R-emove Contact\n";
        cout << "F-ind Contact\n";
        cout << "C-lear Contacts\n";
        cout << "E-isEmpty\n";
        //cout << "U-isFull\n";
        cout << "Q-uit\n";
        cout << "> ";
        
        cin >> choice;
        cin.ignore();
        
        switch(choice)
        {
            case 'A':
            case 'a':
                name = getName();
                phone = getPhone();
                a.add(name, phone);
                break;
            case 'R':
            case 'r':
                name = getName();
                cout << a.remove(name);
                break;
            case 'F':
            case 'f':
                name = getName();
                cout << a.find(name) << endl;
                break;
           case 'C':
            case 'c':
                cout << a.clear();
                break;
            case 'E':
            case 'e':
                isEmpty(a);
                break;
           /* case 'U':
            case 'u':
                isFull(a);
                break;*/
        }
    } while(choice != 'Q' && choice != 'q');
}

string getName()
{
    string n;
    
    cout << "Enter contact's name: ";
    getline(cin, n);
    
    return n;
}

string getPhone()
{
    string p;
    
    cout << "Enter contact's number: ";
    getline(cin, p);
    
    return p;
}

/*void isFull(const AdressBook& r)
{
    if(r.isFull())
        cout << "AddressBook is full.\n";
    else
        cout << "AddressBook isn't full.\n";
}*/


void isEmpty( AdressBook& r)
{
    if(r.isEmpty())
        cout << "AddressBook is empty.\n";
    else
        cout << "AddressBook isn't empty.\n";
}
