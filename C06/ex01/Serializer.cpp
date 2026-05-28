#include "Serializer.hpp"
#include <cstdint>

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t	address_ptr;

	address_ptr = reinterpret_cast<uintptr_t>(ptr);
	std::cout << "in method: " << address_ptr << std::endl;
	return (address_ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *restored_ptr = reinterpret_cast<Data *>(raw);

	std::cout << "in method: " << restored_ptr << std::endl;
	return (restored_ptr);
}