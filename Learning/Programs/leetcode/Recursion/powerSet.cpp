#include <iostream>
#include <vector>
using namespace std;

void powerSet(vector<int> v, vector<vector<int>> &as, vector<int> output = {}, int i = 0)
{

    if (i >= v.size())
    {
        as.push_back(output);
        return;
    }

    // excld
    powerSet(v, as, output, i + 1);
    // incl
    output.push_back(v[i]);
    powerSet(v, as, output, i + 1);
}

int main(int argc, char const *argv[])
{
    vector<int> vc = {1, 2, 3};
    vector<vector<int>> ans;
    powerSet(vc, ans);

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
