#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter number to print its upto n primes..: ";
    cin >> n;

    vector<bool> vec1(n + 1, true);
    vec1[0] = vec1[1] = false;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            vec1[j] = false;
        }
    }

    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] == true)
        {
            cout << i << ", ";
        }
    }

    return 0;
}
