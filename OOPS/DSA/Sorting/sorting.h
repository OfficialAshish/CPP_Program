
#ifndef _Sorting_All_
#define _Sorting_All_
#define DEBUG 0
#include <vector>

using namespace std;

namespace nm_sorting_
{
    class Sorting_
    {
    protected:
        vector<int> array;

    public:
        Sorting_();
        ~Sorting_();

        void swap(auto &sw_1, auto &sw_2)
        {
            auto temp = sw_1;
            sw_1 = sw_2;
            sw_2 = temp;
        }

        void selectionSort(vector<int> &arr)
        {
            for (int i = 0; i < arr.size() - 1; i++)
            {
                for (int j = i + 1; j < arr.size(); j++)
                {
                    if (arr[i] > arr[j])
                    {
                        swap(arr[i], arr[j]);
                    }
                }
                // debugging
                if (DEBUG == 1)
                {
                    cout << "\n { ";
                    for (int d = 0; d < arr.size(); d++)
                    {
                        cout << arr[d] << ", ";
                    }
                    cout << " } \n";
                }
            }
            array = arr;
        }

        void bubbleSort(vector<int> &arr)
        {
            for (int i = 0; i < arr.size() - 1; i++)
            {
                for (int j = 0; j < arr.size() - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
                // debugging...
                if (DEBUG == 1)
                {
                    cout << "\n { ";
                    for (int d = 0; d < arr.size(); d++)
                    {
                        cout << arr[d] << ", ";
                    }
                    cout << " } \n";
                }
            }
        }

        void insertionSort(vector<int> &arr)
        {
            for (int i = 1; i < arr.size(); i++)
            {
                int j = i - 1;
                int current = arr[i];

                while (arr[j] > current && j >= 0)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = current;

                // debugging...
                if (DEBUG == 1)
                {
                    cout << "\n { ";
                    for (int d = 0; d < arr.size(); d++)
                    {
                        cout << arr[d] << ", ";
                    }
                    cout << " } \n";
                }
            }
        }

        void merge(vector<int> &arr, int l, int mid, int r)
        {
            int n1 = mid - l + 1; //+1 for including mid
            int n2 = r - mid;
            int na1[n1], na2[n2];
            // cout << "merge call @" << endl;
            for (int i = 0; i < n1; i++)
            {
                na1[i] = arr[i + l];
            }
            for (int i = 0; i < n2; i++)
            {
                na2[i] = arr[i + mid + 1];
            }
            int i = 0, j = 0, k = l;
            while (i < n1 and j < n2)
            {
                if (na1[i] < na2[j])
                {
                    arr[k++] = na1[i++];
                }
                else
                {
                    arr[k++] = na2[j++];
                }
            }
            while (i < n1)
            {
                arr[k++] = na1[i++];
            }
            while (j < n2)
            {
                arr[k++] = na2[j++];
            }
        }

        void mergeSort(vector<int> &arr, int l, int r) // r=size
        {
            if (l < r)
            {
                int mid = ((r - l) / 2) + l;
                mergeSort(arr, l, mid);
                mergeSort(arr, mid + 1, r);

                merge(arr, l, mid, r);

                // debugging...
                if (DEBUG == 1)
                {
                    cout << endl
                         << l << ", " << r << endl;
                    cout << "\n { ";
                    for (int d = 0; d < arr.size(); d++)
                    {
                        cout << arr[d] << ", ";
                    }
                    cout << " } \n";
                }
            }
        }

        int partition(vector<int> &ar, int lf, int rt)
        {
            int i = lf, j = rt;
            int pivot = ar[lf];

            while (i < j)
            {
                while (ar[i] <= pivot)
                    i++;
                while (ar[j] > pivot)
                    j--;
                if (i < j)
                {
                    swap(ar[i], ar[j]);
                }
            }
            swap(ar[lf], ar[j]);
            return j;
        }
        void quickSort(vector<int> &arr, int l, int r)
        {
            if (l < r)
            {
                int pivot_index = partition(arr, l, r);
                quickSort(arr, l, pivot_index - 1);
                quickSort(arr, pivot_index + 1, r);

                // debugging...
                if (DEBUG == 1)
                {
                    cout << endl
                         << l << ", " << r << endl;
                    cout << "\n { ";
                    for (int d = 0; d < arr.size(); d++)
                    {
                        cout << arr[d] << ", ";
                    }
                    cout << " } \n";
                }
            }
        }
    };

    Sorting_::Sorting_() {}

    Sorting_::~Sorting_()
    {
        // cout << "\nDestr..\n";
    }

} // namespace nm_sorting_

#endif
