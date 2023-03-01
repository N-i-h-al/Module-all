#include<bits/stdc++.h>
using namespace std;

void deleteValue(list<int> &num, int x)
{
    for (auto it = num.begin(); it != num.end(); it++)
    {
        if (*it == x)
        {
            it = num.erase(it);
            break;
        }
    }
}

int main()
{
    list<int>li= {7, 3, 8, 4, 5, 4};
    int value = 4;

    deleteValue(li, value);

    int i=0;
    int l=li.size();

    for (int li : li)
    {
        cout << li;
        if(i<l-1)
        {
            cout <<",";
        }
        else
        {
            cout <<" ";
        }
        i++;
    }
    cout << endl;

    return 0;
}
