#include <iostream>
#include <vector>
using namespace std;
/*
void moveZero(vector<int> &v)
{
    int i = 0, j = 0;
    while (i < v.size() and j < v.size())
    {
        while (v[i] != 0)
            i++; // exit at v[i] is zero
        cout << "I=" << i << endl;
        while (v[j] == 0)
            j++; // element, exits when v[j] is not zero
        cout << "J=" << j << endl;
        if (v[i] < v[j])
        {
            swap(v[i], v[j]);
            i++; // i is no more zero
        }
    }
} */

void moveZero(vector<int> &v)
{
    int i = v.size() - 1; // remains at zero
    int j = i;            // remains at elem
    while (j >= 0)
    {
        if (v[j] != 0)
        {
            swap(v[i], v[j]);
            i--;
            j--;
        }
        else
            j--;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> ar = {2, 0, 4, 0, 0, 7, 5};
    moveZero(ar);

    for (auto i : ar)
    {
        cout << i << ", ";
    }

    return 0;
}
