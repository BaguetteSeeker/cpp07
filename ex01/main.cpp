#include "iter.hpp"

int main( void ) {
	int a[] = {0, 1, 2, 7, 6, 5};
	char str[] = "abc";

	std::cout << "State of int array before calling iter:" << std::endl;
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		std::cout << "Arr[" << i <<"] = " << a[i] << std::endl;

	iter(a, sizeof(a) / sizeof(a[0]), incr<int>);

	std::cout << "State of int array after calling iter:" << std::endl;
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		std::cout << "Arr[" << i <<"] = " << a[i] << std::endl;
	
	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "State of str array before calling iter:" << std::endl;
	for (size_t i = 0; i < sizeof(str) - 1; i++)
		std::cout << "Arr[" << i <<"] = " << str[i] << std::endl;

	iter(str, sizeof(str), incr<char>);

	std::cout << "State of str array after calling iter:" << std::endl;
	for (size_t i = 0; i < sizeof(str) - 1; i++)
		std::cout << "Arr[" << i <<"] = " << str[i] << std::endl;
	
	return (0);
}