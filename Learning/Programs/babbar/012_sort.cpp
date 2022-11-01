#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void sort012(vector<int> &ar)
{
    int low = 0, btw = 0, high = ar.size() - 1;

    while (btw <= high)
    {
        if (ar[btw] == 0)
        {
            swap(ar[btw], ar[low]);
            low++;
            btw++;
        }
        else if (ar[btw] == 2)
        {
            swap(ar[btw], ar[high]);
            high--;
        }
        else if (ar[btw] == 1)
        {
            btw++;
        }
    }
}

int main(int argc, char const *argv[])
{
    time_t start, end;
    time(&start);
    vector<int> ar = {2, 0, 1, 0, 2, 1, 0, 1, 2, 0};

    sort012(ar);
    // sort(ar.begin(), ar.end());

    int i = 0, j = ar.size() - 1;

    /*
        while (i < j)
        {
            cout << ".";

            while (ar[i] > 1)
                i++;
            while (ar[j] > 0)
            {
                if (ar[j] < ar[j - 1]) // 2<1
                {
                    swap(ar[j], ar[j - 1]);
                    j--;
                }
                else if (ar[j] == 2)
                {
                    j--;
                }
                else
                    break;
            }
            if (ar[i] > ar[j])
            {
                swap(ar[i], ar[j]);
                i++;
                j--;
            }
        }

    while (i < j)
    {
        // cout << ".";
        while (ar[i] == 0)
            i++;
        while (ar[j] == 2)
            j--;
        if (ar[j] == 1)
        {
            j--;
            continue;
        }
        if (i < j)
        {
            swap(ar[i], ar[j]);
            i++;
            j--;
        }
    }
    j = ar.size() - 1;
    while (i < j)
    {
        while (ar[i] == 1)
            i++;
        while (ar[j] == 2)
            j--;
        if (i < j)
        {
            swap(ar[i], ar[j]);
            i++;
            j--;
        }
    }
    */
    time(&end);
    for (int i = 0; i < ar.size(); i++)
    {
        cout << ar[i] << ", ";
    }
    double time_taken = double(end - start);
    cout << "Time:" << fixed
         << time_taken /* << setprecision(5) */;
    cout << " sec " << endl;

    return 0;
}

/* class Solution {
public:
    void sortColors(vector<int>& a) {
        // quick sort algo with pivot 1
        int p = 1;
        int l = 0, r = a.size() - 1;
        for(int i = 0; i <= r; i++) {
            if(a[i] < p) {
                swap(a[i], a[l]);
                l++;
            } else if(a[i] > p) {
                swap(a[i], a[r]);
                r--;
                i--;
            }
        }
    }
}; */