#include <bits/stdc++.h>
using namespace std;

#include "Client.h"


// Define constructor for Client
Client::Client(const string& _name, const string& _surname, const string& _phone, const string& _email, const string& _address, const string& _city){
    name = _name;
    surname = _surname;
    phone = _phone;
    email = _email;
    address = _address;
    city = _city;
}

// Interaction operations:
void Client::add_interaction(const Interaction& _interaction){
    interactions.push_back(_interaction);
}

void Client::view_interaction() const{
    for (const auto& interaction : interactions)
    {
        interaction.view_interaction_details();
    }
    
}


// Client operations:    
void Client::edit_client_details(const string& _name, const string& _surname, const string& _phone, const string& _email, const string& _address, const string& _city){
    name = _name;
    surname = _surname;
    phone = _phone;
    email = _email;
    address = _address;
    city = _city;
}

void Client::view_client_details() const {

    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
    cout << "City: " << city << "\n" << endl;

}