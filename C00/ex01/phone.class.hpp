#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

class Contact {

    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

        Contact() {} ;

        Contact(std::string fn, std::string ln, std::string n, std::string pn, std::string ds) {
            this->first_name = fn;
            this->last_name = ln;
            this->nickname = n;
            this->phone_number = pn;
            this->darkest_secret = ds;
        };
};

class PhoneBook {

    public:
        Contact contact_list[8];

        PhoneBook() {};

        void add_contact( int index );
        void search_contact( Contact *contact_list, int counter_contact );
};

