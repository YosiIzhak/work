#include "single_list.hpp"
#include <cstddef>
#include <cassert>
#include <cstdio>
#include <cstring>

/*--------------- Node constructors -----------*/
Node::Node(int a_data)
: m_data(a_data)
, m_next()
{
}

Node::Node(int a_data, Node* a_next)
: m_data(a_data)
, m_next(a_next)
{
    axioms(); 
}

int Node::getData() const
{
    return m_data;
}

void Node::setData(int a_data)
{
    m_data = a_data;
}

Node* Node::getNext() const
{
    return m_next;
}

void Node::setNext(Node* a_next)
{
    m_next = a_next;
}

void Node::axioms() const
{
   //assert(m_next != 0);
} 

LinkedList::LinkedList()
: m_sentinal(new Node(0, m_sentinal))   
, m_head(m_sentinal)
, m_tail(m_sentinal) 
, m_size(0)
{
    m_sentinal -> setNext(m_sentinal);
    axioms();
}
  
LinkedList::LinkedList(LinkedList const &source)
: m_sentinal(new Node(0, m_sentinal))   
, m_head(m_sentinal)
, m_tail(m_sentinal) 
, m_size()
{
    m_sentinal -> setNext(m_sentinal);

    Node* node = source.m_head;
    LinkedList list;
    while (node != source.m_sentinal)
    {
        list.add(node -> getData());
        node = node -> getNext();
    }

    node = list.m_head;
    while (node != list.m_sentinal)
    {
        add(node -> getData());
        node = node -> getNext();
    }

    m_size = source.size(); 
    axioms();   
}

LinkedList &LinkedList::operator=(LinkedList const &source)
{
    m_sentinal = new Node(0, m_sentinal);
    m_head = m_sentinal;
    m_tail = m_sentinal;
    m_sentinal -> setNext(m_sentinal);

    Node* node = source.m_head;
    LinkedList list;
    while (node != source.m_sentinal)
    {
        list.add(node -> getData());
        node = node -> getNext();
    }

    node = list.m_head;
    while (node != list.m_sentinal)
    {
        add(node -> getData());
        node = node -> getNext();
    }

    m_size = source.size();
    axioms(); 
    return *this;
}

LinkedList::~LinkedList()
{
    while(!isEmpty())
    {
        remove();
    }

    delete m_sentinal;
    axioms();
}
bool LinkedList::isExist (int a_data) 
{
    Node* current = m_head;
    while(current != m_sentinal)
    {
      if (current->getData() == a_data)
      {
          return 1;
      }
      current = current->getNext();
    }
    return 0;
}

LinkedList interSec(LinkedList &a_first,
LinkedList &a_second)
{
    Iterator start = a_first.begin();
    Iterator last = a_first.end();
    LinkedList dest;
    while (start.notEqual(last))
    {
        int data = start.data();
        if (a_second.isExist(data))
        {
            dest.add(data);
        }
        start = start.next();                                                                                                                                                                                                     
    }
    return dest;
}
void LinkedList::add(int a_data)
{
    if(isEmpty())
    {
        Node* node = new Node(a_data, m_sentinal);
        m_head = node;
        m_tail = node;
    }
    else
    {
        Node* node = new Node(a_data, m_head);
        m_head = node;
    }
    m_size++;
}
/*----------------------------------------------*/
void LinkedList::print() const
{
    Node* current = m_head;
    
    printf("\n");
    while(current != m_sentinal)
    {
        printf("%d, ", current->getData());
        current = current->getNext();
    }
    printf("\n\n");
}

int LinkedList::remove()
{
    assert(!isEmpty());
    Node* node = m_head;
    int data = m_head -> getData();
    m_head = m_head-> getNext();
    m_size--;
    delete node;
    return data;
}

int LinkedList::first() const
{
    assert(!isEmpty());
    return m_head -> getData();
} 

int LinkedList::last() const
{
    assert(!isEmpty());
    return m_tail -> getData();
} 
 Node* LinkedList::getHead() const
 {
     return m_head;
 }
void LinkedList::axioms()
{
    assert(m_size >= 0);
   // assert((m_sentinal -> getNext()) == m_sentinal);
    assert(m_head != 0);
    assert(m_tail != 0);
}

Iterator::Iterator(Node* a_node)
: m_current(a_node)
{

}

Iterator Iterator::next() const
{
    return Iterator(m_current -> getNext());
}

int Iterator::data() const
{
    return m_current -> getData();
}