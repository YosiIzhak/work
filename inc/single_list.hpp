#ifndef LIST_HPP
#define LIST_HPP
#include <cstdlib> //size_t

class Node
{
public:
    Node(int size);
    int getData() const;
    Node* getNext() const;
    Node* setNext(Node* ptr);
    void setData(int a_data);
    void setNext(Node& a_next);
private:
    int       m_data;
    Node*     m_next;
};

class List
{
public:
	//constructor
	List(size_t a_capacity = 64);
    ~List();
    List(List const& a_source);       //copy constructor
    List& operator=(List const& a_source);
	
	//methods
    void remove();
    void add(int x);
    int size() const;
    bool isEmpty() const;
    void dump() const;
    void dumpElements() const;
    void copyList(List const& a_source);
    Node* getHead() const;
    Node* getEnd() const;
    ListItr begin(List* _list);
    ListItr end(List* _list);
    
    
private:
    void axioms() const;
    
    // data member
private:
    size_t m_size;
    Node* m_head;
    Node* m_end;

};

class ListItr
{
public:
    ListItr();
    bool equals(const ListItr a_itr) const;
    Node* next();
    int get() const;
    ListItr set(Node * a_node);
     int first(List* _list);
    int last(List* _list);
private:
    Node* m_node;
};

 #include "./inl/single_list.hxx"   

#endif

