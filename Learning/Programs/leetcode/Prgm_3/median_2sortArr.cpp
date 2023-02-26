#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    int i = 0, j = 0, n = nums1.size() + nums2.size();
    for (int k = 0; k < n; k++)
    {
        if (nums1[i] < nums2[j] and i < nums1.size())
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else if (nums1[i] > nums2[j] and j < nums2.size())
        {
            ans.push_back(nums2[j]);
            j++;
        }
        else
        {
            if (i == nums1.size())
            {
                while (j < nums2.size())
                {
                    ans.push_back(nums2[j]);
                    j++;
                }
                break;
            }
            else
            {
                while (i < nums1.size())
                {
                    ans.push_back(nums1[i]);
                    i++;
                }
                break;
            }
        }
    }
    double med = 0;
    if (n % 2 != 0)
        med = ans[n / 2];
    else
        med = (ans[n / 2] + ans[(n / 2) - 1]) / 2.0;
    return med;
}

int main()
{
    vector<int> a = {1, 2}, b = {3, 4};
    cout << findMedianSortedArrays(a, b);
}