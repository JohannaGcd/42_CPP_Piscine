#ifndef MATERIASOURCE_H
 # define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_materias[4];
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource& operator=(const MateriaSource &other);
		~MateriaSource();

		virtual void learnMateria(AMateria *) override;
		virtual AMateria *createMateria(std::string const &type) override;
};

#endif


