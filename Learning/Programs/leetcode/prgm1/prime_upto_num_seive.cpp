#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n = 30;

    int arr[100] = {0};

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = (i * i); j <= n; j += i)
            {
                arr[j] = 1;
            }
        }
    }

    for (int k = 2; k <= n; k++)
    {
        if (arr[k] == 0)
        {
            cout << k << ", ";
        }
    }

    return 0;
}
