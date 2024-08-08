
#ifndef Stack_udt_
#define Stack_udt_

namespace nm_stack
{
    using namespace std;
    template <class T>
    class Node
    {
    protected:
        T info;
        Node<T> *nextNode;

    public:
        Node<T> *nodePointer;
        Node<T>(T i = T()) : info(i), nextNode(0)
        {
            // cout << "\nNode Allocated...\n";
        }
        ~Node<T>()
        {
            // cout << "\nDestroyed Node.\n";
        }
        // Node *getNodeAddr() { return nodePointer; }
        // int getInfo() { return info; }
        // Node *getNextNode() { return nextNode; }

        template <class U>
        friend class Stack;

        template <class V>
        friend Node<V> *allocNode(V);
        template <class W>
        friend void deallocateNodes(Node<W> *tmp);
    };
    template <class T>
    Node<T> *allocNode(T info = T())
    {
        Node<T> *tmpPoint;
        tmpPoint = new Node<T>(info);
        tmpPoint->nodePointer = tmpPoint;
        return tmpPoint;
    }
    template <class T>
    void deallocateNodes(Node<T> *tmp)
    {
        while (tmp != NULL)
        {
            Node<T> *next = tmp->nextNode;
            delete tmp;
            tmp = next;
        }
    }
    template <class T>
    class Stack
    {
    protected:
        Node<T> *listHead;
        int countNodes;

    public:
        Stack(Node<T> *head = nullptr) : listHead(head), countNodes(0) { cout << "\nStack Intiz..\n"; }
        ~Stack() { cout << "\nStack Remv.\n"; }

        Node<T> *getHead() { return listHead; }
        int getNodesTot() { return countNodes; }

        bool isempty() { return listHead == NULL; }
        // void insert(T);
        // int pop();
        // int top();
        // void printStack();

        void insert(T val)
        {
            Node<T> *nd = allocNode<T>(val);
            nd->nextNode = listHead;
            listHead = nd;
            countNodes++;
        }

        T pop()
        {
            if (listHead == NULL)
            {
                cout << "\nStack is Empty\n";
                return T();
            }
            else
            {
                Node<T> *tmp = listHead;
                listHead = listHead->nextNode;
                T result = tmp->info;
                delete tmp;
                countNodes--;
                return result;
            }
        }

        T top()
        {
            if (listHead == NULL)
            {
                cout << "\nStack is Empty\n";
                return T();
            }
            else
            {
                return listHead->info;
            }
        }

        void printStack()
        {
            if (listHead == NULL)
            {
                cout << "\nList is Empty\n";
                return;
            }
            else
            {
                Node<T> *tempIterator = listHead;
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
    };
} // namespace nm_stack

#endif
