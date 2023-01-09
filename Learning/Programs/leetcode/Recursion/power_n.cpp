#include <iostream>
#include <cmath>
using namespace std;

int powerOfN(int x, int n)
{

    if (n == 0)
    {
        cout << "ooo";
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    int an = powerOfN(x, n >> 1);
    // first go to end for n==0,1

    // an = an*an;
    cout << "\nx: " << x << " an: " << an << " n: " << n;
    if (n & 1) // n is odd
    {
        return (x * an * an);
    }
    else
    {
        return (an * an);
    }
}

int main(int argc, char const *argv[])
{

    cout << powerOfN(4, 10);

    return 0;
}
