
namespace cpp{
inline BlockQueueExceptions::BlockQueueExceptions( std::string const& a_function, int const& a_errorNumber)
: m_function(a_function)
, m_errorNumber(a_errorNumber)
{

}

inline BlockQueueExceptions::~BlockQueueExceptions() throw()
{

}

inline const char* BlockQueueExceptions::what() const throw()
{
    return "blockQueue fail!\n";
}

inline std::string BlockQueueExceptions::getFunctionName() const throw()
{
    return m_function;
}

inline int BlockQueueExceptions:: getErrorNumber()const throw()
{
    return m_errorNumber;
}

}//namespace cpp