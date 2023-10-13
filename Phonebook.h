/**
 * @file Phonebook.h
 * @author Daniel Wright
 * @date 2023-10-13
 * @brief .h file
 * 
 * file that declares all of the public and private variables used
 */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
using namespace std;

class Phonebook {
public:
    struct Entry {
      string first_name; //string stuff
      string last_name;
      string phone_number;
      Entry* next; // Linked list for storing entries
    };

    Phonebook();  // Constructor
   ~Phonebook(); // Destructor

    void push_front(const string& first_name, const string& last_name, const string& phone_number); //pushes entry to the front
    void push_back(const string& first_name, const string& last_name, const string& phone_number); // puts it at the end
    void read_from_file(const string& filename); // Read phone book entries from a file
    void write_to_file(const string& filename); // Write phone book entries to a file
    void insert_sorted(const string& first_name, const string& last_name, const string& phone_number); // Insert an entry in a sorted order
    string lookup(const string& name) const; // Look up an entry number
    string reverse_lookup(const string& phone_number) const;
    void print() const; // Print all entries in the phone book
    void delete_user(const string& first_name, const string& last_name); // Delete an entry by name

private:
    Entry* head; //head of linked list, it contans the Phone book entrys
    Entry* create_entry(const string& first_name, const string& last_name, const string& phone_number); //helps create new entrys
};

#endif 
