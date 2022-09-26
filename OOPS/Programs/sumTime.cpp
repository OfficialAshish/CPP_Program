#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    printf("\nEnter Time 1: ");
    scanf("%d%d%d", &arr[0][0], &arr[0][1], &arr[0][2]);
    printf("\nEnter Time 2: ");
    scanf("%d%d%d", &arr[1][0], &arr[1][1], &arr[1][2]);
    for (int i = 2; i >= 0; i--)
    {
        arr[2][i] += arr[0][i] + arr[1][i];
        if (arr[2][i] > 60)
        {
            arr[2][i] = arr[2][i] % 60;
            arr[2][i - 1]++;
        }
    }
    printf("Time_1 + Time_2 = %dhours %dmin %dsec \n", arr[2][0], arr[2][1], arr[2][2]);
    return 0;
}
