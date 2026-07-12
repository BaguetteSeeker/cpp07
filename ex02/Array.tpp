#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : _arr(NULL), _size(0) {

}

template <typename T>
Array<T>::Array( unsigned int n ) : _arr(new T[n]), _size(n) {
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < n; i++)
		this->_arr[i] = rand();
}

template <typename T>
Array<T>::Array( const Array &copy ) : _arr(new T[copy._size]), _size(copy._size) {
	for (size_t i = 0; i < this->_size; i++)
		this->_arr[i] = copy._arr[i];
}

template <typename T>
Array<T>::~Array( void ) {
	delete [] _arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src) {
	if (this != &src) {
		delete [] _arr;
		this->_arr = new T[src->size()];
		this->_size = src.size();
		for (size_t i = 0; i < this->_size; i++)
			this->_arr[i] = src->_arr[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index > this->size())
		throw	OutOfBounds();
	return (_arr[index]);
	
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (this->_size);
}

template <typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return ("Index out of bounds");
}
