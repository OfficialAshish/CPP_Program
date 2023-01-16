#include <iostream>

using namespace std;

int gcd(pair<int, int> n)
{
    if (n.first < n.second)
    {
        swap(n.first, n.second);
    }
    // n.first is greater now
    int rem = 1;
    while (rem != 0)
    {
        rem = n.first % n.second;
        n.first =n.second;
        n.second = rem;
    }
    return n.first;
}

int main(int argc, char const *argv[])
{
    pair<int, int> gn(24, 72);

    cout << gcd(gn);
    return 0;
}

