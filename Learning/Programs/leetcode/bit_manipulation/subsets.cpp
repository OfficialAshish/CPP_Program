#include <iostream>
using namespace std;
#define N 4
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4};

    for (int i = 0; i < (1 << N); i++) // 2^N
    {
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j];
            }
        }
        cout << endl;
    }

    return 0;
}
