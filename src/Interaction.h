/*
Here, I define class Interaction and the operations about client's interacitons.

Firstly, I need to prevent duplication about the inclusion of header file. I need this content to be included only once.
I used ifndef/endif and define.

In this file, I decleare variables and constructor for Interaction with view function
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
    Interaction(const string& _type, const string& _date, const string& _note);

    void view_interaction_details () const;

    //~Interaction();
};






#endif