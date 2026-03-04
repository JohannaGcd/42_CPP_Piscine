#include "phone.class.hpp"

int main() {

    int counter_contact = 0;
    std::string cmd;
    PhoneBook phonebook;

    while (1) {
        std::cout << "Please enter your command : [ ADD / SEARCH / EXIT ]" << std::endl;
        std::cin >> cmd;
        if (cmd == "ADD") {
            phonebook.add_contact(counter_contact);
            counter_contact += 1;
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