#include "Serializer.hpp"
#include <cstdint>

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t	address_ptr;

	address_ptr = reinterpret_cast<uintptr_t>(ptr);
	return (address_ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *restored_ptr = reinterpret_cast<Data *>(raw);
	return (restored_ptr);
}