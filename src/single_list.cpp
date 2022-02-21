#include "single_list.hpp"
#include "hashset.hpp"
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
    printf("new sentinal ,%p\n", (void*)m_sentinal);
    m_sentinal->setNext(m_sentinal);
    
    axioms();
}
  
LinkedList::LinkedList(LinkedList const &source)
: m_sentinal(new Node(0, m_sentinal))   
, m_head(m_sentinal)
, m_tail(m_sentinal) 
, m_size()
{
    m_sentinal->setNext(m_sentinal);

    Node* node = source.m_head;
    LinkedList list;
    while (node != source.m_sentinal)
    {
        list.add(node->getData());
        node = node->getNext();
    }

    node = list.m_head;
    while (node != list.m_sentinal)
    {
        add(node->getData());
        node = node->getNext();
    }

    m_size = source.size(); 
    axioms();   
}

LinkedList &LinkedList::operator=(LinkedList const &source)
{
    while (size() > 0)
    {
        remove();
    }
        
    m_sentinal->setNext(m_sentinal);

    Node* node = source.m_head;
    LinkedList list;
    while (node != source.m_sentinal)
    {
        list.add(node->getData());
        node = node->getNext();
    }

    node = list.m_head;
    while (node != list.m_sentinal)
    {
        add(node->getData());
        node = node->getNext();
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
    printf("delete sentinal ,%p\n", (void*)m_sentinal);
    delete m_sentinal;
    axioms();
}

bool LinkedList::contains(int a_element) const
{
     Iterator it = this->begin();
     Iterator end = this->end();
    //Node* current = m_head;
    m_sentinal->setData(a_element);
    
    for (int index = 0; ; index++)
	{
      if (it.data() == a_element)
      {
          if(it.notEqual(end))
          {
            return true;
          }
          else
          {
            return false;
          }
      }
      it = it.next();
    }
   
}


// bool LinkedList::isExist (int a_data) 
// {
//     Node* current = m_head;
//     while(current != m_sentinal)
//     {
//       if (current->getData() == a_data)
//       {
//           return 1;
//       }
//       current = current->getNext();
//     }
//     return 0;
// }


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
    int data = m_head->getData();
    m_head = m_head->getNext();
    m_size--;
    delete node;
    return data;
}

int LinkedList::first() const
{
    assert(!isEmpty());
    return m_head->getData();
} 

int LinkedList::last() const
{
    assert(!isEmpty());
    return m_tail->getData();
} 
 Node* LinkedList::getHead() const
 {
     return m_head;
 }
void LinkedList::axioms()
{
    assert(m_size >= 0);
    assert(m_head != 0);
    assert(m_tail != 0);
}

Iterator::Iterator(Node* a_node)
: m_current(a_node)
{
}
 
Iterator& Iterator::next() 
{
    m_current = m_current->getNext();
    return *this;
}

int Iterator::data() const
{
    return m_current->getData();
}
LinkedList interSec(LinkedList &a_first, LinkedList &a_second)
{
    Iterator start = a_first.begin();
    Iterator last = a_first.end();
    LinkedList dest;
    while (start.notEqual(last))
    {
        int data = start.data();
        if (a_second.contains(data))
        {
            dest.add(data);
        }
        start = start.next();                                                                                                                                                                                                     
    }
    return dest;
}
bool contains(LinkedList const& a_list, int a_element)
{
    return a_list.contains(a_element);
}
bool contains(Iterator a_begin, Iterator a_end, int a_element)
{
     while (a_begin.notEqual(a_end))
    {
        if (a_begin.data() == a_element)
        {
           return true;
        }
         a_begin.next();                                                                                                                                                                                                     
    }
    return false;
}
size_t HashFunc(void *_data)
{
	return *(int*)_data;
}

int EqualityInt(void *_Data1, void *_Data2)
{
	if(*(int*)_Data1 == *(int*)_Data2)
	{
		return true;
	}
	return false;
}

void PrintInt(void *_data)
{
	if(_data != NULL)
	{
		printf("%d, " ,*(int*)_data);
	}
}
LinkedList flipList(LinkedList a_list) 
{
    LinkedList flipped;
    Iterator it = a_list.begin();
    Iterator end = a_list.end();

    while(it.notEqual(end))
    {
        flipped.add(it.data());
        it = it.next();
    } 

    return flipped;  
}
size_t intersect(LinkedList const& a_first, LinkedList const& a_second, LinkedList& a_result)
{
    Hash *pHash = NULL; 
	size_t secondSize = a_second.size();
    assert(a_first.size() > 0 && secondSize > 0);

    Iterator it1 = a_first.begin();
    Iterator it2 = a_second.begin();
    Iterator end1 = a_first.end();
    Iterator end2 = a_second.end();

	pHash = HashCreate(secondSize, HashFunc, EqualityInt);
	if(pHash == NULL)
    {
        return 0;
    }

    int* dataArray = new int[secondSize];
    int* searchArray = new int[a_first.size()];
    size_t j = 0, i = 0;
    
    while(it2.notEqual(end2))
    {
        dataArray[i] = it2.data();
        HashInsert(pHash, dataArray + i);
        it2.next();
        i++;
    }
   
    while(it1.notEqual(end1))
    {
        searchArray[j] = it1.data();
        if(HashIsFound(pHash, searchArray + j))
        {
            a_result.add(it1.data());          
        }
        it1.next();
        j++;
    }
    flipList(a_result);
    HashDestroy(&pHash, NULL);
    delete[] dataArray;
    delete[] searchArray;
    
    return a_result.size();
}