#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans(2, -1);

    int s = 0, e = nums.size() - 1, mid = 0;

    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    if (nums[s] == target)
        ans[0] = s;
    else
        return ans;

    e = nums.size() - 1;
    while (s < e)
    {
        mid = s + (e - s) / 2 + 1; // Make mid biased to the right

        if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid;
        }
    }
    if (nums[e] == target)
        ans[1] = e;
    else
        return ans;

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> ar = {5, 7, 7, 8, 8, 10};
    vector<int> an = searchRange(ar, 6);
    cout << an[0] << "and," << an[1];
    return 0;
}
