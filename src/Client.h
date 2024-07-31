/*
Here, I define class Client and the operations about clients.

Firstly, I need to prevent duplication about the inclusion of header file. I need this content to be included only once.
I used ifndef/endif and define.

In this file, I decleare variables and constructor for Client with functions to handle Client and Interaction operations.
*/


#ifndef CLIENT_H
#define CLIENT_H


#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <vector>
#include "Interaction.h"

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
    //string company; or bool company;

    vector<Interaction> interactions;

    // I need a specific constructor with input by reference (more efficient and direct) so to also change original variable
    Client(const string& _name, const string& _surname, const string& _phone, const string& _email, const string& _address, const string& _city);

    // Functions declaration:
        // Function for Interaction operations
    void add_interaction(const Interaction& _interaction);
    void view_interaction() const;

        // Functions for Client's operations
    void edit_client_details(const string& _name, const string& _surname, const string& _phone, const string& _email, const string& _address, const string& _city);
    void view_client_details() const;

    //~Client();
};

#endif