#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<vector<int>> &board, const int &value, const int &row, const int &col)
{
    int size = board.size();
    for (int i = 0; i < size; i++)
    {
        if (board[row][i] == value or board[i][col] == value)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<int>> &board)
{
    int size = board.size();

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (board[row][col] == 0) // empty cell
            {
                for (int value = 1; value <= 9; value++)
                {
                    if (isSafe(board, value, row, col))
                    {
                        board[row][col] = value;
                        bool res = solveSudoku(board);
                        if (res)
                            return true;
                        else
                            board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
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
    vector<vector<int>> board =
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    if (solveSudoku(board))
        cout << "\nSOLVED correctly\n";
    else
        cout << "\nSome Error!\n";

    printBoard(board);
    return 0;
}
