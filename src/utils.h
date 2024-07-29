/*
Here, I define functions for general purpose to handle manu and user's input.

Firstly, I need to prevent duplication about the inclusion of header file. I need this content to be included only once.
I used ifndef/endif and define.



*/


#ifndef UTILS_H
#define UTILS_H

#include "Clients_Management.h"


void show_menu();
void user_input(ClientsManagement& _management);


#endif // UTILS_H