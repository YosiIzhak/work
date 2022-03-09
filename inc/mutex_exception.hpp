#include <string>
#include <iostream>
#include <exception>

namespace cpp{

class MutexExceptions : public std::exception
{
public:
    MutexExceptions( std::string const& a_function, int const& a_errorNumber);
    ~MutexExceptions()throw();
    virtual const char* what() const throw();
    std::string getFunctionName()const throw();
    int getErrorNumber()const throw();

private:
    std::string m_function;
    int m_errorNumber;
};

}//namespace cpp

#include "./inl/mutex_exception.hxx"