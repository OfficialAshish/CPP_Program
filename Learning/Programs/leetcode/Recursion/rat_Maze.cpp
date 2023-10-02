#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPossible(vector<vector<int>> mat, vector<vector<int>> &visited, int x = 0, int y = 0)
{
    if ((x >= 0 and x < mat.size()) and (visited[x][y] == 0) and mat[x][y] == 1)
        return true;
    else
        false;
}

void rat_going(vector<vector<int>> mat, vector<string> &path, vector<vector<int>> &visited, string &str_path, int x = 0, int y = 0)
{
    // base case
    if (x == mat.size() - 1 and y == mat.size() - 1)
    {
        path.push_back(str_path);
        return;
    }

    // visited
    // visited[x][y] = 1;

    // moving next
    //  D,L,R,U,
    int newX = x + 1;
    int newY = y;
    if (isPossible(mat, visited, newX, newY))
    {
        str_path += "D";
        visited[newX][newY] = 1;
        rat_going(mat, path, visited, str_path, newX, newY);
        str_path.pop_back();
        visited[newX][newY] = 0;
    }

    // Left
    newX = x;
    newY = y - 1;
    if (isPossible(mat, visited, newX, newY))
    {
        str_path += "L";
        visited[newX][newY] = 1;
        rat_going(mat, path, visited, str_path, newX, newY);
        str_path.pop_back();
        visited[newX][newY] = 0;
    }
    // right
    newX = x;
    newY = y + 1;
    if (isPossible(mat, visited, newX, newY))
    {
        str_path += "R";
        visited[newX][newY] = 1;
        rat_going(mat, path, visited, str_path, newX, newY);
        visited[newX][newY] = 0;
        str_path.pop_back();
    }
    // up
    newX = x - 1;
    newY = y;
    if (isPossible(mat, visited, newX, newY))
    {
        str_path += "U";
        visited[newX][newY] = 1;
        rat_going(mat, path, visited, str_path, newX, newY);
        visited[newX][newY] = 0;
        str_path.pop_back();
    }

    // backtrack
    // visited[x][y] = 0;
}

int main(int argc, char const *argv[])
{
    vector<string> paths;
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                  {1, 1, 1, 1},
                                  {1, 1, 0, 1},
                                  {0, 1, 1, 1}};
    // int n=4;

    vector<vector<int>> visited = matrix;
    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited[0].size(); j++)
            visited[i][j] = 0;
    }
    string str_path = "";
    rat_going(matrix, paths, visited, str_path);

    for (auto i : paths)
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
