#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

template<typename T>
class Array {

	private:
		T				*_arr;
		unsigned int	_size;

	public:
		Array( void );
		Array( unsigned int n);
		Array( Array const &copy );
		~Array( void );
		Array 	&operator=( const Array &src );
		T		&operator[]( unsigned int i );
		T const	&operator[]( unsigned int i ) const;

		unsigned int	size( void ) const;

		class	OutOfBounds: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

# include "Array.tpp"

#endif