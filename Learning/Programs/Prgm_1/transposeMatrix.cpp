#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 3, m = 3;
    int matrix[n][m] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }

    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i, tmp = 0; j < m; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    cout << "\nTransposed Matrix: \n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
