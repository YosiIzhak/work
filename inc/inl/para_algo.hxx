#ifndef PARA_ALGO_HXX
#define PARA_ALGO_HXX

#include <iostream>
#include <algorithm>
namespace cpp
{

template<typename T>
struct Arg
{
    Arg(std::vector<T> const& a_vec = 0, size_t a_from = 0, size_t a_end = 0)
    : m_vec(a_vec)
    , m_from(a_from)
    , m_end(a_end)
    {}

    std::vector<T> const& m_vec;
    size_t m_from;
    size_t m_end;
    
};

template<typename T>
void* sumElemnts(void* a_arg)
{
    Arg<T>* arg = static_cast<Arg<T>*>(a_arg);

    if(0 == arg)
    {   
        return 0;
    }     

    size_t from = arg->m_from;
    size_t end = arg->m_end; 
    std::vector<T> const& vec = arg->m_vec;

    T* sum = new T;
    for(size_t i = from; i < end; ++i)
    {
        *sum += vec[i];
    }

    return sum;  
}


template <typename T>
T sumVector(std::vector<T>& a_vec, size_t a_numOfThreads)
{
    size_t const part = a_vec.size()/a_numOfThreads;
    std::vector<pthread_t> threads(a_numOfThreads);

    size_t i = 0;
    
    for(i = 0; i < a_numOfThreads; i++)
    {
        Arg<T>* arg = new Arg<T>(a_vec, part*i ,part*i + part);
        ::pthread_create(&threads[i], 0, sumElemnts<T>, static_cast<void*>(arg));
    }

    Arg<T>* arg = new Arg<T>(a_vec, part*i ,a_vec.size());
    ::pthread_create(&threads[i], 0, sumElemnts<T>, static_cast<void*>(arg));

    T sum = 0;
    void* r;
    
    for(size_t i = 0; i < a_numOfThreads; i++)
    {
        ::pthread_join(threads[i], &r);
        sum += *static_cast<T*>(r);
    }
    
    ::pthread_join(threads[i], &r);
    sum += *static_cast<T*>(r);  
    return sum;
}
// template<typename T>
// void* sortElemnts(void* a_arg)
// {
//     Arg<T>* arg = static_cast<Arg<T>*>(a_arg);

//     if(0 == arg)
//     {   
//         return 0;
//     }     
   
//     size_t from = arg->m_from;
//     size_t end = arg->m_end; 
//     std::vector<T> const& vec = arg->m_vec;
//     std::vector<T>::iterator it = &vec[from];
//     std::vector<T>::iterator itEnd = &vec[end];
//     std::sort (it, itEnd);
//     return static_cast<void*>(arg);
// }

// template<typename T>
// size_t sortVector(std::vector<T> const& a_vec, size_t a_numOfThreads)
// {
//     size_t part = a_vec.size()/ a_numOfThreads;
//     size_t start = 0;
//     size_t end = part;
//     for(size_t i = 0; i < a_numOfThreads; ++i)
//     {
//        pthread_t thread;
//        void* r;
//        cpp::Arg<T>* arg = new cpp::Arg<T>(a_vec, start, end);
//        ::pthread_create(&thread, 0, sortElemnts<T>,  static_cast<void*>(arg));
//        ::pthread_join(thread, &r);
//        start = end;
//        end = end +part; 
//     }
   
//     while (a_numOfThreads > 1)
//     {
//          std::vector<T> merge(2 * part);
//          std::merge (first,first+5,second,second+5,merge.begin());
//     }
//     return sum;
// }


}//namespace cpp

#endif//PARA_ALGO_HXX




// #include <iostream>

// #include <pthread.h>

// #include <cmath>

// #include <unistd.h>

// #include <string.h>

// ​

// const size_t LOOP_TIMES = 1000 * 1000;

// ​

// int g;

// bool done = false;

// ​



// ​

// ​

// void* tikcer(void* arg)

// {

//     Mutex* pmutex = static_cast<Mutex*>(arg);

//     Mutex& mtx = *pmutex;

//     for (size_t i = 0; i < LOOP_TIMES; i++)

//     {

//         // ::usleep(15);

//         //std::cout << "tick " << i << '\n';

//         mtx.lock();

//         ++g;

//         mtx.unlock();

//     }

// ​

//     //pthread_exit(0);

//     done = true;

//     return 0;

// }

// ​

// ​

// struct Stuff {

//     Stuff(int a, int b) : x(a), y(b) {}

//     int x;

//     int y;

// };

// ​

// void* tock(void* arg)

// {

//     const char* msg = static_cast<const char*>(arg);

//     for (size_t i = 0; i < 5; i++)

//     {

//         // race on cout

//         std::cout << msg << '\n';

//     }

// ​

// ​

//     // return (void*)42;        // fishy but ok if you say say.

//     // return static_cast<void*>(42);    // error

//     return new Stuff(42, 888);

// }

// ​

// int main(){

//     Mutex mtx;

// ​

//     pthread_t thread[2];

//     int r = ::pthread_create(&thread[0], 0, tikcer, &mtx);

//     if(r != 0){

//         std::cout << "Failed to create new thread\n";

//     }

// ​

//     r = ::pthread_create(&thread[1], 0, tikcer, &mtx);

// ​

//     //::usleep(49);

//     // while(!done){   // busy wait + race condition

//     //     ;

//     // }

//     const char* msg = "Hello Threads: ";

//     pthread_t t2;

//     // r = ::pthread_create(&t2, 0, tock, msg );  // compiler error

//     // r = ::pthread_create(&t2, 0, tock, (void*)(msg) );  // work but uglly

// ​

//     //r = ::pthread_create(&t2, 0, tock, static_cast<void*>( const_cast<char*> (msg) ) );  // works but length

//     r = ::pthread_create(&t2, 0, tock,  const_cast<char*>(msg)  );  // recomended

// ​

// ​

// ​

//     //long answer = 0;

//     void *pv = 0;

// ​

//     ::pthread_join(t2, &pv);

// ​

//     //memcpy(&answer, &pv, sizeof(answer));

//     //std::cout << "answer is " << answer << '\n';

// ​

//     //Stuff* pstuf = (Stuff*)pv;

//     Stuff* pstuf = static_cast<Stuff*>(pv);

//     std::cout << "answer is " << pstuf->x << " " << pstuf->y <<  '\n';

// ​

//     ::pthread_join(thread[0], 0); // wait and clean up OS related stuff

//     ::pthread_join(thread[1], 0); // wait and clean up OS related stuff

//     std::cout << "g is : " << g << '\n';

// ​

//     // size_t n = 10000000;

//     // double s = 0;

//     // while(n-- > 0){

//     //     s += ::sin(2.0 * M_PI/ n);

//     // }

// ​

//     std::cout << "done compute\n";

// ​

//     return 0;

// ​

//     //exit(42);

//     //std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

// }

