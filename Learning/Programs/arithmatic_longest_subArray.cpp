#include <iostream>
#include <vector>
#define DEBUG 0
#define SIZE 16
using namespace std;

int main()
{
    // int array[SIZE] = {1, 3, 5, 6, 7, 8, 10, 12, 14, 16};

    vector<int> array = {1, 3, 5, 6, 7, 8, 10, 12, 14, 16, 5, 4, 3, 2, 1, 0};

    int newCount = 0, prevCount = 0;
    int begin = 0, end = 0;
    for (int i = 0; i < SIZE - 2; i++)
    {
        int count = 0;
        while (((array[i] - array[i + 1]) == (array[i + 1] - array[i + 2])) && (i <= SIZE))
        {
            // printf("%d, %d, %d, i: %d\n", array[i], array[i + 1], array[i + 2], i);
            count++;
            i++;
        }
        // cout << count << "& " << i - count << endl;
        newCount = count;
        if (newCount > prevCount)
        {
            // cout << prevCount << "  &  " << newCount;
            begin = i - newCount;
            end = i + 1; //(newCount + 2) - 1 + (i - newCount);
            // cout << "\n"
            //  << begin << "&" << end << endl;
            prevCount = newCount;
        }
    }

    // cout << "\n"
    //      << begin << " finall& " << end << endl;
    for (int i = begin; i <= end; i++)
    {
        cout << array[i] << ", ";
    }

    // cout << "\n";
    // for (int k = 0; k < SIZE; k++)
    // {
    //     cout << array[k] << ", ";
    // }

    return 0;
}