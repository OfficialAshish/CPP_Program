#include <iostream>
#include <vector>
#include "sorting.h"

using namespace nm_sorting_;
using namespace std;

int main()
{
    vector<int> arr_inp;
    int n = 10;
    // cout << "\nEnter num. of elements :\n";
    // cin >> n;
    // for (int i = 0, temp = 0; i < n; i++)
    // {
    //     cin >> temp;
    //     arr_inp.push_back(temp);
    // }

    int ar[10]={ 4, 5, 3, 8, 2, 1, 0, 4, 9, 6};
    arr_inp.assign(ar, ar+10);

    Sorting sortSel;
    sortSel.selectionSort(arr_inp);

    cout<<"\nSelection Sort :  ";
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr_inp[i] << " " ;
    }

    arr_inp.assign(ar, ar+10);
    sortSel.bubbleSort(arr_inp);

    // cout << endl;
    cout << "\nBubble Sort    : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr_inp[i] << " " ;
    }

    arr_inp.assign(ar, ar+10);
    sortSel.insertionSort(arr_inp);

    // cout << endl;
    cout << "\nInsertion Sort :  ";
    for (int i = 0; i < n; i++)
    {
        cout << arr_inp[i] << " " ;
    }
    cout << endl;
}