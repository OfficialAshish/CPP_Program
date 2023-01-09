#include <iostream>
#include <string>

using namespace std;

class Node
{
protected:
    Node *prevNode;
    string data;
    Node *nextNode;

public:
    Node *nodeAddr;
    Node(string n = "EMPTY") : nextNode(NULL), prevNode(NULL), data(n), nodeAddr(this) { cout << "\nConstructor..\n"; }
    ~Node()
    { /* cout << "\ndestructor..\n"; */
    }

    Node *getNodeAddr() { return nodeAddr; }
    string getData() { return data; }
    Node *getNextNode() { return nextNode; }
    Node *getPrevNode() { return prevNode; }

    friend class List;
    friend Node *allocNodes();
    friend void deallocateNodes(Node *tmp);
};

Node *allocNodes()
{
    cout << "\nEnter Name :";
    string nm;
    // getline(cin, nm);
    cin >> nm;
    Node *tmpNode = new Node();
    tmpNode->data = nm;
    tmpNode->nextNode = NULL;
    tmpNode->prevNode = NULL;
    // cout << "S";

    return tmpNode;
}
void deallocateNodes(Node *tmpHead)
{
    while (tmpHead)
    {
        Node *nxNd = tmpHead->nextNode;
        delete tmpHead;
        cout << "*";
        tmpHead = nxNd;
    }
}

class List
{
protected:
    Node *listHead;
    Node *listTail;
    int countNodes;

public:
    List(Node *p = NULL) : listHead(p), listTail(p), countNodes(0) { cout << "\nList Constr..\n"; }
    ~List() { cout << "\nList Remvd..\n"; }

    Node *getHead() { return listHead; }
    Node *&setHead() { return listHead; }
    Node *getTail() { return listTail; }
    int getTotalNd() { return countNodes; }

    void addingNodes();
    void addNode();    // beginning addition
    void addNode(int); // overload for between addition.. (alternative-> by default parameter 0)
    void addNodeEnd();

    void printList();
    void printRev(Node *);

    void deleteNode();
    void updateData();
    void reverseList();
    Node *reverseList(Node *);
};
void List::addNode()
{
    Node *newNode = allocNodes();
    Node *tmpHead = getHead();
    if (!tmpHead) // without !this it won't works
    {
        listHead = newNode;
        listTail = newNode;
    }
    else
    {
        newNode->nextNode = tmpHead; // null to second node addr, // newNode->prevNode should remains null(1st node)
        tmpHead->prevNode = newNode; // null to prev node, pointing to first
        listHead = newNode;          // list pointing to newnode
    }
    countNodes++;
}
void List::addNode(int pos)
{
    Node *tmpHead = getHead();
    Node *newNode = allocNodes();
    for (int count = 1; (count++ <= pos - 2); tmpHead = tmpHead->nextNode)
        ; // tmpHead is already in node 1, THINK LITTLE!
    newNode->nextNode = tmpHead->nextNode;
    tmpHead->nextNode = newNode;
    newNode->prevNode = tmpHead;           // tmpHead is prev to newNode
    newNode->nextNode->prevNode = newNode; // updating prev of nextNode to newNode
    countNodes++;
}
void List::addNodeEnd()
{
    Node *tmp = allocNodes();
    Node *tmpHead = getHead();
    Node *tmpTail = getTail();
    if (!tmpHead)
    {
        listHead = tmp;
    }
    else if (tmpTail->nextNode == NULL)
    {
        tmp->prevNode = tmpTail;
        tmpTail->nextNode = tmp;
        tmpTail = tmp;
    }
    else
    {
        while (tmpHead->nextNode != NULL)
        {
            tmpHead = tmpHead->nextNode;
        }
        tmp->prevNode = tmpHead;
        tmpHead->nextNode = tmp;
        listTail = tmp;
    }
    countNodes++;
}
void List::addingNodes()
{
    int option = 0;
    while (option != 4)
    {
        cout << "\nAdding Nodes to List...\n";
        cout << "\n1 : Add Elements in beginning.\n";
        cout << "\n2 : Add Elements in N'\th Position.\n";
        cout << "\n3 : Add Elements in End.\n";
        cout << "\n4 : Exit or Abort Addition!\n";
        cout << "\nSelect Option : ";
        cin >> option;
        if (option == 4)
        {
            cout << "\nAborting addition!\n";
            return;
        }

        switch (option)
        {
        case 1:
        {
            addNode();
            break;
        }
        case 2:
        {
            int n = 0;
            if (listHead == NULL)
            {
                cout << "\nNo Previous Element to print, Element should be added at beginning ..\n";
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
        {
            addNodeEnd();
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
    if (countNodes == 0)
    {
        cout << "\nList is Empty ...\n";
        return;
    }
againPos:
    Node *tmpHead = getHead();
    int n = countNodes;
    printList();
    cout << "\nEnter Position to be Deleted...";
    cin >> n;
    if (n > 1 and n < countNodes)
    {
        for (int count = 1; count++ <= n - 1; tmpHead = tmpHead->nextNode)
            ;
        tmpHead->nextNode->prevNode = tmpHead->prevNode;
        tmpHead->prevNode->nextNode = tmpHead->nextNode;
        delete tmpHead;
        countNodes--;
        cout << "Deleted!\n";
    }
    else if (n == 1)
    {
        if (!tmpHead->nextNode)
        {
            listHead = NULL;
            delete tmpHead;
            countNodes--;
            cout << "Deleted!\n";
        }
        else
        {
            listHead = tmpHead->nextNode;
            listHead->prevNode = NULL;
            delete tmpHead;
            countNodes--;
            cout << "Deleted!\n";
        }
    }
    else if (n == countNodes)
    {
        Node *tmptail = listTail;
        if (!tmptail->prevNode)
        {
            listTail = NULL;
            delete tmptail;
            countNodes--;
            cout << "Deleted!\n";
        }
        else
        {
            listTail = listTail->prevNode;
            listTail->nextNode = NULL;
            delete tmptail;
            countNodes--;
            cout << "Deleted!\n";
        }
    }
    else
    {
        cout << "\nWrong position, Select Again...(y/n) : ";
        char cn = 'y';
        cin >> cn;
        if (cn == 'y' or cn == 'Y')
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
void List::updateData()
{
    Node *tmpHead = getHead();
    int n = countNodes;
    string str;
    printList();
    cout << "\nEnter Position to be Updated...";
    cin >> n;
    cout << "\nEnter New Value : ";
    cin >> str;
    for (int count = 1; count++ <= n - 1; tmpHead = tmpHead->nextNode)
        ;
    tmpHead->data = str;
}

void List::reverseList()
{
    Node *tmp = getHead();
    Node *tmpNext = tmp;
    Node *tmpSwap = tmp;
    while (tmpNext)
    {
        tmp = tmpNext;
        tmpNext = tmpNext->nextNode;

        tmpSwap = tmp->nextNode;
        tmp->nextNode = tmp->prevNode;
        tmp->prevNode = tmpSwap;
    }
    cout << "\nDone...\n";
}

Node *List::reverseList(Node *head)
{
    if (head->nextNode == NULL)
    {
        return head;
    }
    Node *currHead = reverseList(head->nextNode);
    Node *prevN = head->nextNode->nextNode;
    head->nextNode->nextNode = head;
    head->nextNode->prevNode = prevN;
    head->nextNode = NULL;
    return currHead;
}

/* void List::reverseList()
{
    Node *tmp = getHead();
    Node *tmpNext = tmp;
    Node *tmpSwap = tmp;
    while (tmpNext)
    {
        tmp = tmpNext;
        tmpNext = tmpNext->nextNode;

        tmpSwap = tmp->nextNode;
        tmp->nextNode = tmp->prevNode;
        tmp->prevNode = tmpSwap;
    }
    cout << "\nDone...\n";
}
 */
/* void List::reverseList()
{
    Node *tmpHead = getHead();
    Node *tmpPrev = NULL;
    Node *tmpNext = NULL;
    while (tmpHead)
    {
        tmpNext = tmpHead->nextNode;
        tmpHead->nextNode = tmpPrev;

        tmpPrev = tmpNext;
        tmpHead = tmpHead;
    }
} */

void List::printList()
{
    Node *tmp = getHead();
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
void List::printRev(Node *tmpNd)
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

int main()
{
    int option = -1;
    List lst;
    while (option != 7 and option != 0)
    {
        cout << "\n* LINKED LIST *\n";
        cout << "\nSelect Opration to perform on list!\n";
        cout << "\n1 : Add Element.\n";
        cout << "\n2 : Print List.\n";
        cout << "\n3 : Delete Element or Node.\n";
        cout << "\n4 : Update Element Value.\n";
        cout << "\n5 : Reverse List.\n";
        cout << "\n6 : Reverse Print.\n";
        cout << "\n7 : Exit Program!.\n";
        cout << "\nSELECT Option : ";
        cin >> option;

        switch (option)
        {
        case 1:
            lst.addingNodes();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 2:
            lst.printList();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 3:
            lst.deleteNode();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 4:
            lst.updateData();
            getchar();
            cout << "\nPress Enter to Continue...\n";
            getchar();
            break;
        case 5:
        {
            Node *&setNewHead = lst.setHead();
            setNewHead = lst.reverseList(setNewHead);
            getchar();
            cout << "\n(WORKING...)Press Enter to Continue...";
            getchar();
            break;
        }
        case 6:
            cout << "\nReverse List : { ";
            lst.printRev(lst.getHead());
            cout << " }\n";
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();

            break;

        case 7:
            cout << "\nExiting Program!!!\n";
            // deallocation.void
            deallocateNodes(lst.getHead());

            return 0;
            break;

        default:
            cout << "\n"
                 << option << "Wrong option selected !... Try again, \n ";
            break;
        }
    }
    deallocateNodes(lst.getHead());
    return 0;
}
