#include "Serializer.hpp"

int	main(void)
{
	Data		originalData;
	uintptr_t	serializedPtr;
	Data		restoredData;
	Data		*restoredPtr;

	originalData.value = 20;
	serializedPtr = Serializer::serialize(&originalData);
	std::cout << "[ ORIGINAL DATA ]: " << std::endl;
	std::cout << "Address:		" << &originalData << std::endl;
	std::cout << "Value:		" << originalData.value << std::endl;
	restoredPtr = &restoredData;
	restoredPtr = Serializer::deserialize(serializedPtr);
	std::cout << "[ DESERIALIZED DATA ] " << std::endl;
	std::cout << "Address:		" << restoredPtr << std::endl;
	std::cout << "Value:		" << restoredPtr->value << std::endl;
}
