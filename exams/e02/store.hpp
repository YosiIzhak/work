#ifndef STORE_H
#define STORE_H
#include <cstdlib> 


    
class Store
{
public:
    Store(size_t a_size);
    Store(Store const& a_source);
    Store& operator=(Store const& a_source);
    ~Store();
   
    int get(int const& index) const;
    void set(int const& index, int const value);
    void reset(int const& value);

private:
    int* m_array;
    size_t m_size;

};

#endif