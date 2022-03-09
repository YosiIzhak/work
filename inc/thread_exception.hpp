#include <string>
#include <iostream>
#include <exception>


class ThreadExceptions : public std::exception
{
public:
    ThreadExceptions( std::string const& a_function, int const& a_errorNumber);
    ~ThreadExceptions()throw();
    virtual const char* what() const throw();
    std::string getFunctionName()const throw();
    int getErrorNumber()const throw();

private:
    std::string m_function;
    int m_errorNumber;
};

#include "./inl/thread_exception.hxx"