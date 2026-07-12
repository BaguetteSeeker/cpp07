#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename Type_Array, typename Fn_T>
void	iter(Type_Array *array, const size_t siz, Fn_T fnc) {
	if (!array)
		return ;
	for (size_t i = 0; i < siz; i++)
		fnc(array[i]);
}

template<typename T>
void	incr(T &elm) {
	elm++;
}

template<typename T>
void	print(const T &elm) {
	std::cout << elm << std::endl;
}

#endif