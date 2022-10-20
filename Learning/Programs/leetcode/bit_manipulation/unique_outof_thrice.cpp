#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 5, 1, 2, 3, 1, 2, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    int res = 0;
    for (int i = 0; i < 32; i++) // 32bit integers
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr[j] & (1 << i))
            {
                sum++;
            }
        }
        // cout << sum << " ";
        if ((sum % 3) != 0)
        {
            res = (res | (1 << i));
            // cout << res << "<<res" << endl;
        }
    }
    cout << res;
}