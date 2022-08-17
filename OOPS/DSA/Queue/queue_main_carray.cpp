#include <iostream>
#include "queue_ll.h"
#define SIZE 8
using namespace std;

class c_queue
{
    int arr[SIZE];
    int front;
    int rear;

public:
    c_queue() : front(-1), rear(-1)
    {
        for (int i = 0; i < SIZE; arr[i] = 0, i++);
        cout << "\nContr..\n";
    }
    ~c_queue() { cout << "\nDestr..\n"; }

    bool isempty() { return rear == -1; }
    int frontElem() { return front; }
    int rearElem() { return rear; }

    void enQueue(int dt)
    {
        if (front == -1)
        {
            front == rear == 0;
            arr[front] = dt;
        }
        else if (rear == SIZE - 1)
        {
            cout << "\nQueue is Full.\n";
        }
        else
        {
            arr[++rear] = dt;
        }
    }

    int deQueue()
    {
        int tmpout;
        if (front == rear)
        {
            tmpout = arr[front];
            arr[front] = 0;
            front = rear = -1;
            return tmpout;
        }
        else if (rear == -1)
        {
            cout << "\nQueue is Empty!.\n";
        }

        tmpout = arr[front];
        arr[front] = 0;
        front++;
        return tmpout;
    }
    void print()
    {
        cout << "\nQueue is :\n { ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[front] << " ,";
        }
        cout << " }\n";
    }
};

int main()
{
    int option = -1;
    c_queue cArr;
    while (option != 6 and option != 0)
    {
        cout << "\n* Queue(Circular Array) *\n";
        cout << "\nSelect Opration to perform on Queue!\n";
        cout << "\n1 : Insert. (EnQueue)\n";
        cout << "\n2 : Delete Element. (DeQueue).\n";
        cout << "\n3 : Front element.\n";
        cout << "\n4 : Rear element(end).\n";
        cout << "\n5 : Print Queue.\n";
        cout << "\n6 : Exit Program!.\n";
        cout << "\nSELECT Option : ";
        cin >> option;
        int i = 0;
        if (option == 1)
        {
            cout << "\nEnter Element : ";
            cin >> i;
        }

        switch (option)
        {
        case 1:
            cArr.enQueue(i);
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 2:
            cout << "\nElement Poped. *";
            cout << cArr.deQueue();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 3:
            cout << cArr.frontElem();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 4:
            cout << cArr.rearElem();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 5:
            cArr.print();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;

        case 6:
            cout << "\nExiting Program!!!\n";
            return 0;
            break;

        default:
            cout << "\n"
                 << option << "Wrong option selected !... Try again, \n ";
            break;
        }
    }

    return 0;
}