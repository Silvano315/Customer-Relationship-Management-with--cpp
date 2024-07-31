/*
Here, I define functions for general purpose to handle manu and user's input.

Firstly, I need to prevent duplication about the inclusion of header file. I need this content to be included only once.
I used ifndef/endif and define.

In this file, I decleare functions to handle the interface menu, the user input choice, the case in which there are multiple 
clients with the same name and surname.

*/


#ifndef UTILS_H
#define UTILS_H

#include "Clients_Management.h"


void show_menu();
void user_input(ClientsManagement& _management);
Client* handle_client_selection(const std::vector<Client*>& clients);


#endif // UTILS_H