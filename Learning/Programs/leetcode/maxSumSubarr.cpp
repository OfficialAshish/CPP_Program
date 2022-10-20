#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static vector<int> sumN(vector<int> &nums, int target)
    {
        vector<int> cumm(0);
        int c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // c = c + nums[i];
            cumm.push_back(c);
            c = c + nums[i];
        }

        /* for (int i = 0; i < cumm.size(); i++)
        {
            cout << cumm[i] << ", ";
        } */

        for (int j = 0; j < cumm.size(); j++)
        {
            if (cumm[j] == target)
            {
                cout << 0 << ", -> " << j << endl;
                exit(0);
            }
            for (int k = 0; k < j; k++)
            {
                if (target == (cumm[j] - cumm[k]))
                {
                    cout << k << ", -> " << j << endl;
                }
            }
        }
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution::sumN(arr, 5);
}