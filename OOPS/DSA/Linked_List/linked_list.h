
#ifndef _Linked_list_
#define _Linked_list_

// #include <vector>

namespace nm_linkedList
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
            cout << "\nInitz...\n";
        }
        ~Node()
        {
            cout << "\nDestroyed Node.\n";
            // delete nodePointer;
        }
        Node *getNodeAddr() { return nodePointer; }
        int getInfo() { return info; }
        Node *getNextNode() { return nextNode; }

        friend class List;
        friend Node *allocNode(int);
        friend void deallocateNodes(Node *tmp);
    };
    Node *allocNode(int info = 6)
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

    class List
    {
    protected:
        Node *listHead;
        int countNodes;

    public:
        List(Node *head = 0) : listHead(head), countNodes(0) { cout << "\nList Intiz..\n"; }
        ~List() { cout << "\nList Remv.\n"; }

        Node *getHead() { return listHead; }
        int getNodesTot() { return countNodes; }

        void addingNodes();
        void addNode(Node *nd);
        void addNode(Node *nd, int n);
        void appendNode(Node *nd);
        void deleteNode();

        void printList();
        void printListReverse(Node *nd);

        void reverseList();
        // void sortList();
    };

    void List::addNode(Node *nd)
    {
        nd->nextNode = listHead;
        listHead = nd;
        countNodes++;
    }

    void List::appendNode(Node *nd)
    {
        Node *tempIterator = listHead;
        while (tempIterator->nextNode != NULL)
        {
            tempIterator = tempIterator->nextNode;
        }
        tempIterator->nextNode = nd;
        countNodes++;
    }

    void List::addNode(Node *nd, int n)
    {
        if (n == 1)
        {
            nd->nextNode = listHead;
            listHead = nd;
        }
        else
        {
            Node *iter = listHead;
            // let n=3, then, coz nextNode node-1 is increment to node-2, after failing condn, for node-3 implemnt
            for (int i = 1; i <= n - 2; iter = iter->nextNode, i++)
            {
                // cout << i << ": " << iter << endl ;
            }
            // cout << endl;

            Node *tmp = iter->nextNode; // tmp have prev node-3 addr
            iter->nextNode = nd;        // node-2 have new node-3 addr
            nd->nextNode = tmp;         // node-3 have node prev node-3 addr
            countNodes++;
        }
    }
    void List::addingNodes()
    {
        int option = 0;
        while (option != 4)
        {
            cout << "\nAdding Nodes to List...\n";
            cout << "\n1 : Add Elements in beginning.\n";
            cout << "\n2 : Add Elements in N'\th Position.\n";
            cout << "\n3 : Append Elements.\n";
            cout << "\n4 : Exit or Abort Addition!\n";
            cout << "\nSelect Option : ";
            cin >> option;
            if (option == 4)
            {
                cout << "\nAborting addition!\n";
                return;
            }

            int inf = 0;
            cout << "\nEnter Element : ";
            cin >> inf;
            Node *tmp = allocNode(inf);

            switch (option)
            {
            case 1:
            {
                addNode(tmp);
            }
            break;
            case 2:
            {
                int n = 0;
                if (listHead == NULL)
                {
                    cout << "\nNo Previous Element to print, Element added at beginning ..\n";
                    addNode(tmp);
                    break;
                }
                else
                {
                    printList();
                }
            agPos:
                cout << "\nEnter Position (begins with inx=1): ";
                cin >> n;
                if (n <= countNodes)
                {
                    addNode(tmp, n);
                    break;
                }
                else
                {
                    cout << "\nWrong position Selected! Try again...\n";
                    goto agPos;
                }
            }
            case 3:
            {
                appendNode(tmp);
                break;
            }
            default:
                cout << "\nWrong option selected!...Try again , \n";
                break;
            }
        }
    }

    void List::deleteNode()
    {
        if (listHead == NULL)
        {
            cout << "\nList is Empty\n";
            return;
        }
        else
        {
            int n = 0;
            printList();
            cout << "\nSelect Position to Delete. : ";
            cin >> n;
            Node *iter = listHead;
            if (n == 1)
            {
                delete iter;
            }
            else
            {
                for (int i = 1; i <= n - 2; iter = iter->nextNode, i++)
                    ;
                Node *tmp = iter->nextNode; // nth node
                iter->nextNode = tmp->nextNode;
                delete tmp;
                countNodes--;
            }
        }
    }

    void List::printList()
    {
        if (listHead == NULL)
        {
            cout << "\nList is Empty\n";
            return;
        }
        else
        {
            Node *tempIterator = listHead;
            cout << "\nList : { ";
            while (!!tempIterator) //!!opt
            {
                // cout << tempIterator << ",@: ";
                cout << tempIterator->info << ", ";
                tempIterator = tempIterator->nextNode;
            }
            cout << " }\n";
        }
    }

    void List::printListReverse(Node *nd)
    {
        if (nd == NULL)
        {
            return;
        }
        else
        {
            printListReverse(nd->nextNode);
        }
        cout << nd->info << ", ";
    }

    void List::reverseList()
    {
        Node *iterc = listHead;
        Node *prevNd = NULL;
        while (iterc)
        {
            Node *nextNd = iterc->nextNode;
            iterc->nextNode = prevNd;
            prevNd = iterc;
            iterc = nextNd;
        }
        listHead = prevNd;
    }

} // namespace nm_linkedList

#endif
