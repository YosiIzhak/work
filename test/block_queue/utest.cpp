#include "mu_test.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ostream> 
#include <iostream>
#include <unistd.h>
#include <queue>
#include "thread.hpp"
#include "mutex.hpp"
#include "block_queue.hpp"

mt::Mutex mtx;
size_t global;

void* increase(void*)
{
    size_t count = 9000000;
    for (size_t i = 0; i < count; i++)
    {
        mtx.lock();
        ++global;
        mtx.unlock();
    }
    return 0;
}

BEGIN_TEST(check_thread)
    using namespace std;
    
    mt::Thread t1(0, increase, 0); 
    mt::Thread t2(0, increase, 0);

    t1.join();
    // cout << "global: " << global << "\n";
    t2.join();
    cout << "global: " << global << "\n";

    ASSERT_PASS();
END_TEST


template <typename T>
struct Parameter
{
    Parameter(mt::BlockQueue<T>& a_queue, size_t a_amount)
    : m_queue(a_queue)
    , m_amount(a_amount)
    {}

    mt::BlockQueue<T>& m_queue;
    size_t m_amount;
};

template <typename T>
void* enqueuePlus(void* a_parameter)
{
    Parameter<T>* par = static_cast<Parameter<T>* >(a_parameter);
    T amount = par->m_amount;
    mt::BlockQueue<T>& que = par->m_queue;

    for (T i = 1; i <= amount; i++)
    {
        que.enqueue(i);
    }
    return 0;
}

template <typename T>
void* enqueueMinus(void* a_parameter)
{
    Parameter<T>* par = static_cast<Parameter<T>* >(a_parameter);
    T amount = par->m_amount;
    mt::BlockQueue<T>& que = par->m_queue;

    for (T i = 1; i <= amount; i++)
    {
        que.enqueue(i * -1);
    }
    return 0;
}

BEGIN_TEST(enqueue_2_threads)
    using namespace std;
    using namespace mt;
    const size_t size = 100; 
    BlockQueue<int> que(size);

    Parameter<int> param(que, size/2);
   
    Thread t1(0, enqueuePlus<int>, static_cast<void*>(&param)); 
    Thread t2(0, enqueuePlus<int>, static_cast<void*>(&param)); 

    t1.join();
    // cout << "size: "<< que.size() <<'\n';
    t2.join();
     //cout << "size: "<< que.size() <<'\n';
    
    ASSERT_EQUAL(que.size(), size);
    //ASSERT_PASS();
END_TEST


BEGIN_TEST(enqueue_5_threads)
    using namespace std;
    using namespace mt;
     using namespace mt;
    const size_t size = 1000; 
    BlockQueue<int> que(size);

    Parameter<int> param(que, size/5);
   
    Thread t1(0, enqueuePlus<int>, static_cast<void*>(&param)); 
    Thread t2(0, enqueuePlus<int>, static_cast<void*>(&param)); 
    Thread t3(0, enqueuePlus<int>, static_cast<void*>(&param)); 
    Thread t4(0, enqueuePlus<int>, static_cast<void*>(&param)); 
    Thread t5(0, enqueuePlus<int>, static_cast<void*>(&param)); 

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    // cout << "size: "<< que.size() <<'\n';
  
     ASSERT_EQUAL(que.size(), size);
    ASSERT_PASS();
END_TEST

size_t amount;
template <typename T>
void* dequeueMany(void* a_parameter)
{
    Parameter<T>* par = static_cast<Parameter<T>* >(a_parameter);
    amount = par->m_amount;
    mt::BlockQueue<T>& que = par->m_queue;
    T data = T();
    T prevPos = 0;
    T prevNeg = 0;
    while (amount > 0)
    {
        bool ok = false;
       
        data = que.dequeue(ok);
        if(ok)
        {
           if (data > 0)
           {
               if(data > prevPos)
               {
                   amount--;
                   prevPos = data;
               }
               else
               {
                 break;
               }
           }
           if (data < 0)
           {
               if(data < prevNeg)
               {
                   amount--;
                   prevNeg = data;
               }
               else
               {
                 break;
               }
           }
       }
        else
        {
            break;
        }
    }
return 0;
}

BEGIN_TEST(dequeue_2_threads)
    using namespace std;
    using namespace mt;
    const size_t size = 1000000; 
    BlockQueue<int> que(size);

    Parameter<int> param(que, size);

    enqueuePlus<int>(static_cast<void*>(&param));
    ASSERT_EQUAL(size, que.size());

    Parameter<int> removeHalf(que, size/2);
    
    Thread t1(0, dequeueMany<int>, static_cast<void*>(&removeHalf)); 
    Thread t2(0, dequeueMany<int>, static_cast<void*>(&removeHalf)); 
   
    t1.join();
    // cout << "size: "<< que.size() <<'\n';
    t2.join();
    // cout << "size: "<< que.size() <<'\n';

    ASSERT_EQUAL(que.size(), 0);
    ASSERT_PASS();
END_TEST



BEGIN_TEST(two_enqueue_one_dequeue)
    using namespace std;
    using namespace mt;
    const size_t size = 1000000; 
    BlockQueue<int> que(size);

    Parameter<int> param(que, size/2);
   
    Thread t1(0, enqueuePlus<int>, static_cast<void*>(&param)); 
    Thread t2(0, enqueueMinus<int>, static_cast<void*>(&param)); 
 
    t1.join();
    t2.join();
    

    Parameter<int> remove(que, size);

    Thread t3(0, dequeueMany<int>, static_cast<void*>(&remove)); 
   
    t3.join();
   
    ASSERT_EQUAL(que.size(), 0);
   
END_TEST

BEGIN_SUITE(不耻下问 this is a description)
    TEST(check_thread)
    TEST(enqueue_2_threads)
    TEST(enqueue_5_threads)
    TEST(dequeue_2_threads)
    TEST(two_enqueue_one_dequeue)

END_SUITE