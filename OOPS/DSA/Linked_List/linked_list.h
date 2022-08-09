
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
        Node(int i = 0) : info(i), nextNode(0) { cout << "\nNot-Dynm Initz...\n"; }
        ~Node() {}
        void printNodeAddr()
        {
            printf("\nNode Addrs: %u \n", this);
        }

        friend class List;
    };

    /*
    class dynmNode
    {
    protected:
        int infoD;
        Node *nextNodeD;
        // Node *NodePointer  = new Node(0);

    public:
        Node(int i=0) : infoD(i), nextNodeD(0) {cout<<"\nDynm Initz...\n"; }
        ~Node() { }
    };
    */

    class List //: public Node
    {
    protected:
        Node *listHead;

    public:
        List(Node *head = 0) : listHead(head) { cout << "\nList Intiz..\n"; }
        ~List() { cout << "\nList Remv.\n"; }

        void addNode(Node *nd);
        void addNode(Node *nd, int n);
        void appendNode(Node *nd);

        void printList();
        void printListReverse();

        void reverseList();
        void sortList();
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

    void List::printList()
    {
        Node *tempIterator = listHead;
        cout << "\nList : { ";
        while(!!tempIterator)
        {
            // cout << tempIterator << ",@: ";
            cout << tempIterator->info << ", ";
            tempIterator = tempIterator->nextNode;
        }
        cout << " }\n";
    }

} // namespace nm_linkedList

#endif
