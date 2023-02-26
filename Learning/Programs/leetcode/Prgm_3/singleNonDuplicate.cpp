#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int s = 0, e = nums.size() - 1, mid = 0;

        while (s < e)
        {
            mid = s + (e - s) / 2;

            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                {
                    s = mid + 1;
                }
                else
                    e = mid;
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                {
                    s = mid + 1;
                }
                else
                    e = mid - 1;
            }
        }
        return nums[s];
    }
};

int main()
{
    vector<int> v = {1, 1, 2, 2, 3, 4, 4};
    Solution s;
    cout << s.singleNonDuplicate(v);
}