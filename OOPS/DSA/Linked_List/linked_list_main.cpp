#include <iostream>
#include "linked_list.h"
// #include <bits/stdc++>

using namespace std;
using namespace nm_linkedList;

int main()
{
    List lst;
    Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7),n8(8);

    lst.addNode(&n1);
    lst.addNode(&n2);
    lst.addNode(&n3);
    lst.addNode(&n4);
    lst.addNode(&n5);
    lst.addNode(&n6);
    lst.appendNode(&n7);
    lst.appendNode(&n8);

    lst.printList();
}