#include "PhoneBook.hpp"

int main() {

    int counter_contact = 0;
    std::string cmd;
    PhoneBook phonebook;

    while (1) {

        std::cout << "Please enter your command : [ ADD / SEARCH / EXIT ]" << std::endl;
        if (!std::getline(std::cin, cmd))
            break;

        if (cmd == "ADD")
        {
            if (phonebook.add_contact(counter_contact))
                counter_contact += 1;
            else
                break;
        }

        else if (cmd == "SEARCH") {
            if (counter_contact == 0) {
                std::cout << "No contacts available. Please add a contact first." << std::endl;
            } else {
                phonebook.search_contact(phonebook.contact_list, counter_contact);
            }
        }

        else if (cmd == "EXIT")
            break ;
            
        else
            continue ;
    }
    return (0);
}