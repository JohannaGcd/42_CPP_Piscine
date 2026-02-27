#include "phone.class.hpp"

void print_column(const std::string str) {
        if (str.size() < 10)
                std::cout << std::right << std::setw(10) << std::setfill(' ') << str << " | ";
        else
                std::cout << std::right << std::setw(10) << str.substr(0,9) + "." << " | ";
}

void display_contacts(Contact *contact_list) {
// how to iterate over the contact list. do i know how many contacts there are there? and if not, can i just iterate with [i] ?
// check " | " or '|' with no space?
        int i = 0;
        
        while (i < 8) {
                print_column(contact_list[i].first_name);
                print_column(contact_list[i].last_name);
                print_column(contact_list[i].nickname);
                print_column(contact_list[i].phone_number);
                print_column(contact_list[i].darkest_secret);
                std::cout << std::endl;
                i++;
        }
}

void PhoneBook::add_contact(int index) {

        std::string fn, ln, n, pn, ds;
        std::cout << "Please input the following values:" << std::endl;
        std::cout << "First name: ";
        std::cin >> fn;
        std::cout << "Last name: ";
        std::cin >> ln;
        std::cout << "Nickname: ";
        std::cin >> n;
        std::cout << "Phone number: "; // should i check for numerical char for this field?
        std::cin >> pn;
        std::cout << "Darkest secret: ";
        std::cin >> ds;

        Contact new_contact(fn, ln, n, pn, ds);
        if (index > 8)
                index = 0;
        contact_list[index] = new_contact;
}

bool validate_input(std::string char_index) {
        if (char_index.size() > 1)
                return false;
        if (std::all_of(char_index.begin(), char_index.end(), ::isdigit) == 0)
                return false;
        int int_index = std::stoi(char_index);
        if (int_index < 0 || int_index > 7)
                return false;
        return true;
}

void PhoneBook::search_contact(Contact *contact_list) {

        std::string char_index;

        if (contact_list != NULL) {
                display_contacts(contact_list);
                std::cout << "Enter the index of the entry you would like to display: " << std::endl;
                std::cin >> char_index;
                if (validate_input(char_index) == true) {   
                        int int_index = std::stoi(char_index);
                        print_column(contact_list[int_index].first_name);
                        print_column(contact_list[int_index].last_name);
                        print_column(contact_list[int_index].nickname);
                        print_column(contact_list[int_index].phone_number);
                        print_column(contact_list[int_index].darkest_secret);
                        std::cout << std::endl;
                }
                else {
                        std::cout << "You must enter a number between 0 and 8." << std::endl; // add try again?
                        std::cout << "You will be redirected to the main menu." << std::endl;
                        return ;
                }
        }
};




