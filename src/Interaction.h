/*
Here, I define class Interaction and the operations about client's interacitons.

Firstly, I need to prevent duplication about the inclusion of header file. I need this content to be included only once.
I used ifndef/endif and define.



*/


#ifndef INTERACTION_H
#define INTERACTION_H


#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Interaction
{
public:
    string type;
    string date;
    string note;

    // I need a specific constructor with input by reference (more efficient and direct) so to also change original variable
    Interaction(const string& type, const string& date, const string& note);

    // Functions declaration:
        // Here I need to implement interaction operations (add and view) 
        
    void view_interaction_details () const;

    //~Interaction();
};






#endif