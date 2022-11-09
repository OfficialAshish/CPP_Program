#include <iostream>
#include "queue_doubly_ended_circular.h"
using namespace std;
using namespace nm_de_c_queue;

int main()
{
    int option = -1;
    de_c_queue cArr(6);
    while (option != 8 and option != 0)
    {
        cout << "\n* Queue(Circular Array) *\n";
        cout << "\nSelect Opration to perform on Queue!\n";
        cout << "\n1 : Push Rear.\n";
        cout << "\n2 : Push Front.\n";
        cout << "\n3 : Delete Element Front.\n";
        cout << "\n4 : Delete Element Rear.\n";
        cout << "\n5 : Front element.\n";
        cout << "\n6 : Rear element(end).\n";
        cout << "\n7 : Print Queue.\n";
        cout << "\n8 : Exit Program!.\n";
        cout << "\nSELECT Option : ";
        cin >> option;
        int i = 0;

        switch (option)
        {
        case 1:
        {
            cout << "\nEnter Element : ";
            cin >> i;

            cArr.push_rear(i);
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        }
        case 2:
        {
            cout << "\nEnter Element : ";
            cin >> i;

            cArr.push_front(i);
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        }
        case 3:
            cout << cArr.pop_front();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 4:
            cout << cArr.pop_rear();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 5:
            cout << cArr.peek_front();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 6:
            cout << cArr.peek_rear();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        case 7:
            cArr.print(); // error
            cout << " size:" << cArr.size();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;

        case 8:
            cout << "\nExiting Program!!!\n";
            // de_c_queue();
            return 0;

        default:
            cout << "\n"
                 << option << "Wrong option selected !... Try again, \n ";
            break;
        }
    }

    return 0;
}