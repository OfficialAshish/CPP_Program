#include <iostream>
#include <vector>
using namespace std;

void printSpiral(vector<vector<int>> v)
{
    int count = 0, row = v.size(), col = v[0].size();
    int startRow = 0, endRow = row - 1, startCol = 0, endCol = col - 1;
    int total = row * col;
    while (count < total)
    {
        for (int j = startCol; j <= endCol; j++)
        {
            cout << v[startRow][j] << ", ";
            count++;
        }
        startRow++;
        for (int j = startRow; j <= endRow; j++)
        {
            cout << v[j][endCol] << ", ";
            count++;
        }
        endCol--;
        for (int j = endCol; j >= startCol; j--)
        {
            cout << v[endRow][j] << ", ";
            count++;
        }
        endRow--;
        for (int j = endRow; j >= startRow; j--)
        {
            cout << v[j][startCol] << ", ";
            count++;
        }
        startCol++;
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> vc = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printSpiral(vc);
    return 0;
}
