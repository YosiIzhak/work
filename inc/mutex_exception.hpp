

#ifndef MUTEX_EXCEPTIONS_HPP

#define MUTEX_EXCEPTIONS_HPP


#include <string>

#include <stdexcept>

#include <errno.h>


namespace cpp

{


//Mutex exceptions

struct MutexExceptions: public std::exception

{

    MutexExceptions();

    virtual const char* what() const throw();

};


struct MutexInitExceptions: public MutexExceptions

{

    MutexInitExceptions();

    virtual const char* what() const throw();

};


struct MutexLockExceptions: public MutexExceptions

{

    MutexLockExceptions();

    virtual const char* what() const throw();

};


}//namespace cpp


#endif//MUTEX_EXCEPTIONS_HPP

