#include <bits/stdc++.h>
using namespace std;

template<class T>
class node
{
public:
    T data;
    node* prv;
    node* nxt;

    node(T value)
    {
        data=value;
        prv=NULL;
        nxt=NULL;
    }

};

template<class T>
class Deque
{
public:
    node<T>* head;
    node<T>* tail;
    int sz,rev;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rev=0;
    }

    void push_back(T value)
    {
        node<T>* newnode = new node<T>(value);
        if(sz==0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        tail->nxt = newnode;
        newnode->prv = tail;
        tail = newnode;
        sz++;
    }

    void push_front(T value)
    {
        node<T>* newnode = new node<T>(value);
        if(sz==0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        head->prv = newnode;
        newnode->nxt = head;
        head = newnode;
        sz++;
    }

    void pop_back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node<T> *a = tail;
        tail= tail->prv;
        delete a;
        tail->nxt = NULL;
        sz--;
    }

    void pop_front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }

        node<T> *a = head;
        head = head->nxt;
        delete a;
        head->prv = NULL;
        sz--;
    }

    T front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        return head->data;
    }

    T back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        return tail->data;
    }
};


int main()
{
    Deque<int>d;
    d.push_back(5);
    d.push_back(10);
    d.push_front(15);
    d.push_front(20);
    cout<<"Back : "<<d.front()<<" Front : "<<d.back()<<"\n";

    Deque<char>d1;
    d1.push_back('c');
    d1.push_back('d');
    d1.push_front('b');
    d1.push_front('a');
    cout<<"Back : "<<d1.front()<<" Front : "<<d1.back()<<"\n";

    Deque<double>d2;
    d2.push_back(1.3);
    d2.push_back(2.6);
    d2.push_front(3.9);
    d2.push_front(4.12);
    cout<<"Back : "<<d2.front()<<" Front : "<<d2.back()<<"\n";
    cout<<"\n";

    d.pop_front();
    d.pop_back();
    cout<<"Back : "<<d.front()<<" Front : "<<d.back()<<"\n";

    d1.pop_front();
    d1.pop_back();
    cout<<"Back : "<<d1.front()<<" Front : "<<d1.back()<<"\n";

    d2.pop_front();
    d2.pop_back();
    cout<<"Back : "<<d2.front()<<" Front : "<<d2.back()<<"\n";

    return 0;
}


