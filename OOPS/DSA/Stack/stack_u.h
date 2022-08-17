
#ifndef Stack_udt_
#define Stack_udt_

namespace nm_stack
{
    using namespace std;

    class Node
    {
    protected:
        int info;
        Node *nextNode;

    public:
        Node *nodePointer;
        Node(int i = 0) : info(i), nextNode(0)
        {
            // cout << "\nNode Allocated...\n";
        }
        ~Node()
        {
            // cout << "\nDestroyed Node.\n";
            // delete nodePointer;
        }
        Node *getNodeAddr() { return nodePointer; }
        int getInfo() { return info; }
        Node *getNextNode() { return nextNode; }

        friend class Stack;
        friend Node *allocNode(int);
        friend void deallocateNodes(Node *tmp);
    };
    Node *allocNode(int info = 0)
    {
        Node *tmpPoint;
        tmpPoint = new Node();
        tmpPoint->info = info;
        tmpPoint->nextNode = NULL;
        tmpPoint->nodePointer = tmpPoint;
        return tmpPoint;
    }
    void deallocateNodes(Node *tmp)
    {
        while (tmp != NULL)
        {
            Node *next = tmp->nextNode;
            delete tmp;
            tmp = next;
        }
    }

    class Stack
    {
    protected:
        Node *listHead;
        int countNodes;

    public:
        Stack(Node *head = 0) : listHead(head), countNodes(0) { cout << "\nStack Intiz..\n"; }
        ~Stack() { cout << "\nStack Remv.\n"; }

        Node *getHead() { return listHead; }
        int getNodesTot() { return countNodes; }

        void insert(int i);
        int pop();
        int top();
        bool isempty(){ return listHead == NULL;}
        void printStack();
    };


    void Stack::insert(int i)
    {
        Node *nd = allocNode(i);
        nd->nextNode = listHead;
        listHead = nd;
        countNodes++;
    }

    int Stack::pop()
    {
        if (listHead == NULL)
        {
            cout << "\nStack is Empty\n";
            return 0;
        }
        else
        {
            Node *tmp = listHead;
            listHead = listHead->nextNode;
            int result = tmp->info;
            delete tmp;
            countNodes--;
            return result;
        }
    }

    int Stack::top()
    {
        if (listHead == NULL)
        {
            cout << "\nStack is Empty\n";
            return 0;
        }
        else
        {
            return listHead->info;
        }
    }


void Stack::printStack()
{
    if (listHead == NULL)
    {
        cout << "\nList is Empty\n";
        return;
    }
    else
    {
        Node *tempIterator = listHead;
        cout << "\nStack : { ";
        while (!!tempIterator) //!!opt
        {
            // cout << tempIterator << ",@: ";
            cout << tempIterator->info << ", ";
            tempIterator = tempIterator->nextNode;
        }
        cout << " }\n";
    }
}
} // namespace nm_stack

#endif
