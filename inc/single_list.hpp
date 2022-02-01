#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstddef>

class Node;

class Iterator
{
public:
    Iterator(Node *a_node = 0);

    Iterator next() const;
    int data() const;

    bool equal(Iterator const& a_itr) const;
    bool notEqual(Iterator const &a_itr) const;

private:
    Node* m_current;
};

class LinkedList
{
public:
    LinkedList();
    LinkedList(LinkedList const &source);
    LinkedList &operator=(LinkedList const &source);
    ~LinkedList();
    
    void add(int a_data); 
    int remove(); 
    bool isExist (int a_data);
    int first() const;  
    int last() const;  
    void print() const;
    Iterator begin() const;
    Iterator end() const;

    size_t size() const;
    bool isEmpty() const;
   
private:
    void axioms();    
  
private:
    Node* m_sentinal;
    Node * m_head;
    Node * m_tail;
    size_t m_size;
};
LinkedList interSec(LinkedList &a_first, 
LinkedList &a_second); 
#include "./inl/single_list.hxx"

#endif  // LINKED_LIST_HPP

