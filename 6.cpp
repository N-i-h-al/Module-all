#include <iostream>
#include <deque>
using namespace std;

bool check_Palindrome(string sg)
{
    deque<char>d_e;

    for (int i = 0; i < sg.length(); i++)
    {
        d_e.push_back(sg[i]);
    }

    if(d_e.size()==0)
    {
        cout<<"The deque is empty"<<"\n";
    }

    while (d_e.size()>1)
    {
        if (d_e.front()!= d_e.back())
        {
            return false;
        }
        d_e.pop_front();
        d_e.pop_back();
    }

    return true;
}

int main()
{
    string s;
    cin >> s;

    if (check_Palindrome(s))
    {
        cout << "Yes" << " ";
    }
    else
    {
        cout << "No" << " ";
    }

    return 0;
}
