#include "utils.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Function to show on interface the possible options to user 
void show_menu(){
    cout << "-----------------------------------" << endl;
    cout << "Client operations:\n" << endl;
    cout << "1. Add Client\n" << endl;
    cout << "2. View Clients\n" << endl;
    cout << "3. Edit Client\n" << endl;
    cout << "4. Delete Client\n" << endl;
    cout << "5. Search Client\n" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Interaction operations\n" << endl;
    cout << "6. Add Interaction\n" << endl;
    cout << "7. View Interaction\n" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Other operations\n" << endl;
    cout << "8. Save Data\n" << endl;
    cout << "9. Load Data\n" << endl;
    cout << "10. Exit\n" << endl;
    cout << "-----------------------------------" << endl;
}

// Function to ask operation from user. Input will be saved to choice as int
void user_input(ClientsManagement& _management){

    int choice; 

    do
    {
        show_menu();
        cout << "Choose operation you need:" << endl;
        cin >> choice;
        cout << "\n" << endl;

        switch (choice)
        {
        case 1: {
            
            string _name, _surname, _phone, _email, _address, _city;
            cout << "Enter client's name: " << endl;
            cin >> _name;
            cout << "Enter client's surname: " << endl;
            cin >> _surname;
            cout << "Enter client's phone: " << endl;
            cin >> _phone;
            cout << "Enter client's email: " << endl;
            cin >> _email;
            cout << "Enter client's address: " << endl;
            cin >> _address;
            cout << "Enter client's city: " << endl;
            cin >> _city;

            Client new_client(_name, _surname, _phone, _email, _address, _city);

            _management.add_client(new_client);

            cout << "\nClient added successfully!\n" << endl;
            break;
        }
        case 2: {

            _management.view_clients();
            break;
        }
        case 3:{
            string _name, _surname;
            cout << "Enter client's name to edit: ";
            cin >> _name;
            cout << "Enter client's surname to edit: ";
            cin >> _surname;

            Client* client = _management.search_client(_name, _surname);
            if (client == nullptr)
            {
                //cerr << "Error: Client not found!\n" << endl;
                throw runtime_error("Client not found!");
            }
            string new_name, new_surname, new_phone, new_email, new_address, new_city;
            cout << "Enter new client's name to edit: ";
            cin >> new_name;
            cout << "Enter new client's surname to edit: ";
            cin >> new_surname;
            cout << "Enter new client's phone to edit: ";
            cin >> new_phone;
            cout << "Enter new client's email to edit: ";
            cin >> new_email;
            cout << "Enter new client's address to edit: ";
            cin >> new_address;
            cout << "Enter new client's city to edit: ";
            cin >> new_city;

            Client edited_client(new_name, new_surname, new_phone, new_email, new_address, new_city);

            try {
                _management.edit_client(_name, _surname, edited_client);
                cout << "Client modified successfully!\n" << endl;
            } catch (const runtime_error& e) {
                cout << "Erorr: " << e.what() << endl;
            }
            break;
        }
        case 4: {
            string _name, _surname;
            cout << "Enter client's name to delete: ";
            cin >> _name;
            cout << "Enter client's surname to delete: ";
            cin >> _surname;
            try {
                _management.delete_client(_name, _surname);
                cout << "Client deleted successfully!\n" << endl;
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 5: {
            string _name, _surname;
            cout << "Enter client's name to view: ";
            cin >> _name;
            cout << "Enter client's surname to view: ";
            cin >> _surname;
            try {
                Client* client = _management.search_client(_name, _surname);
                cout << "\nClient founded: " << endl;
                client->view_client_details();
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 6: {
            string _name, _surname, _type, _date, _note;
            cout << "Enter client's name to add interaction: ";
            cin >> _name;
            cout << "Enter client's surname to add interaction: ";
            cin >> _surname;
            try {
                Client* client = _management.search_client(_name, _surname);

                cout << "Client founded!\n" << endl;
                cout << "Enter interaction's type: ";
                cin >> _type;
                cout << "Enter interaction's date (format YYYY-MM-DD): ";
                cin >> _date;
                cout << "Enter a note: ";
                cin >> _note;

                Interaction _interaction(_type, _date, _note);
                client->add_interaction(_interaction);

                cout << "Interaction added successfully!\n" << endl;
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 7: {
            string _name, _surname, _type, _date, _note;
            cout << "Enter client's name to add interaction: ";
            cin >> _name;
            cout << "Enter client's surname to add interaction: ";
            cin >> _surname;
            try {
                Client* client = _management.search_client(_name, _surname);
                client->view_interaction();                
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 8: {
            _management.save_data("data/clients.csv");
            cout << "Clients data saved successfully!\n" << endl;
            break;
        }
        case 9: {
            _management.load_data("data/clients.csv");
            cout << "Clients data loaded successfully!\n" << endl;
            break;
        }
        case 10: {
            cout << "Exiting...\n" << endl;
            break;
        }
        default: {
            cout << "Warning: wrong choice. Insert a new correct value (1-10).\n" << endl;
            break;
        }
        }
    } while (choice != 10);
}