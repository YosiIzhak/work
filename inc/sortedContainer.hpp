#include <iostream>
#include <cmath>
#include <cassert>
#include <iostream>
#include <vector>


namespace cpp{
class SortedContainer {
public:    
    SortedContainer(){} 
    virtual void insert(int x) = 0;
    virtual bool contains(int x) = 0;
    virtual void remove(int x) = 0;
    virtual int front() = 0;
    virtual int back() = 0;
    virtual void print(std::ostream&) = 0;

private:
    SortedContainer& operator=(SortedContainer const& other); 
    SortedContainer(SortedContainer const& other);       
};

} // namespace cpp




