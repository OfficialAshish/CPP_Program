#include <iostream>
#include <vector>
using namespace std;

vector<int> operator+(vector<int> v1, vector<int> v2)
{
    vector<int> sum(max(v1.size(), v2.size()) + 1, 0);
    int i = v1.size() - 1, j = v2.size() - 1;
    int tmps = 0, k = sum.size() - 1;
    while (i >= 0 and j >= 0)
    {
        tmps = v1[i--] + v2[j--] + sum[k];
        sum[k--] = tmps % 10;
        if (tmps > 9)
        {
            sum[k]++;
        }
    }
    while (i >= 0)
    {
        sum[k--] += v1[i--];
    }
    while (j >= 0)
    {
        sum[k--] += v2[j--];
    }

    if (sum[0] == 0)
    {
        sum.erase(sum.begin());
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    vector<int> v1 = {6, 8, 5}, v2 = {9, 8, 3, 4, 5};
    vector<int> vsum = v1 + v2;

    for (auto i : vsum)
    {
        cout << i << ", ";
    }

    return 0;
}
