#include <iostream>

using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1, n2 = r - mid;
    int na_1[n1], na_2[n2];

    // cout << "\nmerge" << l;
    for (int i = 0; i < n1; i++)
    {
        na_1[i] = arr[l + i];
        // cout << na_1[i] << ", ";
    }
    for (int i = 0; i < n2; i++)
    {
        na_2[i] = arr[mid + 1 + i];
        // cout << na_2[i] << ",, ";
    }

    int i = 0, j = 0, k = l;
    /*
    while (i + j < n1 + n2)
    {
        if (i == n1)
        {
            arr[k++] = na_2[j++];
        }
        else if (j == n2)
        {
            arr[k++] = na_1[i++];
        }
        else if (na_1[i] < na_2[j])
        {
            arr[k++] = na_1[i++];
        }
        else if (na_2[j] < na_1[i])
        {
            arr[k++] = na_2[j++];
        }
        else
        {
            cout << "\nError! @merge\n";
        }
    }*/
    while (i < n1 and j < n2)
    {
        if (na_1[i] < na_2[j])
        {
            arr[k++] = na_1[i++];
        }
        else
        {
            arr[k++] = na_2[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = na_1[i++];
    }
    while (j < n2)
    {
        arr[k++] = na_2[j++];
    }
}

void mergeSort(int arr[], int lf, int rt)
{
    if (lf < rt)
    {
        int mid = (lf + rt) / 2;
        mergeSort(arr, lf, mid);
        mergeSort(arr, mid + 1, rt);

        merge(arr, lf, mid, rt);
    }
}

int main()
{
    int arr[] = {5, 2, 6, 9, 1, 7};
    int N = 6;
    mergeSort(arr, 0, 6);
    cout << N << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << ", ";
    }
}