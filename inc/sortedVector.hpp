#include <iostream>
#include <cmath>
#include <cassert>
#include <iostream>
#include <vector>

namespace cpp{

class SortedVector : public SortedContainer {
public:
    SortedVector() {}
    
    ~SortedVector(){} 

    void insert(int x); 
    bool contains(int x);
    void remove(int x);
    int front();
    int back();
    std::ostream& print(std::ostream& a_ostream);


private:
    std::vector<int> m_vec;              
};

} // namespace cpp