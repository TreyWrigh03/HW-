/**
 * @file main.cpp
 * @author Daniel Wright
 * @date 2023-10-13
 * @brief main.cpp the front end
 * 
 * takes in all the stuff from the classes and displays it to the user and promps a menu using the while loop that the user can use to navigate the phonebook
 */

#include "Phonebook.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
  
  Phonebook phonebook; // Declaring Class in main
  int choice;

  int answer = 0; // for the while loop
  
  while (answer != 8) { // makes it so that the menu will keep displaying 
    cout << "Welcome to the UTM Phonebook!\n"
         << "1 Read a phonebook from a file\n"
         << "2 Write the phonebook to a file\n"
         << "3 Print the phonebook\n"
         << "4 Search for a user's phone number\n"
         << "5 Reverse lookup by phone number\n"
         << "6 Add a user\n"
         << "7 Delete a user\n"
         << "8 Exit this program\n"
         << "Please enter your choice now: ";
    cin >> choice; //user input
    cout << "\n"; // i like newlines and spaces they're pretty
    
    if(choice == 1){ // Reads the file in, kinda like scanning documents
      string filename;
      cout << "Enter the file name to read from: ";
      cin >> filename;
      phonebook.read_from_file(filename);
      cout << "Phonebook read from file.\n";
      cout << "\n";
    }
    
    else if(choice == 2){ // writes everyting that has been read in into a file of its own, like scanning abunch of documents and putting them in the same folder.
      string filename;
      cout << "Enter the file name to write to: ";
      cin >> filename;
      phonebook.write_to_file(filename);
      cout << "Phonebook written to file.\n";
      cout << "\n";
    }
    
    else if(choice == 3){ // prints out said phonebook
      phonebook.print();
      cout << "\n";
    }
    
    else if (choice == 4) { // search a users phone number by their last name
      string name;
      cout << "Enter the last name to search: ";
      cin >> name;
      string number = phonebook.lookup(name);
      cout << "Phone number: " << number << "\n";
      cout << "\n";
    }
    
    else if (choice == 5) { // Lookup someone by phone number
      string number;
      cout << "Enter the phone number to search: ";
      cin >> number;
      string name = phonebook.reverse_lookup(number);
      cout << "Name: " << name << "\n";
      cout << "\n";
    }

    else if (choice == 6) { // add new person to the registry
      string first_name, last_name, phone_number;
      cout << "Enter first name: ";
      cin >> first_name;
      cout << "Enter last name: ";
      cin >> last_name;
      cout << "Enter phone number: ";
      cin >> phone_number;
      phonebook.push_back(first_name, last_name, phone_number);
      cout << "User added.\n";
      cout << "\n";
    }
    
    else if (choice == 7) { // delete person from the book
      string first_name, last_name;
      cout << "Enter the first name to delete: ";
      cin >> first_name;
      cout << "Enter the last name to delete: ";
      cin >> last_name;
      phonebook.delete_user(first_name, last_name);
      cout << "User deleted.\n";
      cout << "\n";
    }

    else if(choice == 8){ //close program
      cout << "Exiting the program." <<endl;
      cout << "\n";
      return 0;
    }

    else{ // just incase an alien character was entered 
      cout << "Invalid choice. Please enter a valid option.\n" <<endl;
    }
    
  }
  return 0;
} 
 
    
