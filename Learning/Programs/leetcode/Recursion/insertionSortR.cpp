#include <iostream>
#include <vector>
using namespace std;

void print(int v[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}
void insertSort(int v[], int size, int i = 0)
{
    if (size == 1)
        return;
    int j = i; // for incr i+1 for next recrsn
    while (v[i] > v[i + 1] && i >= 0)
    {
        swap(v[i], v[i + 1]);
        i--;
    }
    // print(v, size);
    // cout << "\ni: " << i;
    insertSort(v, size - 1, j + 1);
}

int main(int argc, char const *argv[])
{
    int v1[] = {4, 2, 1, 5, 6, 7, 9, 2, 3};
    insertSort(v1, sizeof(v1) / sizeof(v1[0]));
    print(v1, sizeof(v1) / sizeof(v1[0]));

    return 0;
}
