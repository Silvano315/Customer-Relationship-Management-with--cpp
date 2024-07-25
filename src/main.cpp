#include <bits/stdc++.h>
using namespace std;

// Function to show on interface the possible options to user 
void menu(){

    cout << "Client operations:\n" << endl;
    cout << "1. Add Client\n" << endl;
    cout << "2. View Client\n" << endl;
    cout << "3. Edit Client\n" << endl;
    cout << "4. Delete Client\n" << endl;
    cout << "5. Search Client\n" << endl;

    cout << "Interaction operations\n" << endl;
    cout << "6. Add Interaction\n" << endl;
    cout << "7. View Interaction\n" << endl;

    cout << "Other operations\n" << endl;
    cout << "8. Save Data\n" << endl;
    cout << "9. Load Data\n" << endl;
    cout << "10. Exit\n" << endl;

}


// Function to ask operation from user. Input will be saved to choice as int
void user_input(){

    int choice; 

    do
    {
        menu();
        cout << "Choose operation you need:\n" << endl;
        cin >> choice;

        /*
        Implementation To DO...
        */

    } while (choice != 10);
}



int main(){



    return 0;
}