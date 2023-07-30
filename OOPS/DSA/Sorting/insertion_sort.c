#include <stdio.h>

void print(int ar[], int l)
{
    printf("{");
    for (int i = 0; i < l; i++)
    {
        printf("%d , ", ar[i]);
    }
    printf("}\n");
}

void insertS(int *arr)
{
    for (int i = 1; i < 6; i++)
    {
        int j = i - 1;
        int current = arr[i];
        // printf("\n\ni:%d\n", i);
        while (arr[j] > current && j >= 0)
        {
            // printf("\nj:%d\n", j);
            arr[j + 1] = arr[j];
            j--;
            // print(arr, 6);
        }
        arr[j + 1] = current;
        // print(arr, 6);
    }
}

int main(int argc, char const *argv[])
{
    int arr[6] = {5, 4, 3, 1, 2, 8};
    print(arr, 6);

    insertS(arr);

    printf("\nFinal:");
    print(arr, 6);

    return 0;
}
