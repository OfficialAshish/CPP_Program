#include <iostream>
using namespace std;
/*
int most_water(int ar[], int size)
{
    int i = 0, j = size - 1;
    int k = 1;
    while (ar[i] < ar[i + 1])
        i++;
    while (ar[j] < ar[i])
    {
        j--;
    }
    cout << "l:" << min(ar[i], ar[j]) << "\nh:" << j - i << endl;
    return (min(ar[i], ar[j]) * (j - i));
} */

int most_water(int ar[], int size)
{
    int s = 0, e = size - 1, maxArea = -1, area = -1;
    while (s <= e)
    {
        area = min(ar[s], ar[e]) * (e - s);
        maxArea = max(maxArea, area);
        if (ar[s] <= ar[e])
        {
            s++;
        }
        else
            e--;
    }
    return maxArea;
}

int main(int argc, char const *argv[])
{
    // int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int arr[] = {1, 2, 4, 3};
    cout << most_water(arr, 4);
    return 0;
}
