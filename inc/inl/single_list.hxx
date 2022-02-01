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

#endif  // LINKED_LIST_HXX
