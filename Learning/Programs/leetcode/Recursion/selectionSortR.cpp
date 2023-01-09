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
void selSort(int v[], int size, int j = 0)
{
    if (size - 1 <= j)
        return;
    int min = 0;
    for (int i = 0; i < size - j; i++)
    {
        if (v[i] <= v[min])
        {
            min = i;
        }
    }
    swap(v[0], v[min]);
    // print(v, size - j);
    selSort(v + 1, size, j + 1);
}

int main(int argc, char const *argv[])
{
    int v1[] = {4, 5, 6, 7, 1, 2, 3};
    selSort(v1, sizeof(v1) / sizeof(v1[0]));
    print(v1, sizeof(v1) / sizeof(v1[0]));

    return 0;
}
