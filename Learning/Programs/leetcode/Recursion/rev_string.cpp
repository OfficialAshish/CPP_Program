#include <iostream>
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

int main(int argc, char const *argv[])
{
    string st = "AshishSir";

    reverseStr(st);

    cout << st;

    return 0;
}
