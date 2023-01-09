#include <iostream>
using namespace std;

int bS(int arr[], int s, int e, int key)
{
    int mid = 0;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int ar[] = {3, 4, 5, 6, 7, 1, 2};
    int key = 1, ans = -1;
    int pivot = 0;
    int s = 0, e = 7 - 1;
    int mid;

    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (ar[mid] == key)
        {
            cout << mid;
            return 0;
        }
        else if (ar[mid] < key)
        {
            s = mid + 1;
                }
        else
        {
            e = mid;
        }
    }

    cout << ans;

    // cout << a;
    return 0;
}

/* if (ar[pivot] <= key )
{
    ans = bS(ar, pivot, 6, key);
}
else
{
    ans = bS(ar, 0, pivot - 1, key);
} */