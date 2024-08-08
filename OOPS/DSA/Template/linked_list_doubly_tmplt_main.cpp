#include <iostream>
#include "linked_list_doubly_tmplt.h"
using namespace std;
using namespace nm_doubly_ll_tmplt;

int main()
{
    int option = -1;
    List<string> lst;
    // Node<int> nd(8);
    // cout << nd.getData();
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
            lst.reverseList();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
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
