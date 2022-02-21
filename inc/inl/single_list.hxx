#ifndef LINKED_LIST_HXX
#define LINKED_LIST_HXX

inline size_t LinkedList::size() const
{
    return m_size;
}
 
inline bool LinkedList::isEmpty() const
{
    return size() == 0;
}

inline Iterator LinkedList::begin() const
{
    return Iterator(m_head);
}

inline Iterator LinkedList::end() const
{
    return Iterator(m_sentinal);
}

inline bool Iterator::notEqual(Iterator const &a_itr) const
{
    return a_itr.m_current != m_current;
}

inline bool Iterator::equal(Iterator const& a_itr) const
{
    return a_itr.m_current == m_current;
}
inline Iterator Iterator::operator++(int) 
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

inline Iterator& Iterator::operator++() 
{
  return next();
}

inline int Iterator::operator*() const
{
    return data();
}

inline Node* Iterator::operator->() const
{
    return m_current;
}

 
#endif  // LINKED_LIST_HXX




// #include <iostream>

// #include <vector>

// #include <map>

// #include <string>

// #include <utility>

// #include <algorithm>

// #include <queue>

// #include <iterator>

// #include <cassert>

// ​

// ​

// struct Kernel { 

//     Kernel(int n) : data(n) {}    

//     int data;

//     int fx()  { return 7; }

// };

// ​

// std::ostream& operator<<(std::ostream& os, Kernel const & k){

//     return os << k.data;

// }

// ​

// struct SeqIter {

//     SeqIter() : n (0) {}

//     Kernel const& operator*() const { return n; }

    

//     Kernel* operator->(){

//         return &n;

//     }

// ​

//     SeqIter& operator++() {

//         ++n.data;

//         return *this;

//     }

// ​

//     SeqIter operator++(int) {

//         SeqIter old(*this);

//         ++*this;

//         return old;

//     }

// private:

//     Kernel n;

// };

// ​

// int main(){

//     SeqIter seq;

// ​

//     std::cout << *seq << '\n';

//     ++seq;

//     std::cout << *seq << '\n';

//     ++seq;

//     std::cout << *seq++ << '\n';

//     std::cout << *seq++ << '\n';

//     std::cout << *seq++ << '\n';

//     std::cout << *seq++ << '\n';

// ​

//     Kernel *pk = seq.operator->();

//     (*pk).data = 67;

//     pk->data = 67;

// ​

//     std::cout << pk->data << '\n';

//     std::cout << seq.operator->()->data << '\n';

//     std::cout << seq->data << '\n';

// ​

//     std::cout << seq->fx() << '\n';

// ​

// ​

//     return 0;

// }

