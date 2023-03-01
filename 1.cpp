#include <bits/stdc++.h>
using namespace std;

template<class T>
class Queue
{
public:
    T *a;
    int array_cap;
    int l,r;
    int sz;

    Queue()
    {
        a = new T[1];
        array_cap = 1;
        l = 0;
        r = -1;
        sz = 0;
    }
    void remove_circular()
    {
        if(l>r)
        {
            T *tmp = new T[array_cap];
            int idx = 0;
            for(int i=l; i<array_cap; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            for(int i=0; i<=r; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            swap(tmp,a);
            l = 0;
            r = array_cap -1;
            delete [] tmp;
        }
    }
    void increase_size()
    {
        remove_circular();
        T *tmp = new T[array_cap*2];
        for(int i=0; i<array_cap; i++)
            tmp[i] = a[i];
        swap(a,tmp);
        array_cap = array_cap*2;
        delete [] tmp;
    }
    void enqueue(T value)
    {
        if(sz == array_cap)
        {
            increase_size();
        }
        r++;
        if(r == array_cap)
        {
            r = 0;
        }
        a[r] = value;
        sz++;
    }

    void dequeue()
    {
        if(sz == 0)
        {
            cout<<"Queue is empty\n";
            return;
        }
        l++;
        if(l==array_cap)
        {
            l = 0;
        }
        sz--;
    }
    T front()
    {
        if(sz == 0)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        return a[l];
    }
    int size()
    {
        return sz;
    }
};

int main()
{
    Queue<int>q;
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.front()<<"\n";

    Queue<char>q1;
    q1.enqueue('N');
    q1.enqueue('M');
    cout<<q1.front()<<"\n";

    Queue<double>q2;
    q2.enqueue(3.33);
    q2.enqueue(6.66);
    cout<<q2.front()<<"\n";

    cout<<"\n";

    q.dequeue();
    cout<<q.front()<<"\n";

    q1.dequeue();
    cout<<q1.front()<<"\n";

    q2.dequeue();
    cout<<q2.front()<<"\n";

    return 0;
}

