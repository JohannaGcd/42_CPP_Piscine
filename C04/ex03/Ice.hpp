#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

        public:
            Ice();
            Ice(const Ice& other);
            Ice& operator=(const Ice& other);
            ~Ice();

            Ice* clone() const override;
            void use(ICharacter &target) override;
};

#endif