
namespace cpp{
inline MutexExceptions::MutexExceptions( std::string const& a_function, int const& a_errorNumber)
: m_function(a_function)
, m_errorNumber(a_errorNumber)
{

}

inline MutexExceptions::~MutexExceptions() throw()
{

}

inline const char* MutexExceptions::what() const throw()
{
    return "Mutex fail!\n";
}

inline std::string MutexExceptions::getFunctionName() const throw()
{
    return m_function;
}

inline int MutexExceptions:: getErrorNumber()const throw()
{
    return m_errorNumber;
}

}//namespace cpp