#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> ar, int m, int n, int mid)
{
    int sumPainter = 1, timeMin = 0;
    for (int i = 0; i < n; i++)
    {
        if (timeMin + ar[i] <= mid)
        {
            timeMin += ar[i];
        }
        else
        {
            sumPainter++;
            if (ar[i] > mid or sumPainter > m)
            {
                return false;
            }
            timeMin = ar[i];
        }
    }
    return true;
}

int partitionPaint(vector<int> arr, int m, int n)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; sum += arr[i++])
        ;
    int e = sum;
    int ans = -1, mid;

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
    vector<int> ar = {5, 5, 5, 5};

    cout << partitionPaint(ar, 2, ar.size());

    return 0;
}