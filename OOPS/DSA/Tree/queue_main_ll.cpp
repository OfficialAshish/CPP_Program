#include <iostream>
#include "binary_tree.h"

// using namespace std;
using namespace nm_binary_tree;

int main()
{
    int option = -1;
    binaryTree bnTree;
    while (option != 4 and option != 0)
    {
        cout << "\n* Binary Tree(linkedList) *\n";
        cout << "\nSelect Opration to perform on Binary Tree!\n";
        cout << "\n1 : Insert Element. \n";
        // cout << "\n2 : Delete Element.\n";
        cout << "\n3 : Print Binary Tree.\n";
        cout << "\n4 : Exit Program!.\n";
        cout << "\nSELECT Option : ";
        cin >> option;
        int i = 0;

        switch (option)
        {
        case 1:
        {
            /*referece to variable is only possible ,cant update or send private root
            through any way as ref or pointer
            soln : insert non-recursively,or make root public*/
            cout << "\nEnter Element : ";
            cin >> i;
            tNode *t_root = bnTree.getRoot();
            bnTree.insert(&bnTree.root, i);
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        }
            /* case 2:
                cout << "\nElement Poped. *";
                cout << bnTree.deleteElem() ;
                getchar();
                cout << "\nPress Enter to Continue...";
                getchar();
                break; */

        case 3:
        {
            bnTree.printLevel();
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        }

        case 4:
        {
            cout << "\nExiting Program!!!\n";
            // deallocation...
            deallocNodes(bnTree.getRoot());
            return 0;
            break;
        }

        default:
        {
            cout << "\n"
                 << option << "Wrong option selected !... Try again, \n ";
            break;
        }
        }
    }

    return 0;
}