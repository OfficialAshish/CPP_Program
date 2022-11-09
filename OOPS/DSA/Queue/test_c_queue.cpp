#include <iostream>
using namespace std;

class MyCircularQueue
{
public:
    int *arr;
    int front, rear, size;

    MyCircularQueue(int k)
    {
        size = k;
        arr = new int[k];
        front = rear = -1;
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear != 0 && front == size - 1)
        {
            rear = 0;
        }
        else
            rear++;
        arr[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        else if (rear == front)
        {
            rear = front = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
            front++;
        return true;
    }

    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
            return arr[front];
    }

    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
            return arr[rear];
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) or (rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        else
            return false;
    }
};
// if ((front == 0 && rear == size - 1) or ((front == (rear + 1) % size) && front != 0))

int main(int argc, char const *argv[])
{
    MyCircularQueue *obj = new MyCircularQueue(7);
    bool param_1 = obj->enQueue(11);
    bool param_11 = obj->enQueue(12);
    bool param_12 = obj->enQueue(13);
    bool param_13 = obj->enQueue(14);
    bool param_14 = obj->enQueue(0);
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
    bool param_2 = obj->deQueue();
    cout << param_1 << "\n"
         << param_11 << "\n"
         << param_12 << "\n"
         << param_2 << "\n"
         << param_3 << "\n"
         << param_4 << "\n"
         << param_5 << "\n"
         << param_6 << "\n";
    ;

    return 0;
}
