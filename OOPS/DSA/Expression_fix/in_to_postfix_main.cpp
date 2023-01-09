#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool hasHighPresd(char stk, char ex)
{
    if ((ex - '0') == 47) // division
    {
        return true;
    }
    return (stk <= ex); // ASCII
}

string expToPostfix(string exp)
{
    stack<char> fixConv;
    string result = "";

    for (int i = 0; i < exp.size(); i++)
    {
        if ((exp[i] - '0') >= 0 && (exp[i] - '0') <= 9)
        {
            result = result + exp[i];
        }
        else if (exp[i]) // operator
        {
            while (!fixConv.empty() && hasHighPresd(fixConv.top(), exp[i]))
            {
                result = result + fixConv.top();
                fixConv.pop();
            }
            fixConv.push(exp[i]); // coz its previous small presidence oprt are poped
        }
        // else
    }
    while (!fixConv.empty())
    {
        result = result + fixConv.top();
        fixConv.pop();
    }

    return result;
}
int main()
{
    string input;
    cout << "\nEnter Expression... :";
    cin >> input;
    cout << "Exp: " << input << endl;

    string result = expToPostfix(input);
    // cout << "\nPostfix Exp: " << result;

    cout << "\nPostfix Exp: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    // cout << "\nDone";
}

/*
    for (int i = 0; i < exp.size(); i++)
    {
        if (((exp[i] - '0') >= 0) )
        {
            postfix.push(exp[i]);
        }
        else
        {
            if (exp[i] == ')')
            {
                while (!oprtr.empty())
                {
                    if (exp[i] == '(')
                    {
                        break;
                    }
                    else
                    {
                        postfix.push(oprtr.top());
                        oprtr.pop();
                    }
                }
            }

            while (!oprtr.empty() and exp[i] < oprtr.top())
            {
                postfix.push(oprtr.top());
                oprtr.pop();
            }
            if (oprtr.top() < exp[i])
            {
                oprtr.push(exp[i]);
            }
        }
    }
     */