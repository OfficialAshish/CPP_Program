#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> v)
{
    int count = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] - v[i] > 0 or (v[v.size() - 1] - v[0] > 0))
        {
            count++;
        }
    }
    return count <= 1;
}

int main(int argc, char const *argv[])
{
    vector<int> v1 = {4, 5, 6, 7, 1, 2, 3};
    cout << check(v1);

    return 0;
}

