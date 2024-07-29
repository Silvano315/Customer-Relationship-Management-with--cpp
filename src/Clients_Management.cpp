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
        throw runtime_error("Client not found!");
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
        string name, surname, phone, email, address, city;
        if (getline(ss, name, ',') &&
            getline(ss, surname, ',') &&
            getline(ss, phone, ',') &&
            getline(ss, email, ',') &&
            getline(ss, address, ',') &&
            getline(ss, city, ','))
        {
            // new to handle clients dynamically
            current_client = new Client(name, surname, phone, email, address, city);  
            add_client(*current_client); 
        } 
        else if (current_client != nullptr)
        {
            ss.clear();
            ss.str(line);
            string type, date, note;
            if (getline(ss, type, ',') &&
                getline(ss, date, ',') &&
                getline(ss, note, ','))
            {
                current_client->add_interaction(Interaction(type, date, note));
            }  
        }
    }
    file.close();
}