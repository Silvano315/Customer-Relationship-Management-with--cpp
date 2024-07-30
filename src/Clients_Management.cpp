#include "Clients_Management.h"
#include <fstream>          // it helps to write data in a file or read data from a file
#include <sstream>          // it processes strings read from a fie (extract and convert datas)



void ClientsManagement::add_client(const Client& _client){
    // clients the array vector from #include <vector>, so I can use this built-in function
    clients.push_back(_client);
}


void ClientsManagement::view_clients() const{
    // I can use auto to run the for loop and the compiler automatically understand the type of the variable
    // without specify the Client type
    for (const auto& client : clients)
    {
        client.view_client_details();
    }
}


Client* ClientsManagement::search_client(const string& _name, const string& _surname){
    // Here I can't put const client because I need to update the variable later in the edit_client method
    for (auto& client : clients)
    {
        if (client.name == _name && client.surname == _surname)
        {
            return &client;
        }
    }
    return nullptr;
}


void ClientsManagement::edit_client(const string& _name, const string& _surname, const Client& modified_client){
    Client* client = search_client(_name, _surname);
    if (client != nullptr)
    {
        *client = modified_client;
    }
    else
    {
        //cerr << "Error: Client not found!\n" << endl;
        throw runtime_error("Client not found!");
    }
}


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


void ClientsManagement::delete_client(const string& _name, const string& _surname){
    Client* client = search_client(_name, _surname);
    if (client != nullptr)
    {
        // I need to find the iterator or position for the element found before inside the clients vector
        auto iterator = find_if(clients.begin(), clients.end(), [&_name, &_surname](const Client& client){
            return client.name == _name && client.surname == _surname;
        });
        if (iterator != clients.end())
        {
            clients.erase(iterator);
        }
    }
    else
    {
        throw runtime_error("\nClient not found!");
    }
}


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
        } else if (fields.size() == 3 && current_client != nullptr)
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