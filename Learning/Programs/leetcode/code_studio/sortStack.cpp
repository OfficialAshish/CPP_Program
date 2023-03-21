#include <bits/stdc++.h>

void insert(stack<int> &stack, int elem)
{
    if (stack.empty() || (!stack.empty() && stack.top() < elem))
    {
        stack.push(elem);
        return;
    }

    int num = stack.top();
    stack.pop();

    insert(stack, elem);
    stack.push(num);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    insert(stack, num);
}