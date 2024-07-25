/*
Here, I define class Client and the operations between clients.

Firstly, I need to prevent duplication about the inclusion of header file. I need this content to be included only once.
I used ifndef/endif and define.



*/


#ifndef CLIENT.H
#define CLIENT.H


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Client
{
public:
    string name;
    string surname;
    string phone;
    string email;
    string address;
    string city;
    //string role;
    //string company; oppure bool company;

    // I need a specific constructor with input by reference (more efficient and direct) so to also change original variable
    Client(const string& _name, const string& _surname, const string& _phone, const string& _email, const string& _address, const string& _city);

    // Functions declaration:
        // Here I need to implement interaction operations (add and view) 

        // Functions for Client's operations
    void edit_client_details(const string& _name, const string& _surname, const string& _phone, const string& _email, const string& _address, const string& _city);
    void view_client_details() const;

    //~Client();
};

#endif