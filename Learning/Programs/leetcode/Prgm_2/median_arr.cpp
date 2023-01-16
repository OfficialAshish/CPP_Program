#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static double findMedianSortedArrays(vector<int> &v1, vector<int> &v2)
    {
        vector<int> fin(0);
        for (auto i = v1.begin(); i != v1.end(); i++)
        {
            fin.push_back(*i);
        }
        for (auto i = v2.begin(); i != v2.end(); i++)
        {
            fin.push_back(*i);
        }
        for (int k = 0; k < fin.size(); k++)
        {
            cout << fin[k] << ", ";
        }

        int m = fin.size();
        if (m % 2 == 0)
        {
            cout << "Median is : " << m / 2 << " and " << (m / 2) + 1 << endl;
        }
        else
        {
            cout << "Median is : " << (m / 2) + 1 << endl;
        }
    }
};

int main()
{
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {5, 6, 7};
    Solution::findMedianSortedArrays(v1, v2);
}