#include <iostream>
#include <vector>
using namespace std;

/* void rotate90(vector<vector<int>> &v)
{
    vector<vector<int>> v_c(v);
    int row = v.size(), col = v[0].size();
    for (int row_index = 0, col_index = col - 1; (row_index < row) and (col_index >= 0); row_index++)
    {
        for (int iter = 0; iter < row; iter++)
        {
            v[iter][col_index] = v_c[row_index][iter]; // swap iter with col_index for 180deg rotation
        }
        col_index--;
    }
} */

// linear approch for updating in same vector ,no extra memory
//{1,2,3,4,5,6,7,8,9}
// after 90deg
//{7,4,1,8,5,2,9,6,3}
//  value of j = {0,2,5,8,1,4,7,0,3,6}
// j is index of value after 90deg
// if else used for 2,3,3 formula ,

void rotate90(vector<vector<int>> &v)
{
    int col = v.size();
    int row = v[0].size();
    vector<vector<int>> v_c(v);
    int tot = row * col;
    int tmp = 0, j = 0, k = 0;
    for (int i = 0; i < tot; i++)
    {
        if (i == 0 or j == 8 or j == 7)
        {
            tmp = (j + 2) % tot;
            v[tmp / col][tmp % row] = v_c[i / col][i % row];
            j = tmp;
        }
        else
        {
            tmp = (j + 3) % tot;
            v[tmp / col][tmp % row] = v_c[i / col][i % row];
            j = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> ar = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate90(ar);

    for (int i = 0; i < 3; i++)
    {
        for (auto i : ar[i])
        {
            cout << i << ", ";
        }
        cout << endl;
    }

    return 0;
}
