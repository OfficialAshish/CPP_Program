#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void winningToken(int n, int arr[], int winningNumber)
{
    vector<pair<int, int>> result;

    // Iterate through all possible pairs
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] + arr[j] == winningNumber)
            {
                result.push_back({max(arr[i], arr[j]), min(arr[i], arr[j])});
            }
        }
    }

    sort(result.begin(), result.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
             int diffA = a.first - a.second;
             int diffB = b.first - b.second;
             return diffA < diffB; });

    cout << result[0].first << " " << result[0].second << endl;
}

void winningToken1(int n, int arr[], int winningNumber)
{
    pair<int, int> bestPair;
    int minDifference = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] + arr[j] == winningNumber)
            {
                int difference = abs(arr[i] - arr[j]);

                if (difference < minDifference)
                {
                    minDifference = difference;
                    bestPair = {max(arr[i], arr[j]), min(arr[i], arr[j])};
                }
            }
        }
    }

    cout << bestPair.first << " " << bestPair.second << endl;
}
int main()
{
    int n = 6;
    int arr[] = {1, 6, 3, 2, 5, 4};
    int winningNumber = 7;

    winningToken1(n, arr, winningNumber);

    return 0;
}
