#include <iostream>
#include "linked_list.h"
// #include <bits/stdc++>

using namespace std;
using namespace nm_linkedList;

int main()
{
    int option = 0;
    List lst;
    while (option != 6)
    {
        cout << "\n* LINKED LIST *\n";
        cout << "\nSelect Opration to perform on list!\n";
        cout << "\n1 : Add Element.\n";
        cout << "\n2 : Print List.\n";
        cout << "\n3 : Delete Element or Node.\n";
        cout << "\n4 : Reverse List.\n";
        cout << "\n5 : Reverse Print.\n";
        cout << "\n6 : Exit Program!.\n";
        cout << "\nSELECT Option : ";
        cin >> option;

        switch (option)
        {
        case 1:
            lst.addingNodes();
            getchar();
            getchar();
            break;
        case 2:
            lst.printList();
            getchar();
            getchar();
            break;
        case 3:
            lst.deleteNode();
            getchar();
            getchar();
            break;
        case 4:
            lst.reverseList();
            getchar();
            getchar();
            break;
        case 5:
            cout << "\nRevrs.List : { ";
            lst.printListReverse(lst.getHead());
            cout << " }\n";
            getchar();
            getchar();

            break;

        case 6:
            cout << "\nExiting Program!!!\n";
            // deallocation...
            deallocateNodes(lst.getHead());

            return 0;
            break;

        default:
            cout << "\nWrong option selected!...Try again , \n";
            break;
        }
    }

    // deallocation...
    // deallocateNodes(lst.getHead());

    return 0;
}