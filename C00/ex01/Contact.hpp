#ifndef __CONTACT_H__
#define __CONTACT_H__

class Contact {

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact();
        Contact(std::string fn, std::string ln, std::string n, std::string pn, std::string ds);

        std::string get_first_name() const ;
        std::string get_last_name() const ;
        std::string get_nickname() const ;
        std::string get_phone_number() const ;
        std::string get_darkest_secret() const ;;

        void set_first_name(std::string str) ;
        void set_last_name(std::string str) ;
        void set_nickname(std::string str) ;
        void set_phone_number(std::string str) ;
        void set_darkest_secret(std::string str) ;
    
};

#endif