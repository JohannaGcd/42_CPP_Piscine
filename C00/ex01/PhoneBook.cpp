#include "PhoneBook.hpp"

/* 
* ******* Constructor *******
*/

PhoneBook::PhoneBook() {} ;

/* 
* ******* Helper Functions - Display *******
*/

static void print_column_full(const std::string title, const std::string str) {

        std::cout << title << std::right << std::setfill(' ') << str << std::endl;
};

static void print_column_trunc(const std::string str) {

        if (str.size() < 10)
                std::cout << std::right << std::setw(10) << std::setfill(' ') << str << " | ";
        else
                std::cout << std::right << std::setw(10) << str.substr(0,9) + "." << " | ";
}

void display_contacts(Contact *contact_list, int counter_contact) {

        int i = 0;

        while (i < std::min(counter_contact, 8)) {
                print_column_trunc(std::to_string(i));
                print_column_trunc(contact_list[i].get_first_name());
                print_column_trunc(contact_list[i].get_last_name());
                print_column_trunc(contact_list[i].get_nickname());
                std::cout << std::endl;
                i++;
        }
};

/* 
* ******* Helper Functions - Validating Input *******
*/

static bool is_blank(const std::string &s) {

        for (size_t i = 0; i < s.size(); i++) {
                if (!std::isspace(s[i]))
                    return false;
        }
        return true;
}

static bool prompt_non_empty(const std::string &title, std::string &saved) {

        while (true) {
                std::cout << title;
                if (!std::getline(std::cin, saved))
                        return false;
                if (!is_blank(saved))
                        return true;
                std::cout << "Field cannot be empty. Try again.\n";
        }
}

static bool validate_input(std::string char_index, int counter_contact) {

        if (char_index.size() > 1)
                return false;
        if (std::all_of(char_index.begin(), char_index.end(), ::isdigit) == 0)
                return false;

        int int_index = std::stoi(char_index);
        if (int_index < 0 || int_index >= counter_contact || int_index >= 8)
                return false;

        return true;
};

/* 
* ******* Class Methods *******
*/

bool PhoneBook::add_contact( int counter_contact ) {

        int index = counter_contact % 8 ;
        std::string fn, ln, n, pn, ds;

        std::cout << "Please input the following values: \n";

        if (!prompt_non_empty("First name: ", fn)) return false;
        if (!prompt_non_empty("Last name: ", ln)) return false;
        if (!prompt_non_empty("Nickname: ", n)) return false;
        if (!prompt_non_empty("Phone number: ", pn)) return false;
        if (!prompt_non_empty("Darkest secret: ", ds)) return false;

        Contact new_contact(fn, ln, n, pn, ds);
        contact_list[index] = new_contact;

        return true;
}

void PhoneBook::search_contact(Contact *contact_list, int counter_contact) {

        std::string char_index;

        if (contact_list != NULL) {

                display_contacts(contact_list, counter_contact);
                
                std::cout << "Enter the index of the entry you would like to display: " << std::endl;
                if (!std::getline(std::cin, char_index) || char_index.empty()|| is_blank(char_index)) {
                        std::cout << "Invalid input: empty line" << std::endl;
                        return;
                };

                if (validate_input(char_index, counter_contact) == true) {   
                        int int_index = std::stoi(char_index);
                        print_column_full("First name: ", contact_list[int_index].get_first_name());
                        print_column_full("Last name: ", contact_list[int_index].get_last_name());
                        print_column_full("Nickname: ", contact_list[int_index].get_nickname());
                        print_column_full("Phone number: ", contact_list[int_index].get_phone_number());
                        print_column_full("Darkest secret: ", contact_list[int_index].get_darkest_secret());
                        std::cout << std::endl;
                }
                else {
                        std::cout << "You must enter a number between 0 and (available saved indexes:) " << counter_contact - 1   << "." << std::endl;
                        return ;
                }
        }
}




