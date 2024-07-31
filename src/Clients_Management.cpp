#include "Clients_Management.h"
#include "utils.h"
#include "Validation_utils.h"
#include <fstream>          // it helps to write data in a file or read data from a file
#include <sstream>          // it processes strings read from a fie (extract and convert datas)


// Function to add client
void ClientsManagement::add_client(const Client& _client){
    // clients the array vector from #include <vector>, so I can use this built-in function
    clients.push_back(_client);
}

// Function to view clients
void ClientsManagement::view_clients() const{
    // I can use auto to run the for loop and the compiler automatically understand the type of the variable
    // without specify the Client type
    for (const auto& client : clients)
    {
        client.view_client_details();
    }
}

// Function to search client
vector<Client*> ClientsManagement::search_client(const string& _name, const string& _surname){
    // Here I can't put const client because I need to update the variable later in the edit_client method
    vector<Client*> results;
    for (auto& client : clients)
    {
        if (client.name == _name && client.surname == _surname)
        {
            results.push_back(&client);
        }
    }
    return results;
}

// Function to edit client
void ClientsManagement::edit_client(const string& _name, const string& _surname){
    //Firstly, I need to search if there is a client with this name and surname, if there is one or more
    vector<Client*> clients_to_edit = search_client(_name, _surname);

    if (clients_to_edit.empty())
    {
        throw runtime_error("Client not found!");
    }
    Client* client = nullptr;
    if (clients_to_edit.size() > 1) {
        client = handle_client_selection(clients_to_edit);
        if (client == nullptr) {
            throw runtime_error("No valid client selected for modification.");
        }
    } else {
        client = clients_to_edit.front();
    }
    // new variables 
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
        while (!validate_string(new_name)) {
            cout << "Invalid name. Please re-enter: " << endl;
            getline(cin, new_name);
        }
    }
    cout << "Current surname: " << client->surname << ". Do you want to change it? (y/n): ";
    getline(cin, input);
    if (input == "y" || input == "Y") {
        cout << "Enter new surname: ";
        getline(cin, new_surname);
        while (!validate_string(new_surname)) {
            cout << "Invalid surname. Please re-enter: " << endl;
            getline(cin, new_surname);
        }
    }
    cout << "Current phone: " << client->phone << ". Do you want to change it? (y/n): ";
    getline(cin, input);
    if (input == "y" || input == "Y") {
        cout << "Enter new phone: ";
        getline(cin, new_phone);
        while (!validate_phone(new_phone)) {
        cout << "Invalid phone. Please re-enter: " << endl;
        getline(cin, new_phone);
    }
    }
    cout << "Current email: " << client->email << ". Do you want to change it? (y/n): ";
    getline(cin, input);
    if (input == "y" || input == "Y") {
        cout << "Enter new email: ";
        getline(cin, new_email);
        while (!validate_email(new_email)) {
            cout << "Invalid email. Please re-enter: " << endl;
            getline(cin, new_email);
        }
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

    // Add to the modified client the previous interactions
    for (const auto& interaction : client->interactions)
    {
        edited_client.add_interaction(interaction);
    }

    *client = edited_client;
}

// Function to delete a client
void ClientsManagement::delete_client(const string& _name, const string& _surname){
    //Firstly, I need to search if there is a client with this name and surname, if there is one or more
    vector<Client*> clients_to_delete = search_client(_name, _surname);

    if (clients_to_delete.empty()) {
        throw runtime_error("Client not found!");
    }
    if (clients_to_delete.size() == 1) {
        Client* client = clients_to_delete.front();
        auto iterator = find_if(clients.begin(), clients.end(), [&_name, &_surname](const Client& client) {
            return client.name == _name && client.surname == _surname;
        });
        if (iterator != clients.end()) {
            clients.erase(iterator);
            //cout << "Client deleted successfully!" << endl;
        }
    }
    else {
        Client* client_to_delete = handle_client_selection(clients_to_delete);
        if (client_to_delete != nullptr) {
            auto iterator = find_if(clients.begin(), clients.end(), [&_name, &_surname](const Client& client_to_delete) {
                return client_to_delete.name == _name && client_to_delete.surname == _surname;
            });
            if (iterator != clients.end()) {
                clients.erase(iterator);
                //cout << "Client deleted successfully!" << endl;
            } else {
                throw runtime_error("Failed to delete the selected client.");
            }
        } else {
            throw runtime_error("No valid client selected for deletion.");
        }
    }
}

// Functio to search interactions by the type
void ClientsManagement::search_interactions_by_type(const string& interaction_type) const {
    for (const auto& client : clients) {
        bool found = false;
        for (const auto& interaction : client.interactions) {
            if (interaction.type == interaction_type) {
                if (!found) {
                    cout << "Client: " << client.name << " " << client.surname << endl;
                    found = true;
                }
                interaction.view_interaction_details();
            }
        }
    }
}

// Function to save data in file path
void ClientsManagement::save_data(const string& _file_path){
    // I open file in write mode
    ofstream file(_file_path);

    for (const auto& client : clients)
    {
        file << client.name << ',' << client.surname << ',' << client.phone << ',' << client.email << ',' << client.address << ',' << client.city << "\n";
        for (const auto& interaction : client.interactions)
        {
            file << interaction.type << ',' << interaction.date << ',' << interaction.note << "\n";
        }
    }
}

// Function to load data from file path
void ClientsManagement::load_data(const string& _file_path){

    ifstream file(_file_path);
    string line;
    Client* current_client = nullptr;
    // I take one line of the file at time
    while (getline(file, line)) {
        // I read the inputs inside the string line in ss
        istringstream ss(line);
        string field;
        vector<string> fields;
        while (getline(ss, field, ','))
        {
            fields.push_back(field);
        }
        // If there are 6 fields saved in a line it is a Client
        if (fields.size() == 6)
        {
            string name = fields[0];
            string surname = fields[1];
            string phone = fields[2];
            string email = fields[3];
            string address = fields[4];
            string city = fields[5];
            Client client(name, surname, phone, email, address, city);
            add_client(client);
            current_client = &clients.back();
        } else if (fields.size() == 3 && current_client != nullptr) // If there are 3 fields saved in a line it is a Interaction
        {
            string type = fields[0];
            string date = fields[1];
            string note = fields[2];
            current_client->add_interaction(Interaction(type, date, note));
        } else {
            cout << "Unrecognized line format or no current client: " << line << endl;
        }
    }
    file.close();
}