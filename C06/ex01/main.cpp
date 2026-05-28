#include "Serializer.hpp"

int	main(void)
{
	Data originalData;
	originalData.value = 20;

	uintptr_t serializedPtr;

	serializedPtr = Serializer::serialize(&originalData);
	std::cout << "in main: " << serializedPtr << std::endl;

	Data restoredData;
	Data *restoredPtr = &restoredData;
	restoredPtr = Serializer::deserialize(serializedPtr);
	std::cout << "int main: " << restoredPtr << std::endl;
	std::cout << "int main: " << restoredPtr->value << std::endl;
}