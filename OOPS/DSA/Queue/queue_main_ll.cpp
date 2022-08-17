#include <iostream>
#include "queue_ll.h"

using namespace std;
using namespace nm_queue;

int main()
{
    int option = -1;
    Queue Qlist;
    while (option != 5 and option != 0)
    {
        cout << "\n* Queue(linkedList) *\n";
        cout << "\nSelect Opration to perform on Queue!\n";
        cout << "\n1 : Insert. (EnQueue)\n";
        cout << "\n2 : Delete Element. (DeQueue).\n";
        cout << "\n3 : Front element.\n";
        cout << "\n4 : Print Queue.\n";
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
            Qlist.enQueue(i);
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 2:
            cout << "\nElement Poped. *";
            cout << Qlist.deQueue() ;
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 3:
            cout << Qlist.front();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 4:
            Qlist.printQueue();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;

        case 5:
            cout << "\nExiting Program!!!\n";
            // deallocation...
            deallocNodes(Qlist.getFront());
            return 0;
            break;

        default:
            cout << "\n"
                 << option << "Wrong option selected !... Try again, \n ";
            break;
        }
    }

    // deallocation...
    // deallocateNodes(Qlist.getHead());

    return 0;
}