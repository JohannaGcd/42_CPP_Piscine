#include <string>
#include <iostream>

#ifndef HARL_H
    #define HARL_H

class Harl {

    private:
        void debug (void);
        void info (void);
        void warning (void);
        void error (void);

    public:
        void complain (std::string level);
// use static? const?
};

#endif