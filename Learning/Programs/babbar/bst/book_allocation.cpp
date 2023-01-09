#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int m, int n, int mid)
{
    int sum = 0;
    int studentNext = 1;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            studentNext++;
            if (studentNext > m or arr[i] > mid)
                return false;
            sum = arr[i];
        }
    }
    return true;
}

int allocBook(vector<int> arr, int m, int n)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; sum += arr[i++])
        ;
    int e = sum;
    int mid, ans = -1;
    int i = 0;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (isPossible(arr, m, n, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> ar = {10, 20, 30, 40, 50};

    cout << allocBook(ar, 2, ar.size());

    return 0;
}