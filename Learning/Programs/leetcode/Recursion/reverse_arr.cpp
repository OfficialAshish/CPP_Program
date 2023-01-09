#include <iostream>
using namespace std;

void reverseArray(int ar[], int sz)
{
    static int i = 0;
    if (i >= sz / 2)
    {
        return;
    }
    swap(ar[i], ar[sz - 1 - i]);
    i++;
    reverseArray(ar, sz);
    // cout << elm << "," << sz - i;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int N = 6;

    reverseArray(arr, N);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << ", ";
    }

    return 0;
}
