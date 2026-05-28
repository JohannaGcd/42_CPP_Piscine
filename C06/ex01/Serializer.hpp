#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>

struct	Data
{
	int	value;
};

class Serializer
{
  private:
	Serializer();
	~Serializer();

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif