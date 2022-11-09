#include <iostream>
#include <stack>

using namespace std;

int operate(int opr_1, int opr_2, char oprt)
{
    // cout << opr_1 << ", " << opr_2 << ",, " << oprt;
    int result = 0;
    switch (oprt)
    {
    case '/':
        result = (opr_1 / opr_2);
        break;
    case '*':
        result = (opr_1 * opr_2);
        break;
    case '+':
        result = (opr_1 + opr_2);
        break;
    case '-':
        result = (opr_1 - opr_2);
        break;

    default:
        cout << "\nInvalid Expression! \n";
        return 0;
        break;
    }
    return result;
}

int evalPostfix(string exp)
{
    stack<char> expSk;
    for (int i = 0; i < exp.size(); i++)
    {
        char oprnd_1, oprnd_2;
        if (((exp[i] - '0') >= 0) and ((exp[i] - '0') <= 9))
        {
            expSk.push(exp[i]);
        }
        else if (exp[i]) // opperator
        {
            oprnd_1 = expSk.top();
            expSk.pop();
            oprnd_2 = expSk.top();
            expSk.pop();
            expSk.push((operate(oprnd_1 - '0', oprnd_2 - '0', exp[i])) + '0');
        }
    }
    if (expSk.size() == 1)
        return (expSk.top());
    else
    {
        cout << "Error! ";
        return 0;
    }
}

int main()
{
    string input;
    cout << "\nEnter Expression... :";
    cin >> input;

    int result = evalPostfix(input);
    cout << result;
    cout << "\nDone";
}