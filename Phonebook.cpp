/**
 * @file Phonebook.cpp
 * @author Daniel Wright
 * @date 2023-10-13
 * @brief Cpp file that includes all of the functions waiting to be called
 * 
 * .cpp file 
 */

#include "Phonebook.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iostream>

using namespace std;

Phonebook::Phonebook() : head(nullptr){} // initialize pointer

Phonebook::~Phonebook() { // Destructor For phonebook class
    while (head) {// loops as long as its in the phone book
        Entry* temp = head;
        head = head->next;
        delete temp;
    }
}
// Adds to the front of the phone book list
void Phonebook::push_front(const string& first_name, const string& last_name, const string& phone_number) {
    Entry* new_entry = new Entry{first_name, last_name, phone_number, head};
    head = new_entry;
}
// pushes it to the back
void Phonebook::push_back(const string& first_name, const string& last_name, const string& phone_number) {
    Entry* new_entry = new Entry{first_name, last_name, phone_number, nullptr};
    if (!head) {
        head = new_entry;
    } else {
        Entry* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_entry; // Set the 'next' of the last entry to the new entry.
    }
}
// Read phone book entries from a file and sort them as so
void Phonebook::read_from_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) { // If the file cannot be opened, report an error and return.
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string first_name, last_name, phone_number;
    while (file >> first_name >> last_name) {
        file.ignore(); // Ignore newline character
        getline(file, phone_number);

        insert_sorted(first_name, last_name, phone_number);
    }

    file.close(); // Close the file when finished reading.
}

void Phonebook::write_to_file(const string& filename) {
    ofstream file(filename); // Create an output stream and open the specified file for writing.
    if (!file.is_open()) {
        cerr << "Failed to open file for writing: " << filename << endl;
        return;
    }

    Entry* current = head;
    while (current) {  // Iterate through the phone book entries.
        file << current->first_name << ' ' << current->last_name << '\n' << current->phone_number << '\n';
        current = current->next;
    }

    file.close();
}
// Insert a new entry in a sorted order based on last names
void Phonebook::insert_sorted(const string& first_name, const string& last_name, const string& phone_number) {
    Entry* new_entry = new Entry{first_name, last_name, phone_number, nullptr};  // Create a new entry with the provided information.

    if (!head || last_name < head->last_name) {  // adds new entry at the beginning if meets criteria
        new_entry->next = head;
        head = new_entry;
    }
    else { // If the new entry's last name is not at the beginning, find its proper position.
        Entry* current = head;

        while (current->next && current->next->last_name < last_name) {
            current = current->next;
        }

        new_entry->next = current->next;
        current->next = new_entry; // Insert the new entry into the sorted position within the phone book.
    }
}
// Look up an entry by name (either first name or last name)
string Phonebook::lookup(const string& name) const {
    Entry* current = head;
    while (current) {
        if (current->last_name == name || current->first_name == name) {
            return current->phone_number;
        }
        current = current->next;
    }
    return "Not found";
}
// alternate way of looking up 
string Phonebook::reverse_lookup(const string& phone_number) const {
    Entry* current = head;
    while (current) {
        if (current->phone_number == phone_number) {
            return current->first_name + " " + current->last_name;
        }
        current = current->next;
    }
    return "Not found";
}
// Prints out a list of everyone in the phonebook entry
void Phonebook::print() const {
    Entry* current = head;
    while (current) {
        cout << "First Name: " << current->first_name << "\n";
        cout << "Last Name: " << current->last_name << "\n";
        cout << "Phone Number: " << current->phone_number << "\n\n";
        current = current->next;
    }
}
// Deletes the user from the phonebook entry
void Phonebook::delete_user(const string& first_name, const string& last_name) {
    Entry* current = head;
    Entry* prev = nullptr;

    while (current) { // loops through the names 
        if (current->first_name == first_name && current->last_name == last_name) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}
