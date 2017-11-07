//
//  AdressBook.hpp
//  AddressLinkedList
//
//  Created by Brian Morales on 10/5/17.
//  Copyright © 2017 Brian. All rights reserved.
//

#ifndef AdressBook_hpp
#define AdressBook_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class AdressBook {
private:
    struct Contact {
        string name;
        string phone;
        Contact *next;
    };
    Contact *head;
    
public:
    AdressBook() {
        Contact *emptyContact = new Contact();
        head = emptyContact;
    }
    
    ~AdressBook() {
        Contact *delte = head;
        
        while(head){
            delte = head;
            head = head->next;
            delete delte;
        }
    }
    
    void add(string nombre, string telefono) {
        Contact *prior = head;
        Contact *adding = new Contact();
        
        adding->name = nombre;
        adding->phone = telefono;
        adding->next  = NULL;
        
        if (isEmpty())
            prior->next = adding;
        
        else if(prior){
            while(prior->next){
                prior = prior->next;
            }
            prior->next = adding;
        }
    }
    
    bool isEmpty() {
        if(head)
            return false;
        else
            return true;
    }
    
    string find(string search){
        Contact *prior = head;
        
        if(isEmpty())
            return "Empty List.\n";
        
        else {
            while (prior->next != NULL and prior->name != search) {
                prior = prior->next;
            }
            if (prior->name == search)
                return search;
            else
                return "Name not found.\n";
        }
    }
    
    string remove(string nombre) {
        
        if(isEmpty()){
            return "Address Book is empyt.\n";
        }
        else {
            Contact *nameSaerch = head;
            Contact *temporary = head;
            
            while (nameSaerch->next !=  NULL and nameSaerch->name != nombre){
                temporary = nameSaerch;
                nameSaerch = nameSaerch->next;
            }
            if(nameSaerch->name == nombre){
                temporary->next = nameSaerch->next;
                delete nameSaerch;
                return "Name removed.\n";
            }
            else
                return "Name not found.\n";
        }
    }
    
    string clear() {
        if (isEmpty())
            return "Address Book is emoty.\n";
        else{
            while (head){
                Contact* clearContact = head;
                head = head->next;
                delete clearContact;
            }
            return "Address Book cleared.\n"; 
        }
    }
    
    
};
#endif /* AdressBook_hpp */
