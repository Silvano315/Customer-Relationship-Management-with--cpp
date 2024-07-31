# Customer Relationship Management with C++

## Table of Contents
1. [Introduction](#introduction)
2. [Data Structure](#data-structure)
3. [Methods](#methods)
4. [Final Implementation](#final-implementation)
5. [Requirements](#requirements)


## Introduction

This repository is the first project of the master's degree in AI Engineering with [Profession AI](https://profession.ai), all the credits for the requests and idea go to this team.

InsuraPro Solutions is dedicated to improving the efficiency and quality of customer service for insurance companies by developing an advanced Customer Relationship Management (CRM) system that facilitates the management of customer information and their interactions with the company. Insurance businesses need a systematic, centralized way to manage customer information and track interactions. Many current systems are fragmented or non-user-friendly, hindering operational effectiveness and customer satisfaction. 

Objective:
- InsuraPro Solutions will offer an interactive console application developed in C++ that will allow users to manage customer information and their interactions efficiently and intuitively, thus improving customer service and internal management.

In this project, I will implement:
- **OOP in C++**: Implement OOP concepts for a robust and flexible structure.
- **Data Structure**: Create a data structure to store information about customers and their interactions.
- **User Interface**: Develop an interactive and intuitive command line interface.

Features to integrate:
1. Adding a Customer: Inserting new customers into the CRM.
2. Viewing Customers: View all current customers.
3. Editing a Customer: Edit the details of an existing customer.
4. Deleting a Customer: Remove customers from the CRM.
5. Search for a Customer: Search for customers by name or surname.
6. Interaction Management: Add, view and search for interactions for each customer (interactions mean appointments by the sales force and signed contracts).
7. Saving and Loading Data: Save customer and interaction data to a file (text or CSV) and load it at startup.
8. User Interface: The interface will be command-line based, with a main menu offering clear options for all necessary operations, ensuring a smooth and accessible user experience.


## Data Structure

In this section, I describe the main data structures used in our program: `Client` and `Interaction`. Each `Client` can have a list of `Interaction` objects. This relationship is implemented by including a vector of `Interaction` within the `Client` class. This allows me to track all interactions a client has had.

### Client

The `Client` class represents a customer and comprises the following fields:

- **name**: `string` - The client's first name.
- **surname**: `string` - The client's last name.
- **phone**: `string` - The client's phone number.
- **email**: `string` - The client's email address.
- **address**: `string` - The client's residential address.
- **city**: `string` - The client's city of residence.
- **interactions**: `vector<Interaction>` - A list of interactions associated with the client.

### Interaction

The `Interaction` class represents a single interaction with a client and comprises the following fields:

- **type**: `string` - The type of interaction (e.g., call, email, meeting).
- **date**: `string` - The date of the interaction in the format `YYYY-MM-DD`.
- **note**: `string` - Additional notes about the interaction.


## Methods

The project is organized into several files, each serving a specific role in managing clients, interactions, and the overall functionality of the CRM system. The key files are:

1. **`Cliente.h` and `Cliente.cpp`**: These files define and implement the `Client` class. This class handles all client-related information, such as personal details and interactions. It includes methods for managing and accessing client data.

2. **`Interazione.h` and `Interazione.cpp`**: These files define and implement the `Interaction` class. This class manages interaction details, including the type, date, and notes associated with each interaction.

3. **`GestioneClienti.h` and `GestioneClienti.cpp`**: These files define and implement the `ClientsManagement` class. This class is responsible for handling operations related to clients, such as searching, editing, and deleting clients. It also manages collections of clients and their interactions.

4. **`Validation_utils.h` and `Validation_utils.cpp`**: These files provide utility functions for validating input data. They include methods for checking constraints on strings, phone numbers, email addresses, and dates using regular expressions.

### Purpose of Header and CPP Files

- **Header Files (`.h`)**: Header files are used to declare the classes, methods, and member variables. They provide the interface for the classes and define the public methods and data members that can be used by other parts of the program.
- **Source Files (`.cpp`)**: Source files implement the methods declared in the header files. They contain the actual code that performs the operations defined in the class interfaces. By separating the implementation from the declarations, the code becomes more modular and easier to manage.

There are some advantages of this structure:

- **Modularity**: Separating the code into different files based on functionality allows for better organization and maintainability. Changes in one module do not directly affect others.
- **Reusability**: Utility functions and validation checks are kept separate in their respective files, making them reusable across different parts of the project.
- **Clarity**: Each class and method has a clear and focused responsibility, making the codebase easier to understand and navigate.
- **Encapsulation**: Header files provide a clear interface for each class, while source files contain the implementation details, promoting encapsulation and abstraction.


## Final Implementation

The command-line interface (CLI) allows users to interact with the CRM system through various commands. The interface is designed to be intuitive and user-friendly, guiding the user through operations such as adding, editing, viewing, and deleting client and interaction information.

The `main` function sets up the application and starts the user interface loop, allowing users to select and perform different operations.

`utils.h` declares functions for showing the menu, handling user input, and selecting clients from a list. `utils.cpp` implements these functions. These files provide utility functions to facilitate user interaction and input handling.

The CRM system supports data persistence by saving client information to a CSV file located in the `data` directory. Client data is saved to [data/clients.csv](src/data/) using the `save_data` method. Upon starting the application, the `load_data` method can be used to read client data from `data/clients.csv`.


## Requirements

In order to create the file .exe for this project [my_program](src/my_program), in the command prompt go to the folder where you cloned this project and in the [src folder](src):

```bash
g++ -std=c++11 -o my_program main.cpp Client.cpp Clients_Management.cpp Interaction.cpp utils.cpp Validation_utils.cpp
```