#include <iostream>
#include "binary_tree.h"

// using namespace std;
using namespace nm_binary_tree;

int main()
{
    int option = -1;
    binaryTree bnTree;
    while (option != 11 and option != 0)
    {
        cout << "\n* Binary Tree(linkedList) *\n";
        cout << "\nSelect Opration to perform on Binary Tree!\n";
        cout << "\n1 : Insert Element. \n";
        // cout << "\n2 : Delete Element.\n";
        cout << "\n3 : Minimum Element in BST.\n";
        cout << "\n4 : Maximum Element in BST.\n";
        cout << "\n5 : Print Binary Tree.\n";
        cout << "\n6 : Search Element.\n";
        cout << "\n11 : Exit Program!.\n";
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
            // tNode *t_root = bnTree.getRoot();
            // bnTree.insert(&bnTree.root, i);
            bnTree.insert(i);
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
            cout << "Minimum Element is: " << bnTree.minElem();
            cout << "\nPress Enter to Continue...";
            getchar();
            getchar();
            break;
        }
        case 4:
        {
            cout << "Maximum Element is: " << bnTree.maxElem();
            cout << "\nPress Enter to Continue...";
            getchar();
            getchar();
            break;
        }

        case 5:
        {
            int opt = 1;
            cout << "\n1. Level \n2. PreOrder \n3. InOrder \n4. PostOrder\n";
            cout << "\nSelect Print Pattern :";
            cin >> opt;
            switch (opt)
            {
            case 1:
                bnTree.printLevel();
                break;
            case 2:
                bnTree.printPreOrder(bnTree.getRoot());
                break;
            case 3:
                bnTree.printInOrder(bnTree.getRoot());
                break;
            case 4:
                bnTree.PrintPostOrder(bnTree.getRoot());
                break;

            default:
                cout << "\nWrong option!!";
                break;
            }
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        }

        case 6:
        {
            int i;
            cout << "Enter Element to be searched :";
            cin >> i;
            if (bnTree.searchElem(i))
                cout << "Found";
            else
                cout << "Not Found";
            getchar();
            cout << "\nPress Enter to Continue...";
            getchar();
            break;
        }

        case 11:
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
    deallocNodes(bnTree.getRoot());

    return 0;
}