#include <iostream>
using namespace std;

int largest(int arr[], int n)
{

    int s = 0, e = n, mid = 0;

    while (s < e)
    {
        mid = s + (e - s) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
            e = mid;
    }

    return s;
}

int main(int argc, char const *argv[])
{
    int ar[] = {2, 3, 4, 5, 1};
    int a = largest(ar, 5);
    cout << a;
    return 0;
}

/*
while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] > arr[mid + 1] and arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            e = mid - 1;
        }
        else
        {
            cout << "err";
        }
    }
     */