#include "PhoneBook.hpp"

/* 
* ******* Constructors *******
*/

Contact::Contact() {} ;

Contact::Contact(std::string fn, std::string ln, std::string n, std::string pn, std::string ds) {
        first_name = fn;
        last_name = ln;
        nickname = n;
        phone_number = pn;
        darkest_secret = ds;
};

/* 
* ******* Class Methods to set / get Private Attributes *******
*/

std::string Contact::get_first_name() const {
    return first_name;
};

std::string Contact::get_last_name() const {
    return last_name;
};

std::string Contact::get_nickname() const {
    return nickname;
};

std::string Contact::get_phone_number() const {
    return phone_number;
};

std::string Contact::get_darkest_secret() const {
    return darkest_secret;
};

void Contact::set_first_name(std::string str) {
    first_name = str;
};

void Contact::set_last_name(std::string str) {
    last_name = str;
};

void Contact::set_nickname(std::string str) {
    nickname = str;
};

void Contact::set_phone_number(std::string str) {
    phone_number = str;
};

void Contact::set_darkest_secret(std::string str) {
    darkest_secret = str;
};
        