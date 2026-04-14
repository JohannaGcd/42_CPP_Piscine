#ifndef BRAIN_H
 # define BRAIN_H

#include <string>

#define IDEAS_MAX 100

class Brain {
	private:
		std::string ideas[IDEAS_MAX];
	
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		void setIdea(std::string idea, int index);
		std::string getIdea(int index) const;
};

#endif