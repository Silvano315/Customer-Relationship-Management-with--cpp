/*
Here, I define class ClientManagement and the operations about client's interacitons and details.

Firstly, I need to prevent duplication about the inclusion of header file. I need this content to be included only once.
I used ifndef/endif and define.

I don't need constructor for this class because each element of the dynamic array clients receive the structure from Client.h

In this file, I decleare private and public variables and methods. The functions have the purpose to handle clients and 
interactions operations.
*/


#ifndef CLIENTSMANAGEMENT_H
#define CLIENTSMANAGEMENT_H

#include "Client.h"
#include <bits/stdc++.h>
using namespace std;
#include <vector>           // It helps to handle dynamic arrays for dimensions and memory
#include <algorithm>        // It helps to use built-in method like find, sort, copy


class ClientsManagement
{
private:
    // I need to declare vector of clients as a private varibale so to ensure privacy with encapsulation principle
    // This wll garantee that access to data will be possible only for methods inside this class
    vector<Client> clients;
public:
    //Implement all methods to handle client's operations

    void add_client(const Client& _client);
    void view_clients() const;

    // the search methods has to return to Client vector, I need a pointer because this allows to:
        // return nullptr for null result
        // avoid to copy entire Client vector
    vector<Client*> search_client(const string& _name, const string& _surname);

    void edit_client(const string& _name, const string& _surname); 
    void delete_client(const string& _name, const string& _surname);
    void search_interactions_by_type(const string& interaction_type) const;
    void save_data(const string& file_path);
    void load_data(const string& file_path);
};

#endif // CLIENTSMANAGEMENT_H