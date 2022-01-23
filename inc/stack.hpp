class Stack
{
public:
    //special member functions
    //Constructor, ctor
    Stack(int size);    // member functions
    void push(int x);
    int pop();    
    int size();

    bool isEmpty();
    bool isFull();    void dump();
private:
    void dumpElements();    // data member
private:
    int* m_elements;
    int m_tos;
    int m_capacity;
};