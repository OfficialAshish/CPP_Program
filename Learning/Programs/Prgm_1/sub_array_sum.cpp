#include <iostream>
#define DEBUG 1
using namespace std;

int main()
{
    int SIZE = 4;
    int elm;
    int array[SIZE];
    cout << "\nEnter elements in array : \n";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> elm;
        array[i] = elm;
    }

    // printing array
    cout << endl
         << "Inp_ARRAY: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;

    int totalSum = 0, sum = 0;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            sum = 0;
            for (int s = i; s <= j; s++)
            {
                sum += array[s];
            }
            totalSum += sum;

            if (DEBUG == 1)
            {
                cout << "\nsubArray : ";
                for (int k = i; k <= j; k++)
                {
                    cout << array[k] << ", ";
                }
                cout << " -> sum is: " << sum << endl;
            }
        }
        cout << endl
             << "TotalSum till: " << totalSum << endl;
    }
    cout << endl
         << "Sum is : " << totalSum << endl;

    return 0;
}