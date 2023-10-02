#include <bits/stdc++.h>

using namespace std;

bool isSafe(const int &row, const int &col, const vector<vector<int>> &board, const int &n)
{
    int i = row, j = col;
    while (j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        j--;
    }

    i = row, j = col;
    while (j >= 0 and i >= 0)
    {
        if (board[i][j] == 1)
            return false;
        j--;
        i--;
    }

    i = row, j = col;
    while (i < n and j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        j--;
        i++;
    }
    return true;
}

void addSolution(vector<vector<int>> &ans, const vector<vector<int>> &board, int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solveQ(int col, vector<vector<int>> &ans, vector<vector<int>> &board, const int &n)
{
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solveQ(col + 1, ans, board, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solveQ(0, ans, board, n);

    return ans;
}
void printBoard(vector<vector<int>> board)
{
    int size = board.size();

    for (auto &&i : board)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> ans = nQueens(4);
    printBoard(ans);

    return 0;
}
