#include <iostream>
#include <vector>
using namespace std;

pair<int, int> bin_search_matrix(vector<vector<int>> v, int targ)
{
    pair<int, int> ans(-1, -1);
    int row = v.size(), col = v[0].size();
    int startRow = 0, endCol = col - 1;
    while (startRow <= endCol)
    {
        if (targ == v[startRow][endCol])
        {
            ans.first = startRow;
            ans.second = endCol;
            return ans;
        }
        else if (targ < v[startRow][endCol])
        {
            endCol--;
        }
        else
            startRow++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> vec = {{1, 4, 8, 15, 18},
                               {2, 6, 10, 17, 20},
                               {3, 7, 11, 21, 26}};

    int target = 17;
    pair<int, int> p = bin_search_matrix(vec, target);
    cout << "\nIndex is : " << p.first << " & " << p.second << endl;
    return 0;
}
