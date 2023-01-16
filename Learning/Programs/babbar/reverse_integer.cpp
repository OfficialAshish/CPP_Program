
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reverseStr(string &s, int tSz = 0)
{
    if (tSz >= s.size() / 2)
    {
        return;
    }
    swap(s[tSz], s[s.size() - 1 - tSz]);
    reverseStr(s, tSz + 1);
}

int main()
{
    int x = -34, flag = 0;
    int result;
    if (x < 0)
        flag = 1;
    string s = to_string(x);
    if (flag == 1)
        s.erase(0, 1);
    reverseStr(s);
    result = stoi(s);
    if (flag == 1)
        result = (-1) * result;
    cout << result;
    if (result > 2147483647)
        return 0;

    return result;
}
