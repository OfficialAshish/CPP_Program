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

int search(int arr[], int s, int e, int key)
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
    int ar[] = {3, 4, 5, -1, 0, 1, 2};
    int key = 1, ans = -1;
    int pivot = getPivot(ar, 7);
    cout << "pivot " << pivot << endl;

    if (ar[pivot] <= key and key <= ar[6])
    {
        ans = search(ar, pivot, 6, key);
    }
    else
    {
        ans = search(ar, 0, pivot - 1, key);
    }
    cout << ans;

    // cout << a;
    return 0;
}
