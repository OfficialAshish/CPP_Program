
#ifndef _Queue_ll_
#define _Queue_ll_

namespace nm_queue
{
    using namespace std;

    class Node
    {
    protected:
        int info;
        Node *nextNode;

    public:
        Node(int dt = 0) : info(dt), nextNode(0) { /* cout << "\nNode constr..\n"; */ }
        ~Node() { /* cout << "\nNode Dest..\n"; */ }

        int getInfo() { return this->info; }

        friend class Queue;
        friend Node *allocNode(int); // allocates & adds to list
        friend void deallocNodes(Node *);
    };

    class Queue
    {
    protected:
        Node *listFront;
        Node *listRear;

    public:
        Queue() : listFront(0), listRear(0) { cout << "\nList contr..\n"; }
        ~Queue() { cout << "\nList dest..\n"; }

        Node *getFront() { return (listFront); }
        // Node *getRear(){return (listRear);}

        void enQueue(int);
        int deQueue();
        int front();
        bool isempty();
        void printQueue();
        friend void deallocNodes(Node *);
    };

    Node *allocNode(int dt = 0)
    {
        Node *aln = new Node(dt);
        if (!aln)
        {
            cout << "\nUnable to allocate..\n";
            exit(1);
        }
        return aln;
    }
    void deallocNodes(Node *front)
    {
        Node *tmpNext;
        // Node *front = listFront;
        cout << endl;
        while (front)
        {
            tmpNext = front->nextNode;
            delete front;
            cout << "*";
            front = tmpNext;
        }
        // cout << "Deallocated all Nodes..\n";
    }

    void Queue::enQueue(int dt)
    {
        Node *tmpAdd = allocNode(dt);
        if (listFront == NULL)
        {
            listFront = listRear = tmpAdd;
        }
        else
        {
            listRear->nextNode = tmpAdd;
            listRear = tmpAdd;
        }
        
    }

    int Queue::deQueue()
    {
        if (listFront == NULL)
        {
            cout << "\nQueue is empty.\n";
            return 0;
        }

        Node *tmpDel = listFront;
        int res = listFront->info;
        listFront = listFront->nextNode;
        delete tmpDel;
        return res;
    }

    int Queue::front()
    {
        if (listFront == NULL)
        {
            cout << "\nQueue is Empty\n";
            return 0;
        }
        else
        {
            return listFront->info;
        }
    }

    bool Queue::isempty()
    {
        return (listFront == listRear);
    }

    void Queue::printQueue()
    {
        Node *tmp = listFront;
        cout << "{ ";
        while (tmp)
        {
            cout << tmp->info << " ,";
            tmp = tmp->nextNode;
        }
        cout << " }" << endl;
    }
} // namespace nm_queue

#endif
