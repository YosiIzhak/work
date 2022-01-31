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

void Node::setNext(Node& a_next)
{
    m_next = &a_next;
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
Node* Node::setNext(Node* ptr)
{
    m_next = ptr;
}
/*---------------list constructors ---------------*/
List::List(size_t size)
:m_size(0)
,m_head(new Node(0))
,m_end(new Node(0))
{
    m_head->setNext(m_end); 
    m_end->setNext(m_end); 
   // axioms();
}

/*---------------------------------------------*/
// copy constructor
List::List(List const& a_source)
:  m_size()
,m_head()
,m_end(0) 
{
    copyList(a_source);
    m_size = a_source.size();
    axioms();
}

/*-------------- de-constructor -------------*/
List::~List()
{
	delete m_head;
    delete m_end;
}
/*------- private function --------------------*/
//void List::axioms() const
//{
 //   assert(m_elements != NULL);
   // assert(m_capacity >= 0);
//}
/*----------------- functions -----------------*/
/*------------ copy-assignment operator -------*/
List& List::operator=(List const& a_source)
{
    this->m_end->setData(0);
    this->m_end->setNext(m_end);
    
    copyList(a_source);
    
    m_size = a_source.size();
    
    axioms();
    //printf("pointer1: %p \npointer2: %p\n", (void*)m_head, (void*)a_source.m_head);
    return *this;
}

/*----------------------------------------------*/
void List::copyList(List const& a_source)
{
    assert(a_source.size() > 0);
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
   // axioms();
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

void List::remove()
{
    assert(!isEmpty());
    m_head->setNext(m_head->getNext()->getNext());
    m_size--;
//	axioms();   
}

void List::add(int a_value)
{
   Node* newNode = new Node(a_value);
   newNode->setNext(m_head->getNext());
   m_head->setNext(newNode);
  
   // axioms();   
}

ListItr List::begin(List* a_list)
{
	if (a_list == 0) 
	{
        return;
   	}
	ListItr itr;
    itr.set(a_list->getHead()->getNext());
    return itr;
}

ListItr List::end(List* a_list)
{
	if (a_list == NULL) 
	{
        	return;
   	}
	 ListItr itr;
     itr.set(a_list->getEnd());  
	return itr;
}
int ListItr::first(List* a_list) 
{
   	//axioms();   
    ListItr itr;
    itr.set(a_list->getHead()->getNext());
    int data = itr.m_node->getData();
    return data;
}

int ListItr::last(List* a_list) 
{
    ListItr itr;
    itr.set(a_list->getHead());
    ListItr itrEnd;
    itrEnd.set(a_list->getEnd());
    while(itr.equals(itrEnd) == false)
    {
        itr.next(); 
    }
    int data = itr.m_node->getData();
    return data;
}

Node* ListItr::next()
{
     return this->m_node->getNext();
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








