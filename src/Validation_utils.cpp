#include "Validation_utils.h"

#include <bits/stdc++.h>
using namespace std;


bool validate_string(const string& str) {
    return !str.empty();
}
bool validate_phone(const string& phone) {
    return all_of(phone.begin(), phone.end(), ::isdigit) && phone.length() >= 10;
}
bool validate_email(const string& email) {
    const regex pattern(R"((\w+)(\.{1}\w+)*@(\w+)(\.(\w+))+)");
    return regex_match(email, pattern);
}