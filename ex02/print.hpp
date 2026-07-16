#ifndef PRINT_HPP
# define PRINT_HPP

#include <iomanip>

template<typename T>
void	printArr(Array<T> arr, std::string arrName) {
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arrName << "["<< i << "] → " << arr[i] << std::endl;
}

template<typename T>
void	printTwoArr(const Array<T> &arr, const std::string &arrName, const Array<T> &arr2, const std::string &arrName2) {
	for (size_t  i = 0; i < std::max(arr.size(), arr2.size()); i++)
	{

		if (i < arr.size())
			std::cout << arrName  << "["<< i << "] → " << std::left << std::setfill(' ') << std::setw(10) << arr[i];
        else
            std::cout << std::left << std::setw(16 + (arrName.size())) << "";

        std::cout << " | ";

		if (i < arr2.size())
			std::cout << std::setw(5) << std::setfill(' ') << "" << arrName2 << "["<< i << "] → " << arr2[i];
		std::cout << std::endl;
	}
}

#endif