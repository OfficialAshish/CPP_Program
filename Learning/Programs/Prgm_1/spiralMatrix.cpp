#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int row = 5, col = 5;
    int matrix[][col] = {{1, 2, 3, 4, 5},
                         {6, 7, 8, 9, 10},
                         {11, 12, 13, 14, 15},
                         {16, 17, 18, 19, 20},
                         {21, 22, 23, 24, 25}};

    int rs = 0, rd = row - 1, cs = 0, cd = col - 1;

    while (rs <= rd && cs <= cd)
    {
        for (int j = cs; j <= cd; j++)
        {
            cout << matrix[rs][j] << ", ";
        }
        rs++;

        for (int k = rs; k <= rd; k++)
        {
            cout << matrix[k][cd] << ", ";
        }
        cd--;

        for (int i = cd; i >= cs; i--)
        {
            cout << matrix[rd][i] << ", ";
        }
        rd--;

        for (int i = rd; i >= rs; i--)
        {
            cout << matrix[i][cs] << ", ";
        }
        cs++;
        cout << endl;
    }

    return 0;
}
