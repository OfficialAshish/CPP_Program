#include <iostream>
using namespace std;

int first(int *arr, int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return first(arr, n, i + 1, key);
}

int last(int *arr, int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int rp = last(arr, n, i + 1, key);
    if (rp != -1)
    {
        return rp;
    }
    else if (arr[i] == key)
    {
        return i;
    }
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    int arrr[] = {3, 2, 5, 4, 3, 5, 2, 4};
    cout << "first:" << first(arrr, 8, 0, 5) << " & last: " << last(arrr, 8, 0, 4);
    return 0;
}
