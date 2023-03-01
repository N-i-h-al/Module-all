#include<bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if(ch=='+' || ch=='-')
    {
        return 0;
    }
    return 1;
}

int main()
{
    string s;
    cin>>s;
    stack<char>st;
    string ans="";

    for(int i=0; i<s.size(); i++)
    {
        char now=s[i];
        if(now>='0' && now<='9')
        {
            ans+=now;
        }
        else if (s[i] == '(')
        {
            stack<char>t;
            while(s[i]!=')')
            {
                if(s[i]>='0' && s[i]<='9')
                {
                    ans+=s[i];
                }
                else if(s[i]!='(')
                {
                    t.push(s[i]);
                }
                i++;
            }
            while(t.size())
            {
                ans +=t.top();
                t.pop();
            }
        }

        else
        {
            while( st.size() && prec(st.top())>=prec(now) )
            {
                ans+=st.top();
                st.pop();
            }
            st.push(now);
        }
    }
    while(st.size())
    {
        ans +=st.top();
        st.pop();
    }
    stack<int>equi;
    int val1,val2,result=0;
    for(int i=0; i<ans.size(); i++)
    {
        if(ans[i]>='0' && ans[i]<='9')
        {
            equi.push(ans[i] - '0');
        }

        else if(ans[i]=='+')
        {
            val2=equi.top();
            equi.pop();
            val1=equi.top();
            equi.pop();
            result=val1+val2;
            equi.push(result);
        }
        else if(ans[i]=='-')
        {
            val2=equi.top();
            equi.pop();
            val1=equi.top();
            equi.pop();
            result=val1-val2;
            equi.push(result);
        }
        else if(ans[i]=='*')
        {
            val2=equi.top();
            equi.pop();
            val1=equi.top();
            equi.pop();
            result=val1*val2;
            equi.push(result);
        }
        else if(ans[i]=='/')
        {
            val2=equi.top();
            equi.pop();
            val1=equi.top();
            equi.pop();
            result=val1/val2;
            equi.push(result);
        }
    }
    cout<<equi.top()<<"\n";

}
