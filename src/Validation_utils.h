#ifndef VALIDATIONUTILS_H
#define VALIDATIONUTILS_H

#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <regex>

bool validate_string(const string& str);
bool validate_phone(const string& phone);
bool validate_email(const string& email);
bool validate_date(const string& date);

#endif // VALIDATIONUTILS_H
