#include <iostream>
#include <queue>
using namespace std;
#include <algorithm>

// (max_size/2) - 1 ,from here heapify the arr
void heapify(int *array, int sz, int i);

class heap
{
    int *array;
    int index;
    int max_size; // zero indexing
public:
    heap(int s) : max_size(s), index(-1), array(new int[s]) {}
    heap(int *arr, int mx_s) : max_size(mx_s), index(mx_s-1)
    {
        // size_t isnt for i>=0,!imp &u knows the reason now
        array = new int[max_size];
        copy(arr, arr + mx_s, array);
        for (int i = (max_size/2) -1; i >= 0; i--)
            heapify(array, max_size, i);
        
        // for(int i=0;i<max_size;i++) cout<<array[i]<<",";
    }

    int *getArray() { return this->array; }
    int getArraySize() { return this->max_size; }

    friend void heapSort(int *, int);
    friend void heapify(int *, int, int);

    void insertH(int elem)
    {
        this->index++;
        this->array[index] = elem;
        int idx = this->index;
        while (idx > 0)
        {
            // zero indexing
            int parent = (idx - 1) / 2;
            if (array[parent] < array[index])
            {
                swap(array[parent], array[index]);
                idx = parent;
            }
            else
                break;
        }
    }

    void deleteH()
    {
        if (index == -1)
        {
            cout << "Heap is empty." << endl;
            return;
        }
        this->index--;
        array[0] = array[index];
        heapify(array, index, 0);
    }

    void print()
    {
        if (index == -1)
        {
            cout << "Heap is empty." << endl;
            return;
        }
        cout << "\nPrinting Heap:  \n";
        for (size_t i = 0; i <= this->index; i++)
        {
            cout << this->array[i] << ", ";
        }
    }
    void levelOrderPrint()
    {
        if (index == -1)
        {
            cout << "Heap is empty." << endl;
            return;
        }
        cout << "\nPrinting Heap:  \n";

        queue<pair<int, int>> nodesQueue;
        nodesQueue.push({0, 0});
        int prevLevel = 0;
        while (!nodesQueue.empty())
        {
            int current = nodesQueue.front().first;
            int level = nodesQueue.front().second;
            nodesQueue.pop();

            if (level != prevLevel)
            {
                cout << endl; // New line for each level
                prevLevel = level;
            }

            // for (int i = 0; i < level; ++i) {
            //     cout << "    "; // Indent based on the level
            // }

            cout << array[current] << " ";

            int leftChild = 2 * current + 1;
            int rightChild = 2 * current + 2;

            if (leftChild < max_size)
                nodesQueue.push({leftChild, level + 1});
            if (rightChild < max_size)
                nodesQueue.push({rightChild, level + 1});
        }
    }

    ~heap() { delete[] array; }
};

void heapify(int *array, int sz, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < sz && array[largest] < array[left])
        largest = left;
    if (right < sz && array[largest] < array[right])
        largest = right;
    if (largest != i)
    {
        swap(array[largest], array[i]);
        heapify(array, sz, largest);
    }
}

void heapSort(int *arr, int sz)
{
    for (int i = sz - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main(int argc, char const *argv[])
{
    // int arr[] = {54, 32, 98, 56, 33, 51, 30, 44, 65, 36};
    // int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int arr[] = {1,2,3,4,5,6,7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    heap hpR = heap(arr, arr_size);
    hpR.levelOrderPrint();

    heapSort(hpR.getArray(), hpR.getArraySize());

    hpR.print();
    // hpR.levelOrderPrint();

    // heap hpR = heap(50);
    // hpR.insertH(30);
    // hpR.insertH(40);
    // hpR.insertH(35);
    // hpR.insertH(45);
    // hpR.insertH(25);
    // hpR.insertH(50);
    // hpR.print();
    // hpR.deleteH();
    // hpR.print();

    return 0;
}
