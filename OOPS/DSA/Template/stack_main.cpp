#include <iostream>
#include "stack_tmplt.h"

using namespace std;
using namespace nm_stack;

int main()
{
    int option = -1;
    Stack<string> lst;
    string value = "";
    // int value = 0;

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

        if (option == 1)
        {
            cout << "\nEnter Element : ";
            cin >> value;
        }

        switch (option)
        {
        case 1:
            lst.insert(value);
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 2:
            cout << "\nElement Poped. *";
            cout << lst.pop();
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