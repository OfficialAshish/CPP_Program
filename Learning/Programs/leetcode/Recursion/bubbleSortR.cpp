#include <iostream>
#include <vector>
using namespace std;

void bSort(int v[], int size)
{
    if (size == 1)
        return;
    for (int i = 0; i < size - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            swap(v[i], v[i + 1]);
        }
    }
    bSort(v, size - 1);
}

int main(int argc, char const *argv[])
{
    int v1[] = {4, 5, 6, 7, 1, 2, 3};
    bSort(v1, sizeof(v1) / sizeof(v1[0]));
    for (auto i : v1)
    {
        cout << i << ", ";
    }

    return 0;
}
