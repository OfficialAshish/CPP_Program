#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty())
            {
                char tp = st.top();
                if ((s[i] == ')' and tp == '(') or (s[i] == '}' and tp == '{') or (s[i] == ']' and tp == '['))
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }
    for (int i = 0; i < st.size(); i++)
    {
        cout << st.top() << ", ";
        st.pop();
    }

    if (st.empty())
        return true;
    else
        return false;
}

int main()
{
    // string s = "]";
    string s = "(])";
    // string s = "()[]{}";
    cout << isValid(s);
}

int longestValidParentheses(string s)
{
    stack<char> st;
    int len = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty())
            {
                char tp = st.top();
                if ((s[i] == ')' and tp == '(') or (s[i] == '}' and tp == '{') or (s[i] == ']' and tp == '['))
                {
                    st.pop();
                    len++;
                }
            }
        }
    }
}