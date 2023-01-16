#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 3, m = 3;
    int matrix[n][m] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int s = 10;

    int i = 0, j = m - 1;
    while (i <= n && j >= 0)
    {
        if (matrix[i][j] == s)
        {
            cout << "\nFound at i =" << i << ", j = " << j << endl;
            return 0;
        }
        else if (s > matrix[i][j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "\nNot Found !\n";
    return 0;
}