#include <iostream>
#include "linked_list.h"

using namespace std;
using namespace nm_linkedList;

int main()
{
    List lst;
    Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9);

    lst.addNode(&n1);
    lst.addNode(&n2);
    lst.addNode(&n3);
    lst.addNode(&n4);
    lst.addNode(&n5);
    lst.addNode(&n6);
    lst.appendNode(&n8);
    lst.appendNode(&n9);
    // lst.addNode(&n7, 2);

    //WRONG WAY TO INTIZ
    // Node *n10;
    // cout << n10->nodePointer << endl;
    // cout << n10->info << endl;
    // cout << n10->nextNode << endl;

    Node *tmpPoint;
    tmpPoint = new Node(50);
    // tmpPoint->info = 3;
    // tmpPoint->nextNode = NULL;
    tmpPoint->nodePointer = tmpPoint;
    cout << tmpPoint->nodePointer << endl;
    cout << tmpPoint->getInfo() << endl;
    cout << tmpPoint->getNextNode() << endl;

    Node *p = allocNode(60);
    cout<<p->nodePointer<<endl;
    cout<<p->getInfo();

    lst.appendNode(p);
    lst.appendNode(tmpPoint);

    
    // cout << "\nRevrs.List : { ";
    // lst.printListReverse(lst.getHead());
    // cout << " }\n";

    cout << endl;
    lst.printList();

    // lst.reverseList();

    // cout << endl;
    // lst.printList();

    delete p;
    delete tmpPoint;
}