#include <iostream>
#include <vector>
using namespace std;

void mergeV(vector<int> &v1, int n1, vector<int> &v2, int m2)
{
    int i = 0, j = 0, k = 0;

    while (i < n1)
    {
        if (v1[i] > v2[j])
        {
            swap(v1[i], v2[j]);
            i++;
        }
        else if (v1[i] == v2[j])
        {
            j++;
            i++;
        }

        else // v1[i] < v2[j]
        {
            i++;
        }
    }
    while (j < m2)
    {
        v1[i++] = v2[j++];
    }

    /* for (auto i : v1)
    {
        cout << i << ", ";
    } */
}

int main(int argc, char const *argv[])
{
    vector<int> v1 = {2, 3, 4, 0, 0, 0, 0}, v2 = {1, 2, 7, 8};

    mergeV(v1, 3, v2, 4);

    for (auto i : v1)
    {
        cout << i << ", ";
    }

    return 0;
}
