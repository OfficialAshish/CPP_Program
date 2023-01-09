#include <iostream>
using namespace std;

int getPivot(int arr[], int n) // minimum elem in rotated shorted arr
{
    int s = 0, mid = 0, e = n - 1;
    while (s < e)
    {
        mid = s + (e - s) / 2;

        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
            e = mid;
    }
    return e;
}

int main(int argc, char const *argv[])
{
    int ar[] = {3, 4, 5, 6, 7, 1, 2};
    int a = getPivot(ar, 7);
    cout << a;
    return 0;
}
