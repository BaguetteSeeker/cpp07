#ifndef PRINT_HPP
# define PRINT_HPP

#include <iomanip>

template<typename T>
void	printArr(Array<T> arr, std::string arrName) {
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arrName << "["<< i << "] → " << arr[i] << std::endl;
}

template<typename T>
void	printTwoArr(Array<T> arr, std::string arrName, Array<T> arr2, std::string arrName2) {
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arrName  << "["<< i << "] → " << std::left << std::setfill(' ') <<  std::setw(10) \
		<< arr[i] << "\t" << arrName2 << "["<< i << "] → " << arr2[i] << std::endl;
}

#endif