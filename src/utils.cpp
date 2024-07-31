#include "utils.h"
#include "Validation_utils.h"
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
            while (!validate_string(_name))
            {
                cout << "Invalid name. Please re-enter:" << endl;
                getline(cin, _name);
            }
            cout << "Enter client's surname: " << endl;
            getline(cin, _surname);
            while (!validate_string(_surname)) {
                cout << "Invalid surname. Please re-enter: " << endl;
                getline(cin, _surname);
            }
            cout << "Enter client's phone: " << endl;
            getline(cin, _phone);
            while (!validate_phone(_phone)) {
                cout << "Invalid phone. Please re-enter: " << endl;
                getline(cin, _phone);
            }
            cout << "Enter client's email: " << endl;
            getline(cin, _email);
                while (!validate_email(_email)) {
                cout << "Invalid email. Please re-enter: " << endl;
                getline(cin, _email);
            }
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
            try {
                _management.edit_client(_name, _surname);
                cout << "Client modified successfully!\n" << endl;
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
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

            vector<Client*> clients_to_view = _management.search_client(_name, _surname);
            if (clients_to_view.empty()) {
                cout << "Error: Client not found!" << endl;
                break;
            }
            Client* client = nullptr;
            if (clients_to_view.size() > 1) {
                client = handle_client_selection(clients_to_view);
                if (client == nullptr) {
                    cout << "No valid client selected. Aborting view operation." << endl;
                    break;
                }
            } else {
                client = clients_to_view.front();
            }
            cout << "\nClient found!\n" << endl;
            client->view_client_details();
            //cout << "\nClient interactions:\n" << endl;
            //client->view_interaction();
            break;
        }
        case 6: {
            string _name, _surname, _type, _date, _note;
            cout << "Enter client's name to add interaction: " << endl;
            cin.ignore();
            getline(cin, _name);
            cout << "Enter client's surname to add interaction: " << endl;
            getline(cin, _surname);
            vector<Client*> clients_to_edit = _management.search_client(_name, _surname);
            if (clients_to_edit.empty()) {
                cout << "Error: Client not found!" << endl;
                break;
            }
            Client* client = nullptr;
            if (clients_to_edit.size() > 1) {
                client = handle_client_selection(clients_to_edit);
                if (client == nullptr) {
                    cout << "No valid client selected. Aborting interaction addition." << endl;
                    break;
                }
            } else {
                client = clients_to_edit.front();
            }

            cout << "Client found!\n" << endl;
            do {
                cout << "Enter interaction's type: " << endl;
                getline(cin, _type);
                if (_type.empty()) {
                    cout << "Interaction type cannot be empty. Please enter a valid type." << endl;
                }
            } while (_type.empty());

            do {
                cout << "Enter interaction's date (format YYYY-MM-DD): " << endl;
                getline(cin, _date);
                if (!validate_date(_date)) {
                    cout << "Invalid date format. Please enter a date in the format YYYY-MM-DD." << endl;
                }
            } while (!validate_date(_date));

            cout << "Enter a note: " << endl;
            getline(cin, _note);

            Interaction _interaction(_type, _date, _note);
            client->add_interaction(_interaction);

            cout << "Interaction added successfully!\n" << endl;
            break;
        }
        case 7: {
            string _name, _surname;
            cout << "Enter client's name to view interaction: " << endl;
            cin.ignore();
            getline(cin, _name);
            cout << "Enter client's surname to view interaction: " << endl;
            getline(cin, _surname);
            vector<Client*> clients_to_view = _management.search_client(_name, _surname);
            if (clients_to_view.empty()) {
                cout << "Error: Client not found!" << endl;
                break;
            }
            Client* client = nullptr;
            if (clients_to_view.size() > 1) {
                client = handle_client_selection(clients_to_view);
                if (client == nullptr) {
                    cout << "No valid client selected. Aborting view interactions operation." << endl;
                    break;
                }
            } else {
                client = clients_to_view.front();
            }
            
            client->view_interaction();
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


// Funtion to handle the case in which there are multiple clients with the same name and surname.
Client* handle_client_selection(const std::vector<Client*>& clients) {
    if (clients.empty()) {
        cout << "No clients found." << endl;
        return nullptr;
    }

    cout << "\nThere are multiple clients with this name and surname:" << endl;
    for (size_t i = 0; i < clients.size(); ++i) {
        cout << "Client " << i + 1 << ":" << std::endl;
        clients[i]->view_client_details();
    }

    size_t choice;
    cout << "Enter the number of the client you want to select: " << endl;
    cin >> choice;
    cin.ignore();  

    if (choice > 0 && choice <= clients.size()) {
        return clients[choice - 1];
    } else {
        cout << "Invalid choice." << endl;
        return nullptr;
    }
}