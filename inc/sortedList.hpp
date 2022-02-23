#include <iostream>
#include <cmath>
#include <cassert>
#include <iostream>
#include <listr>
#include "sortedContainer.hpp"

class SortedList : public SortedContainer {
public:
    SortedList() {}
    
    ~SortedList(){} 

    void insert(int x); 
    bool contains(int x);
    void remove(int x);
    int front() ;
    int back();
    std::ostream& print(std::ostream& a_ostream);

private:
    std::list<int> m_vec;              
};