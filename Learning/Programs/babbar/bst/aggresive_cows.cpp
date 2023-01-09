#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> stll, int m, int mid)
{
    int cowCount = 1, lstPosition = stll[0];
    for (int i = 0; i < stll.size(); i++)
    {
        if (stll[i] - lstPosition >= mid)
        {
            cowCount++;
            if (cowCount == m)
            {
                return true;
            }
            lstPosition = stll[i];
        }
    }
    return false;
}

int largestMinimumDist(vector<int> stll, int m)
{
    sort(stll.begin(), stll.end());
    int s = 0, maxi = -1;
    /* for (int i = 0; i < stll.size(); i++)
    {
        maxi = max(maxi, stll[i]);
    } */
    int e = stll[stll.size() - 1], mid, ans = -1;

    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (isPossible(stll, m, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> stall = {1, 2, 3, 4, 6};
    int m = 3;                            // aggresive cows
    cout << largestMinimumDist(stall, m); // largest possible minimum distance btw two cows such that they dont fight
    return 0;
}
