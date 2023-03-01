#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node * nxt;
};

template <class T>
class SinglyLinkedList
{
public:
    node<T> *head;
    int sz;
    SinglyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    node<T> * CreateNewNode(T data)
    {
        node<T> *newnode = new node<T>;
        newnode->data = data;
        newnode->nxt = NULL;
        return newnode;
    }

    void InsertAtHead(T data)
    {
        sz++;
        node<T> *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        node<T> *a = head;
        newnode->nxt = a;
        head = newnode;
    }

    void DeleteAtHead()
    {
        if(head== NULL)
        {
            return;
        }
        node<T> *a = head;
        node<T> *b = head->nxt;
        delete a;
        head= b;
        sz--;
    }

    int getSize()
    {
        return sz;
    }
};

template <class T>
class Stack
{
public:
    SinglyLinkedList<T> l;

    Stack()
    {

    }

    T top()
    {
        if(l.getSize() == 0)
        {
            cout << "Stack is empty!\n";
            T a;
            return a;

        }
        return l.head->data;
    }

    void push(T val)
    {
        l.InsertAtHead(val);
    }

    void pop()
    {
        if(l.getSize() == 0)
        {
            cout << "Stack is empty!\n";
            return;
        }
        l.DeleteAtHead();
    }
};


int main()
{
    Stack<int> st;
    st.push(3);
    st.push(4);
    cout<<st.top()<<"\n";


    Stack<char> sty;
    sty.push('N');
    sty.push('M');
    cout<<sty.top()<<"\n";

    Stack<double> stx;
    stx.push(3.33);
    stx.push(6.66);
    cout<<stx.top()<<"\n";

    cout<<"\n";

    st.pop();
    cout<<st.top()<<"\n";

    sty.pop();
    cout<<sty.top()<<"\n";

    stx.pop();
    cout<<stx.top()<<"\n";

    return 0;
}

