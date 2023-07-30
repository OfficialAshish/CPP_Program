#include <iostream>
#include <queue>
using namespace std;
#include <algorithm>

void heapify(int *array, int sz, int i);

class heap
{
    int *array;
    int size;
    int max_size; // zero indexing
public:
    heap(int s) : max_size(s), size(0), array(new int[s]) {}
    heap(int *arr, int mx_s) : max_size(mx_s), size(mx_s)
    {
        // size_t isnt for i>=0,!imp &u knows the reason now
        array = new int[max_size];
        copy(arr, arr + mx_s, array);
        for (int i = (size / 2); i >= 0; i--)
            heapify(array, max_size, i);
    }

    int* getArray(){ return this->array;}
    int getArraySize(){return this->size;}

    friend void heapSort(int *, int);
    friend void heapify(int *, int, int);

    void insertH(int elem)
    {
        // zero indexing
        int index = this->size;
        this->array[size] = elem;
        this->size++;
        while (index > 0)
        {
            int parent = index / 2;
            if (array[parent] < array[index])
            {
                swap(array[parent], array[index]);
                index = parent;
            }
            else
                break;
        }
    }

    void deleteH()
    {
        if (size == 0)
        {
            cout << "Heap is empty." << endl;
            return;
        }
        array[0] = array[size - 1];
        this->size--;
        heapify(array, size, 0);
    }

    void print()
    {
        if (size == 0)
        {
            cout << "Heap is empty." << endl;
            return;
        }
        cout << "\nPrinting Heap:  \n";
        for (size_t i = 0; i < this->size; i++)
        {
            cout << this->array[i] << ", ";
        }
    }
    void levelOrderPrint()
    {
        if (size == 0)
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

            if (leftChild < size)
                nodesQueue.push({leftChild, level + 1});
            if (rightChild < size)
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
    if (sz > left && array[largest] < array[left])
        largest = left;
    if (sz > right && array[largest] < array[right])
        largest = right;
    if (largest != i)
    {
        swap(array[largest], array[i]);
        heapify(array, sz, largest);
    }
}

void heapSort(int *arr, int sz)
{
    int end_index = sz - 1;
    while (end_index > 1)
    {
        swap(arr[end_index], arr[0]);
        end_index--;
        heapify(arr, end_index, 0);
        cout<<arr[end_index]<<". ";
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {54, 32, 98, 56, 33, 51, 30, 44, 65, 36};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    heap hpR = heap(arr, arr_size);
    hpR.levelOrderPrint();
    heapSort(hpR.getArray(),hpR.getArraySize());
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
