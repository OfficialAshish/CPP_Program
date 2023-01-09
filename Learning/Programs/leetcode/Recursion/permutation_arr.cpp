#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permutation(vector<int> v, vector<vector<int>> &ans, int i = 0)
{
    if (i >= v.size())
    {
        ans.push_back(v);
        return;
    }
    for (int j = i; j < v.size(); j++)
    {
        swap(v[i], v[j]);
        permutation(v, ans, i + 1);
        swap(v[i], v[j]); // backtracking
    }
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 2, 3};
    vector<vector<int>> ans;
    permutation(vec, ans);

    for (int j = 0; j < ans.size(); j++)
    {
        for (auto i : ans[j])
        {
            cout << i << ", ";
        }
        cout << endl;
    }

    return 0;
}
