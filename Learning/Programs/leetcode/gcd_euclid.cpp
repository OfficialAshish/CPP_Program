#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n;
    cout << "Enter m,n :";
    cin >> m >> n;
    // let m>n
    if (n > m)
    {
        int tmp = m;
        m = n;
        n = tmp;
    }
    while (n != 0)
    {
        int rem = m % n;
        m = n;
        n = rem;
    }
    cout << m;

    return 0;
}
