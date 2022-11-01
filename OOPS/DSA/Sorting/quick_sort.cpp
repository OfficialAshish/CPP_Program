#include <iostream>
using namespace std;

void printArr(int ar[], int l)
{
    cout << endl;
    for (int i = 0; i < l; i++)
    {
        cout << ", " << ar[i];
    }
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int ar[], int lf, int rt)
{
    int i = lf, j = rt;
    int pivot = ar[lf];
    // printArr(ar, 8);

    while (i < j)
    {
        while (ar[i] <= pivot)
            i++;
        while (ar[j] > pivot)
            j--;
        if (ar[i] > ar[j] && i < j)
        {
            swap(&ar[i], &ar[j]);
        }
    }
    swap(ar[lf], ar[j]);
    // cout << "\nPivot:" << pivot;
    // printArr(ar, 8);
    return j;
}

void quickSort(int ar[], int left, int right)
{
    if (left < right)
    {
        int prt_inx = partition(ar, left, right);
        quickSort(ar, left, prt_inx - 1);
        quickSort(ar, prt_inx + 1, right);
    }
}

int main(int argc, char const *argv[])
{
    int N = 8;
    int arr[] = {4, 2, 6, 9, 2, 5, 1, 8};
    quickSort(arr, 0, 8 - 1);

    printArr(arr, 8);

    return 0;
}
