#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstddef>

class Node
{
public:
    Node(int a_data, Node* a_next);
    Node(int a_data);
    int getData() const;
    Node* getNext() const;

    void setData(int a_data);
    void setNext(Node* a_next);

private:
    void axioms()const;    

private:
    int m_data;
    Node* m_next;
};


class Iterator: public std::iterator<std::input_iterator_tag, int>
{
public:
    Iterator(Node *a_node = 0);

    Iterator& next();
    int data() const;

    bool equal(Iterator const& a_itr) const;
    bool notEqual(Iterator const &a_itr) const;
    Iterator operator++(int);
    Iterator& operator++();
    int operator*() const;
    Node* operator->() const;
    bool operator!=(Iterator const& a_itr) const;
    bool operator==(Iterator const& a_itr) const;
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
    bool contains(int a_element) const;
    int first() const;  
    int last() const;  
    void print() const;
    Iterator begin() const;
    Iterator end() const;
    Node* getHead () const;
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
LinkedList interSec(LinkedList &a_first, LinkedList &a_second); 
bool contains(LinkedList const& a_list, int a_element);
bool contains(Iterator a_begin, Iterator a_end, int a_element);
size_t HashFunc(void *_data);
int EqualityInt(void *_Data1, void *_Data2);
void PrintInt(void *_data);
 LinkedList flipList(LinkedList a_list); 
size_t intersect(LinkedList const& a_first, LinkedList const& a_second, LinkedList& a_result);
#include "./inl/single_list.hxx"

#endif  // LINKED_LIST_HPP

