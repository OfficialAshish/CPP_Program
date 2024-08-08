#ifndef _TMPLT_DOUBLY_LL_
#define _TMPLT_DOUBLY_LL_

#include <iostream>
#include <string>
using namespace std;

namespace nm_doubly_ll_tmplt
{
    template <class T>
    class Node
    {
    public:
        Node<T> *prevNode;
        T data;
        Node<T> *nextNode;

    public:
        Node<T> *nodeAddr;
        Node(T n = T()) : nextNode(nullptr), prevNode(nullptr), data(n), nodeAddr(this)
        {
            cout << "\nConstructor..\n";
        }
        ~Node()
        {
            // cout << "\ndestructor..\n";
        }

        Node<T> *getNodeAddr() { return nodeAddr; }
        T getData() { return data; }
        Node<T> *getNextNode() { return nextNode; }
        Node<T> *getPrevNode() { return prevNode; }

        template <class X>
        friend class List;

        template <class Y>
        friend Node<Y> *allocNodes();

        template <class Z>
        friend void deallocateNodes(Node<Z> *tmp);
    };

    template <class T>
    Node<T> *allocNodes()
    {
        cout << "\nEnter Name: ";
        T nm;
        cin >> nm;
        Node<T> *tmpNode = new Node<T>(nm);
        tmpNode->nextNode = nullptr;
        tmpNode->prevNode = nullptr;
        cout << "S";

        return tmpNode;
    }

    template <class T>
    void deallocateNodes(Node<T> *tmpHead)
    {
        while (tmpHead)
        {
            Node<T> *nxNd = tmpHead->nextNode;
            delete tmpHead;
            cout << "*";
            tmpHead = nxNd;
        }
    }

    template <class T>
    class List
    {
    protected:
        Node<T> *listHead;
        Node<T> *listTail;
        int countNodes;

    public:
        List(Node<T> *p = nullptr) : listHead(p), listTail(p), countNodes(0)
        {
            cout << "\nList Constr..\n";
        }
        ~List()
        {
            cout << "\nList Remvd..\n";
            deallocateNodes(listHead);
        }

        Node<T> *getHead() { return listHead; }
        Node<T> *getTail() { return listTail; }
        int getTotalNd() { return countNodes; }

        void addingNodes();
        void addNode();    // beginning addition
        void addNode(int); // overload for between addition
        void addNodeEnd();

        void printList();
        void printRev(Node<T> *);

        void deleteNode();
        void updateData();
        void reverseList();
    };

    template <class T>
    void List<T>::addNode()
    {
        Node<T> *newNode = allocNodes<T>();
        Node<T> *tmpHead = getHead();
        if (!tmpHead)
        {
            listHead = newNode;
            listTail = newNode;
        }
        else
        {
            newNode->nextNode = tmpHead;
            newNode->prevNode = nullptr;
            tmpHead->prevNode = newNode;
            listHead = newNode;
        }
        countNodes++;
    }

    template <class T>
    void List<T>::addNode(int pos)
    {
        Node<T> *tmpHead = getHead();
        Node<T> *newNode = allocNodes<T>();
        for (int count = 1; count < pos - 1 && tmpHead != nullptr; count++, tmpHead = tmpHead->nextNode)
            ;
        if (tmpHead)
        {
            newNode->nextNode = tmpHead->nextNode;
            tmpHead->nextNode = newNode;
            newNode->prevNode = tmpHead;
            if (newNode->nextNode)
            {
                newNode->nextNode->prevNode = newNode;
            }
            else
            {
                listTail = newNode;
            }
            countNodes++;
        }
    }

    template <class T>
    void List<T>::addNodeEnd()
    {
        Node<T> *tmp = allocNodes<T>();
        Node<T> *tmpHead = getHead();
        Node<T> *tmpTail = getTail();
        if (!tmpHead)
        {
            listHead = tmp;
            listTail = tmp;
        }
        else
        {
            tmp->prevNode = tmpTail;
            tmpTail->nextNode = tmp;
            listTail = tmp;
        }
        countNodes++;
    }

    template <class T>
    void List<T>::addingNodes()
    {
        int option = 0;
        while (option != 4)
        {
            cout << "\nAdding Nodes to List...\n";
            cout << "\n1: Add Elements at beginning.\n";
            cout << "\n2: Add Elements at N'th Position.\n";
            cout << "\n3: Add Elements at End.\n";
            cout << "\n4: Exit or Abort Addition!\n";
            cout << "\nSelect Option: ";
            cin >> option;
            if (option == 4)
            {
                cout << "\nAborting addition!\n";
                return;
            }

            switch (option)
            {
            case 1:
                addNode();
                break;
            case 2:
            {
                int n = 0;
                if (listHead == nullptr)
                {
                    cout << "\nNo Previous Element to print, Element should be added at beginning...\n";
                    addNode();
                    break;
                }
                else
                {
                    printList();
                }
            againPos:
                cout << "\nEnter Position (begins with index=1): ";
                cin >> n;
                if (n <= countNodes)
                {
                    addNode(n);
                    break;
                }
                else
                {
                    cout << "\nWrong position Selected! Try again...\n";
                    goto againPos;
                }
            }
            case 3:
                addNodeEnd();
                break;
            default:
                cout << "\nWrong option selected!...Try again.\n";
                break;
            }
        }
    }

    template <class T>
    void List<T>::deleteNode()
    {
    againPos:
        Node<T> *tmpHead = getHead();
        int n = countNodes;
        printList();
        cout << "\nEnter Position to be Deleted: ";
        cin >> n;
        if (n > 1 && n < countNodes)
        {
            for (int count = 1; count < n - 1 && tmpHead != nullptr; count++, tmpHead = tmpHead->nextNode)
                ;
            if (tmpHead && tmpHead->nextNode)
            {
                Node<T> *nodeToDelete = tmpHead->nextNode;
                tmpHead->nextNode = nodeToDelete->nextNode;
                if (nodeToDelete->nextNode)
                {
                    nodeToDelete->nextNode->prevNode = tmpHead;
                }
                else
                {
                    listTail = tmpHead;
                }
                delete nodeToDelete;
                cout << "Deleted!\n";
                countNodes--;
            }
        }
        else if (n == 1)
        {
            if (!tmpHead->nextNode)
            {
                listHead = nullptr;
                delete tmpHead;
                cout << "Deleted!\n";
            }
            else
            {
                listHead = tmpHead->nextNode;
                listHead->prevNode = nullptr;
                delete tmpHead;
                cout << "Deleted!\n";
            }
            countNodes--;
        }
        else if (n == countNodes)
        {
            Node<T> *tmptail = listTail;
            if (!tmptail->prevNode)
            {
                listTail = nullptr;
                delete tmptail;
                cout << "Deleted!\n";
            }
            else
            {
                listTail = listTail->prevNode;
                listTail->nextNode = nullptr;
                delete tmptail;
                cout << "Deleted!\n";
            }
            countNodes--;
        }
        else
        {
            cout << "\nWrong position, Select Again...(y/n): ";
            char cn = 'y';
            cin >> cn;
            if (cn == 'y' || cn == 'Y')
            {
                goto againPos;
            }
            else
            {
                cout << "\nAborting...\n";
                return;
            }
        }
    }

    template <class T>
    void List<T>::updateData()
    {
        Node<T> *tmpHead = getHead();
        int n = countNodes;
        T updVal;
        printList();
        cout << "\nEnter Position to be Updated: ";
        cin >> n;
        cout << "\nEnter New Value: ";
        cin >> updVal;
        for (int count = 1; count < n && tmpHead != nullptr; count++, tmpHead = tmpHead->nextNode)
            ;
        if (tmpHead)
        {
            tmpHead->data = updVal;
        }
    }
    template <class T>
    void List<T>::reverseList()
    {
        Node<T> *tmpHead = getHead();
        Node<T> *tmpPrev = nullptr;
        Node<T> *tmpNext = nullptr;

        while (tmpHead != nullptr)
        {
            tmpNext = tmpHead->nextNode;
            tmpHead->nextNode = tmpPrev;
            tmpHead->prevNode = tmpNext;
            tmpPrev = tmpHead;
            tmpHead = tmpNext;
        }

        // Update the head and tail of the list
        listTail = listHead;
        listHead = tmpPrev;
    }

    template <class T>
    void List<T>::printList()
    {
        Node<T> *tmp = getHead();
        if (!tmp)
        {
            cout << "\nList is Empty! ...\n";
        }
        else
        {
            while (tmp)
            {
                cout << "(" << tmp->data << ") -> ";
                tmp = tmp->nextNode;
            }
        }
    }
    template <class T>
    void List<T>::printRev(Node<T> *tmpNd)
    {
        if (!tmpNd)
        {
            return;
        }
        else
        {
            printRev(tmpNd->nextNode);
        }
        cout << "(" << tmpNd->data << ") -> ";
    }
} // namespace nm_doubly_ll_tmplt

#endif