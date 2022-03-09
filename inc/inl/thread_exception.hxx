#include <iostream>

inline ThreadExceptions::ThreadExceptions( std::string const& a_function, int const& a_errorNumber)
: m_function(a_function)
, m_errorNumber(a_errorNumber)
{

}

inline ThreadExceptions::~ThreadExceptions() throw()
{

}

inline const char* ThreadExceptions::what() const throw()
{
    return "Thread fail!\n";
}

inline std::string ThreadExceptions::getFunctionName() const throw()
{
    return m_function;
}

inline int ThreadExceptions:: getErrorNumber()const throw()
{
    return m_errorNumber;
}