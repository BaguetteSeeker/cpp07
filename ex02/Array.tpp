#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array( void ) : _arr(NULL), _size(0) {

}

template <typename T>
Array<T>::Array( unsigned int n ) : _arr(new T[n]), _size(n) {
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < n; i++)
		_arr[i] = T(rand()) % T(99999);
}

template <>
Array<float>::Array(unsigned int n) : _arr(new float[n]), _size(n) {
    for (unsigned int i = 0; i < n; ++i)
        _arr[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 99999.0f;
}

template <>
Array<double>::Array(unsigned int n) : _arr(new double[n]), _size(n) {
    for (unsigned int i = 0; i < n; ++i)
        _arr[i] = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) * 99999.0;
}

template <typename T>
Array<T>::Array( const Array &copy ) : _arr(new T[copy._size]), _size(copy._size) {
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = copy._arr[i];
}

template <typename T>
Array<T>::~Array( void ) {
	delete [] _arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src) {
	if (this != &src) {
        T *tmp = new T[src._size];
        for (unsigned int i = 0; i < src._size; ++i)
            tmp[i] = src._arr[i];
        delete [] _arr;
        _arr = tmp;
        _size = src._size;
	}
	return (*this);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= this->size())
		throw	OutOfBounds();
	return (_arr[index]);
	
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	return (const_cast<T &>(static_cast<const Array &>(*this)[index]));
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (this->_size);
}

template <typename T>
const char *Array<T>::OutOfBounds::what() const throw() {
	return ("Index out of bounds");
}

#endif
