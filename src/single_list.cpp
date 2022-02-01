#include <cstdio>
#include <cstddef> //size_t
#include <cassert>
#include <cstring>

#include "single_list.hpp"

Node::Node(int a_data)
:m_data(a_data)
,m_next()
{
   // axioms();
}

void Node::setNext(Node* a_next)
{
    m_next = a_next;
}

void Node::setData(int a_data)
{
    m_data = a_data;
}

int Node::getData() const
{
    return m_data;
}
 
Node* Node::getNext() const
{
    return m_next;
}

/*---------------list constructors ---------------*/
List::List(size_t size)
:m_size(0)
,m_head(new Node(0))
,m_end(new Node(0))
,m_tail(new Node(0))
{
    m_head->setNext(m_end); 
    m_end->setNext(m_end); 
     m_tail->setNext(m_end); 
   // axioms();
}

/*---------------------------------------------*/
// copy constructor
List::List(List const& a_source)
:m_size()
,m_head()
,m_end(0)
,m_tail(0)
{
    copyList(a_source);
    m_size = a_source.size();
    axioms();
}

/*-------------- de-constructor -------------*/
List::~List()
{
    while(!isEmpty())
    {
        remove();
    }

    delete m_end;
    axioms();
}
/*------- private function --------------------*/
void List::axioms() const
{
    assert(m_head != 0);
    assert(m_tail != 0);
}
/*------------ copy-assignment operator -------*/
List &List::operator=(List const &source)
{
    m_end = new Node(0);
    m_head = m_end;
    m_tail = m_end;
    m_end -> setNext(m_end);

    Node* node = source.m_head;
    List list;
    while (node != source.m_end)
    {
        list.add(node -> getData());
        node = node -> getNext();
    }

    node = list.m_head;
    while (node != list.m_end)
    {
        add(node -> getData());
        node = node -> getNext();
    }

    m_size = source.size();
    axioms(); 
    return *this;
}
/*----------------------------------------------*/
void List::copyList(List const& a_source)
{
   // assert(a_source.size() > 0);
    Node* current = a_source.m_head;
    List copyList;

    while(current != a_source.m_end)
    {
        copyList.add(current->getData());     
        current = current->getNext();
    }

    current = copyList.m_head;
    while(current != copyList.m_end)
    {
        add(current->getData());   
        current = current->getNext();
    }
    axioms();
}
bool List::isEmpty() const
{
    //axioms();
    return m_size == 0;
}

int List::size() const
{
   // axioms();
    return m_size;
}

Node* List::getHead() const
{
    return m_head;
}

Node* List::getEnd() const
{
    return m_end;
}

int List::remove()
{
    assert(!isEmpty());
    Node* node = m_head;
    int data = m_head -> getData();
    m_head = m_head-> getNext();
    m_size--;
    delete node;
    return data;
}

void List::add(int a_value)
{
   if (m_size == 0)
   {
       m_tail->setData(a_value);
       m_head->setNext(m_tail);
   }
   else
   {
       Node* newNode = new Node(a_value);
       newNode->setNext(m_head->getNext());
       m_head->setNext(newNode);
   }
   m_size++;
   // axioms();   
}
void List::print() const
{
    assert(m_size > 0);
    Node* current = m_head->getNext();
    
    printf("\n");
    while(current != m_end)
    {
        printf("%d, ", current->getData());
        current = current->getNext();
    }
    printf("\n\n");
}

ListItr List::begin()
{
	ListItr itr;
    itr.set(m_head->getNext());
    return itr;
}

ListItr List::end()
{
	ListItr itr;
    itr.set(m_end);  
	return itr;
}
int List::first() const
{
   return m_head->getNext()->getData();
}

int List::last() const
{
    return m_tail->getData();
}

ListItr ListItr::next()
{
    ListItr next(m_node->getNext());
    return next;
}
ListItr::ListItr()
:m_node()
{

}

ListItr::ListItr(Node* a_node)
{
    m_node = a_node;
}
ListItr ListItr::set(Node * a_node)
{
    this->m_node = a_node;
    return *this;
}
int ListItr::get() const
{
    return this->m_node->getData();
}

bool ListItr::equals(const ListItr a_itr) const
{
	return (a_itr.m_node->getData() == this->m_node->getData());
}








