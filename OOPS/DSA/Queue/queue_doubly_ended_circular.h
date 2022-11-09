
#ifndef _Queue_de_c_
#define _Queue_de_c_

namespace nm_de_c_queue
{
    using namespace std;

    class de_c_queue
    { /*
     private:
         int max_size;
         int *arr;
         int front, rear;

     public:
         de_c_queue(int sz = 5) : max_size(sz), front(-1), rear(-1)
         {
             arr = new int[sz];
             cout << "Constr.." << endl;
         } */

    public:
        int max_size;
        int arr[5];
        int front, rear;

    public:
        de_c_queue(int sz = 5) : max_size(sz), front(-1), rear(-1)
        {
            // arr = new int[sz];
            cout << "Constr.." << endl;
        }
        ~de_c_queue()
        {
            // delete[] arr;
            cout << "Destr.." << endl;
        }

        void push_front(int elem);
        void push_rear(int elem);
        int pop_front();
        int pop_rear();
        int peek_rear();
        int peek_front();
        int size();
        bool isEmpty();
        void print();
    };

    bool de_c_queue::isEmpty()
    {
        if (rear == -1)
            return true;
        else
            false;
    }
    int de_c_queue::size()
    {
        if (front <= rear)
            return rear - front;
        else
            return (max_size - (front - rear + 1));
    }
    void de_c_queue::push_rear(int elem)
    {
        if ((rear == max_size - 1 && front == 0) or (rear == (front - 1) % (max_size - 1) && front != 0))
        {
            cout << "\nQueue is Full! " << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            cout << "fst";
        }
        else if (rear == max_size - 1)
        {
            rear = 0; //(rear + 1) % max_size; //=0
        }
        else
            rear++;
        arr[rear] = elem;
    }

    void de_c_queue::push_front(int elem)
    {
        if ((front != 0 and (front - 1 == rear)) or (front == 0 and (rear == max_size - 1)))
        {
            cout << "\nQueue is Full! " << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 and rear != max_size - 1)
        {
            cout << 'sec';
            front = max_size - 1;
        }
        else
        {
            cout << 'thd ';
            front = front - 1;
        }
        arr[front] = elem;
    }

    int de_c_queue::pop_rear()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty! " << endl;
            return -1;
        }
        int a = arr[rear];

        if (rear == front)
        {
            rear = front = -1;
        }
        else if (rear == max_size - 1 && front != 0)
        {
            rear = 0;
        }
        else
            rear--;
        return a;
    }

    int de_c_queue::pop_front()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty! " << endl;
            return -1;
        }
        int a = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            rear = front = -1;
        }
        else if (front == 0 and rear != max_size - 1)
        {
            front = max_size - 1;
        }
        else
            front--;
        return a;
    }

    int de_c_queue::peek_front()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty! " << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    int de_c_queue::peek_rear()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty! " << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    void de_c_queue::print()
    {
        for (int i = 0; i < max_size; i++)
        {
            cout << arr[i] << ", ";
        }
    }

}

#endif