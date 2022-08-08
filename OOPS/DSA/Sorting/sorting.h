
#ifndef _Sorting_All_
#define _Sorting_All_
#define DEBUG 0
#include <vector>

using namespace std;

namespace nm_sorting_
{
    class Sorting
    {
    protected:
        vector<int> array;

    public:
        Sorting();
        ~Sorting();

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
            for (int i = 1; i < arr.size() ; i++)
            {
                int j = i-1;
                int current = arr[i];

                while (arr[j] > current && j>=0)
                {
                    arr[j+1]= arr[j];
                    j--;
                }
                arr[j+1] = current;
            
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
    };

    Sorting::Sorting() {}

    Sorting::~Sorting()
    {
        // cout << "\nDestr..\n";
    }

} // namespace nm_sorting_

#endif
