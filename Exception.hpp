#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <string>

class wrongValue : public std::exception
{
public:
	const char *what() const throw();
};

class divisionByZero : public std::exception
{
public:
	const char *what() const throw();
};

class noExit : public std::exception
{
public:
	const char *what() const throw();
};

class incorrectInput : public std::exception
{
public:
	const char *what() const throw();
};

#endif