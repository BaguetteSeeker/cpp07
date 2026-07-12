#include "Array.hpp"

template<typename T>
void	printArr(Array<T> arr, std::string arrName) {
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arrName << "["<< i << "] → " << arr[i] << std::endl;
}

int main( void ) {
	try {

		std::cout << "\n-------- Creating from scratch test0 array --------\n" << std::endl;
		Array<int> test(5); 
		printArr(test, "test");
		
		std::cout << "\n-------- Assigning test1 from test0 array --------\n" << std::endl;
		Array<int> test1 = test;
		printArr(test1, "test1");
	
		std::cout << "\n--------  Tweaking values within test1 array --------\n" << std::endl;
		try { 
			test1[3] = 55; std::cout << "Index 3 modified" << std::endl; 
			test1[0] = 42; std::cout << "Index 0 modified" << std::endl;
			test[10] = 1; }
		catch (std::exception &e) {
			std::cout << "Index 10 couldn't be accessed" << std::endl;
			std::cout << "Exception:" << e.what() << std::endl;
		}
		printArr(test1, "test1");
	
		std::cout << "\n--------  Constructing test2 from test1 array --------\n" << std::endl;
		Array<int> test2 = Array<int>(test1);
		printArr(test2, "test2");
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	//Add float example with copy casting from int array
	return (0);
}