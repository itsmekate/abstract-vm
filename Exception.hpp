#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <string>

class notInt8 : public std::exception
{
public:
	const char *what() const throw();
};

class notInt16 : public std::exception
{
public:
	const char *what() const throw();

};

class notInt32 : public std::exception
{
public:
	const char *what() const throw();
};

class notFloat : public std::exception
{
public:
	const char *what() const throw();
};

class notDouble : public std::exception
{
public:
	const char *what() const throw();
};

class divisionByZero : public std::exception
{
public:
	const char *what() const throw();
};

class lexicalError : public std::exception
{
public:
	const char *what() const throw();
};

//exception for underflow TO DO!

#endif