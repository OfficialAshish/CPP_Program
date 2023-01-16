#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &v, int k = 1)
{
    int s = v.size();
    vector<int> tmpv(v);
    for (int i = 0; i < s; i++)
    {
        v[(i+k)%s] = tmpv[i];
    }
    
}

int main(int argc, char const *argv[])
{
    vector<int> v1 = {1,2,3, 4, 5, 6, 7,8,9};
    rotate(v1,2);

    for (auto i : v1)
    {
        cout << i << ", ";
    }

    return 0;
}
