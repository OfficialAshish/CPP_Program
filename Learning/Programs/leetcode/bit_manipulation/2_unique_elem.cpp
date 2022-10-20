#include <iostream>
using namespace std;

int setBitCheck(int elm, int pos)
{
    return (elm & (1 << pos));
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 4, 6, 3, 2, 1}; // 5,6
    int N = sizeof(arr) / sizeof(arr[0]);
    int xorsum = 0;
    for (int i = 0; i < N; i++)
    {
        xorsum = xorsum ^ arr[i];
    }

    int pos = 0, bit = 0;
    while (bit != 1)
    {
        bit = xorsum & (1 << pos);
        pos++;
    }
    int uniq_1 = 0;
    for (int i = 0; i < N; i++)
    {
        if (setBitCheck(arr[i], pos - 1))
        {
            uniq_1 = uniq_1 ^ arr[i];
        }
    }

    cout << uniq_1 << " " << (uniq_1 ^ xorsum);

    return 0;
}
