#include <bits/stdc++.h>
using namespace std;

#include "Interaction.h"

// Define Interaction constructor 
Interaction::Interaction(const string& _type, const string& _date, const string& _note){
    
    type = _type;
    date = _date;
    note = _note;
}

// Function to view interaction's details 
void Interaction::view_interaction_details () const{
    cout << "Type: " << type << endl;
    cout << "Date: " << date << endl;
    cout << "Note: " << note << endl;
}