#include "utils.h"
#include <iostream>
#include <string>
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
    cout << "7. View Interactions\n" << endl;
    cout << "8. Search Interactions\n" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Other operations\n" << endl;
    cout << "9. Save Data\n" << endl;
    cout << "10. Load Data\n" << endl;
    cout << "11. Exit\n" << endl;
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
            cin.ignore();
            getline(cin, _name);
            cout << "Enter client's surname: " << endl;
            getline(cin, _surname);
            cout << "Enter client's phone: " << endl;
            getline(cin, _phone);
            cout << "Enter client's email: " << endl;
            getline(cin, _email);
            cout << "Enter client's address: " << endl;
            getline(cin, _address);
            cout << "Enter client's city: " << endl;
            getline(cin, _city);

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
            cout << "Enter client's name to edit: " << endl;
            cin.ignore();
            getline(cin, _name);
            cout << "Enter client's surname to edit: " << endl;
            getline(cin, _surname);

            Client* client = _management.search_client(_name, _surname);
            if (client != nullptr)
            {
                string new_name = client->name;
                string new_surname = client->surname;
                string new_phone = client->phone;
                string new_email = client->email;
                string new_address = client->address;
                string new_city = client->city;
                string input;

                cout << "Current name: " << client->name << ". Do you want to change it? (y/n): ";
                getline(cin, input);
                if (input == "y" || input == "Y") {
                    cout << "Enter new name: ";
                    getline(cin, new_name);
                }
                cout << "Current surname: " << client->surname << ". Do you want to change it? (y/n): ";
                getline(cin, input);
                if (input == "y" || input == "Y") {
                    cout << "Enter new surname: ";
                    getline(cin, new_surname);
                }
                cout << "Current phone: " << client->phone << ". Do you want to change it? (y/n): ";
                getline(cin, input);
                if (input == "y" || input == "Y") {
                    cout << "Enter new phone: ";
                    getline(cin, new_phone);
                }
                cout << "Current email: " << client->email << ". Do you want to change it? (y/n): ";
                getline(cin, input);
                if (input == "y" || input == "Y") {
                    cout << "Enter new email: ";
                    getline(cin, new_email);
                }
                cout << "Current address: " << client->address << ". Do you want to change it? (y/n): ";
                getline(cin, input);
                if (input == "y" || input == "Y") {
                    cout << "Enter new address: ";
                    getline(cin, new_address);
                }
                cout << "Current city: " << client->city << ". Do you want to change it? (y/n): ";
                getline(cin, input);
                if (input == "y" || input == "Y") {
                    cout << "Enter new city: ";
                    getline(cin, new_city);
                }

                Client edited_client(new_name, new_surname, new_phone, new_email, new_address, new_city);

                for (const auto& interaction : client->interactions)
                {
                    edited_client.add_interaction(interaction);
                }
                
                _management.edit_client(_name, _surname, edited_client);
                cout << "Client modified successfully!\n" << endl;
            } else
            {
                cout << "Error: Client not found!\n" << endl;
            }
            break;
        }
        case 4: {
            string _name, _surname;
            cout << "Enter client's name to delete: " << endl;
            cin.ignore();
            getline(cin, _name);
            cout << "Enter client's surname to delete: " << endl;
            getline(cin, _surname);
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
            cout << "Enter client's name to view: " << endl;
            cin.ignore();
            getline(cin, _name);
            cout << "Enter client's surname to view: " << endl;
            getline(cin, _surname);

            Client* client = _management.search_client(_name, _surname);
            if (client != nullptr)
            {
                cout << "\nClient found!\n" << endl;
                client->view_client_details();
                //cout << "\nClient interactions:\n" << endl;
                //client->view_interaction();
            } else
            {
                cout << "\nError: Client not found!" << endl;
            }
            break;
        }
        case 6: {
            string _name, _surname, _type, _date, _note;
            cout << "Enter client's name to add interaction: " << endl;
            cin.ignore();
            getline(cin, _name);
            cout << "Enter client's surname to add interaction: " << endl;
            getline(cin, _surname);
            Client* client = _management.search_client(_name, _surname);
            if (client != nullptr)
            {
                cout << "Client found!\n" << endl;
                cout << "Enter interaction's type: " << endl;
                getline(cin, _type);
                cout << "Enter interaction's date (format YYYY-MM-DD): " << endl;
                getline(cin, _date);
                cout << "Enter a note: " << endl;
                getline(cin, _note);

                Interaction _interaction(_type, _date, _note);
                client->add_interaction(_interaction);

                cout << "Interaction added successfully!\n" << endl;
            } else
            {
                cout << "Error: Client not found!" << endl;
            }  
            break;
        }
        case 7: {
            string _name, _surname, _type, _date, _note;
            cout << "Enter client's name to view interaction: " << endl;
            cin.ignore();
            getline(cin, _name);
            cout << "Enter client's surname to view interaction: " << endl;
            getline(cin, _surname);
            Client* client = _management.search_client(_name, _surname);
            if (client != nullptr)
            {
                client->view_interaction();
            } else
            {
                cout << "Error: Client not found!" << endl;
            }
            break;
        }
        case 8: {
            string interaction_type;
            cout << "Enter interaction type to search: ";
            cin.ignore();
            getline(cin, interaction_type);
            _management.search_interactions_by_type(interaction_type);
            break;
        }
        case 9: {
            _management.save_data("data/clients.csv");
            cout << "Clients data saved successfully!\n" << endl;
            break;
        }
        case 10: {
            _management.load_data("data/clients.csv");
            cout << "Clients data loaded successfully!\n" << endl;
            break;
        }
        case 11: {
            cout << "Exiting...\n" << endl;
            break;
        }
        default: {
            cout << "Warning: wrong choice. Insert a new correct value (1-11).\n" << endl;
            break;
        }
        }
    } while (choice != 11);
}