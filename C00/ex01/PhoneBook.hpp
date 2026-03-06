#include <iostream>
#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <algorithm>

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

class PhoneBook {

    public:
        Contact contact_list[8];

        PhoneBook();

        bool add_contact( int index );
        void search_contact( Contact *contact_list, int counter_contact );
};

#endif