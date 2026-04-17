#include "MateriaSource.hpp"

static void initMaterias(AMateria **_materias) {
	for (int i = 0; i < 4; i++)
		_materias[i] = nullptr;
}

static void copyMaterias(AMateria *const *_src, AMateria **_dst) {
	for (int i = 0; i < 4; i++) {
		if (_src[i])
			_dst[i] = _src[i]->clone();
		else
			_dst[i] = nullptr;
	}
}

static void cleanMaterias(AMateria **_materias) {
	for (int i = 0; i < 4; i++)
		delete _materias[i];
}

MateriaSource::MateriaSource() : IMateriaSource() {
	initMaterias(_materias);
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource() {
	copyMaterias(other._materias, _materias);
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		cleanMaterias(_materias);
		copyMaterias(other._materias, _materias);
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	cleanMaterias(_materias);
}

void MateriaSource::learnMateria(AMateria *src) {
	if (!src)
		return;
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == nullptr) {
			_materias[i] = src->clone();
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	return nullptr;
}