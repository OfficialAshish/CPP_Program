
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
        Node(int i = 0) : info(i), nextNode(0)
        { /* cout << "\nNot-Dynm Initz...\n"; */
        }
        ~Node() {cout<<"\nDestr..\n";}
        void printNodeAddr()
        {
            cout << this;
        }

        friend class List;
    };

    class DmNode
    {
    public:
        int infoD;
        DmNode *nextNodeD;

    public:
        DmNode *nodePointerD;
        DmNode(int i = 0) : infoD(i)
        {
            cout << "\nDynm Initz...\n";
        }
        ~DmNode()
        {
            cout << "\nDestroyed DmNode.\n";
            // delete nodePointerD;
        }
        DmNode *getNodeAddr() { return nodePointerD; }
        friend DmNode *allocNode(int);
    };
    DmNode *allocNode(int info =6)
    {
        DmNode *tmpPoint;
        tmpPoint = new DmNode();
        tmpPoint->infoD = info;
        tmpPoint->nextNodeD = NULL;
        tmpPoint->nodePointerD = tmpPoint;
        return tmpPoint;
    }

    class List
    {
    protected:
        Node *listHead;

    public:
        List(Node *head = 0) : listHead(head) { cout << "\nList Intiz..\n"; }
        ~List() { cout << "\nList Remv.\n"; }

        Node *getHead() { return listHead; }

        void addNode(Node *nd);
        void addNode(Node *nd, int n);
        void appendNode(Node *nd);

        void printList();
        void printListReverse(Node *nd);

        void reverseList();
        // void sortList();
    };

    void List::addNode(Node *nd)
    {
        Node *currentHead = listHead;
        nd->nextNode = listHead;
        listHead = nd;
    }

    void List::appendNode(Node *nd)
    {
        Node *tempIterator = listHead;
        while (tempIterator->nextNode != NULL)
        {
            tempIterator = tempIterator->nextNode;
        }
        tempIterator->nextNode = nd;
    }

    void List::addNode(Node *nd, int n)
    {
        Node *iter = listHead;
        // let n=3, then, coz nextNode node-1 is increment to node-2, after failing condn, for node-3 implemnt
        for (int i = 1; i <= n - 2; iter = iter->nextNode, i++)
        {
            // cout << i << ": " << iter << endl ;
        }
        cout << endl;

        Node *tmp = iter->nextNode; // tmp have prev node-3 addr
        iter->nextNode = nd;        // node-2 have new node-3 addr
        nd->nextNode = tmp;         // node-3 have node prev node-3 addr
    }

    void List::printList()
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
        while (iterc->nextNode)
        {
            Node *nextNd = iterc->nextNode;
            iterc->nextNode = prevNd;
            prevNd = iterc;
            iterc = nextNd;
        }
        iterc->nextNode = prevNd;
        listHead = iterc;
    }

} // namespace nm_linkedList

#endif
