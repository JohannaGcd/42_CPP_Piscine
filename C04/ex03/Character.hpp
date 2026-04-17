# ifndef CHARACTER_H
 # define CHARACTER_H

#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter {

		private:
			std::string _name;
			AMateria *_inventory[4];
			AMateria *_floor[100];

		public:
			Character(std::string name);
			Character(const Character &other);
			Character &operator=(const Character &other);
			~Character();

			std::string const &getName() const override;
			void equip(AMateria *m) override;
			void unequip(int idx) override;
			void use(int idx, ICharacter &target) override;
			void cleanFloor(void);
};

#endif