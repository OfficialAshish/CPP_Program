#include <iostream>
#include <string>
#include "stack_tmplt_nop.h"

using namespace std;
using namespace nm_stack_tmplt_nop_;

int main(int argc, char const *argv[])
{
    string exp_inp;
    char exp_pstf[exp_inp.size()], ch;
    cout << "\nEnter Postfix Expression : ";
    cin >> exp_inp;

    for (int i = 0; i < exp_inp.size(); i++)
    {
        exp_pstf[i] = exp_inp[i];
    }

    stack_nop_<int> stk;

    for (size_t i = 0; i < exp_inp.size(); i++)
    {
        ch = exp_pstf[i];
        if (isdigit(ch))
        {
            stk.push(ch - '0');
        }
        else
        {
            int op1 = stk.pop();
            int op2 = stk.pop();
            switch (ch)
            {
            case '*':
                stk.push(op1 * op2);
                break;
            case '+':
                stk.push(op1 + op2);
                break;
            case '-':
                stk.push(op1 - op2);
                break;
            case '/':
                stk.push(op1 / op2);
                break;
            default:
                cout << "\nERRO!\n";
                break;
            }
        }
    }
    cout << "\nResult : " << stk.pop();
    if (stk.empty())
    {
        cout << "\ncorrect\n";
    }
    return 0;
}
