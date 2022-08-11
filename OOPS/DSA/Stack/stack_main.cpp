#include <iostream>
#include "stack_u.h"

using namespace std;
using namespace nm_stack;

int main()
{
    int option = -1;
    Stack lst;
    while (option != 5 and option != 0)
    {
        cout << "\n* Stack(linkedList) *\n";
        cout << "\nSelect Opration to perform on Stack!\n";
        cout << "\n1 : Insert.\n";
        cout << "\n2 : Delete Element (POP).\n";
        cout << "\n3 : Top most element. (TOP).\n";
        cout << "\n4 : Print Stack.\n";
        cout << "\n5 : Exit Program!.\n";
        cout << "\nSELECT Option : ";
        cin >> option;
        int i = 0;
        if (option == 1)
        {
            cout << "\nEnter Element : ";
            cin >> i;
        }

        switch (option)
        {
        case 1:
            lst.insert(i);
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 2:
            cout << "\nElement Poped. *";
            cout << lst.pop() ;
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 3:
            cout << lst.top();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 4:
            lst.printStack();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;

        case 5:
            cout << "\nExiting Program!!!\n";
            // deallocation...
            deallocateNodes(lst.getHead());

            return 0;
            break;

        default:
            cout << "\n"
                 << option << "Wrong option selected !... Try again, \n ";
            break;
        }
    }

    // deallocation...
    // deallocateNodes(lst.getHead());

    return 0;
}