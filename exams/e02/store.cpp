#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <map>
#include "store.hpp"



Store::Store(size_t a_size)
: m_size(a_size)
{
   m_array = new int[a_size];
}
Store::Store(Store const& a_source)
: m_array(new int[a_source.m_size])
, m_size(a_source.m_size)
{
    memcpy(m_array, a_source.m_array, sizeof(a_source.m_array[0]) * a_source.m_size);
}
Store::~Store()
{
	delete[] m_array;
}
Store& Store::operator=(Store const& a_source)
{
    m_size = a_source.m_size;
    delete[] m_array;
    m_array = new int[a_source.m_size];
    memcpy(m_array, a_source.m_array, sizeof(a_source.m_array[0]) * a_source.m_size);
    return *this;
}

inline int Store::get(int const& a_index) const
{
    
    return m_array[a_index];
}
 
void Store::set(int const& a_index, int const a_value)
{
     m_array[a_index] = a_value;
}

inline void Store::reset(int const& value)
{
   

}


