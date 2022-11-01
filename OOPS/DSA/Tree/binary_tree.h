#if !defined(_binary_tree_)
#define _binary_tree_
#include <queue>
#include <stack>
using namespace std;

namespace nm_binary_tree
{
    class tNode
    {
    private:
        int data;
        tNode *leftNode;
        tNode *rightNode;

    public:
        tNode(int dt = 0) : data(dt), leftNode(NULL), rightNode(NULL)
        { /* cout << "\nNode constr...\n";  */
        }
        ~tNode()
        { /* cout << "\nNode Destr..\n";  */
        }

        friend class binaryTree;
        friend tNode *allocNode(int);
        friend void deallocNodes(tNode *);
    };

    tNode *allocNode(int dt = 0)
    {
        tNode *tmp = new tNode(dt);
        if (!tmp)
        {
            cout << "\nUnable to allocate node. \n";
            exit(1);
        }
        return tmp;
    }

    void deallocNodes(tNode *tmproot)
    {
        queue<tNode *> Q;
        Q.push(tmproot);

        tNode *tmp = NULL;
        if (!tmproot)
        {
            cout << "\nTree is Empty.\n";
            return;
        }

        while (!Q.empty())
        {
            tmp = Q.front();
            if (tmp->leftNode)
            {
                Q.push(tmp->leftNode);
            }
            if (tmp->rightNode)
            {
                Q.push(tmp->rightNode);
            }
            Q.pop();
            delete tmp;
            cout << "*";
        }
    }

    class binaryTree
    {
    public: // for recursive(root is param..) insert ,
        tNode *root;

    public:
        binaryTree() : root(NULL) { cout << "\nTree Contr..\n"; }
        ~binaryTree() { cout << "\nTree Destr..\n"; }

        tNode *getRoot() { return root; }
        void insert(int);
        void insert(tNode **, int);
        int minElem();
        int maxElem();
        bool searchElem(int);
        void printLevel();           // breath first
        void printPreOrder(tNode *); // depth first (3 Types)
        void printInOrder(tNode *);
        void PrintPostOrder(tNode *);
        // void deleteElem(int val);
    };

    void binaryTree::insert(tNode **tmproot, int dt = 0)
    {
        if (*tmproot == NULL)
        {
            *tmproot = allocNode(dt);
        }
        else if (dt > (*tmproot)->data)
        {
            insert(&(*tmproot)->rightNode, dt);
        }
        else
        {
            insert(&(*tmproot)->leftNode, dt);
        }
    }

    void binaryTree::insert(int dt = 0) // some implementation error
    {
        tNode *tmproot = root;
        tNode *tmpNew = allocNode(dt);
        if (root == NULL)
        {
            root = tmpNew;
            // tmproot = root; //required when inserting multiple at once
        }
        else
        {
            while (1 /* (tmproot->leftNode != NULL) && (tmproot->rightNode != NULL) */)
            {
                if (dt <= tmproot->data)
                {
                    if (tmproot->leftNode == NULL)
                        break;
                    else
                        tmproot = tmproot->leftNode;
                }
                else if (dt > tmproot->data)
                {
                    if (tmproot->rightNode == NULL)
                        break;
                    else
                        tmproot = tmproot->rightNode;
                }
                else
                {
                    cout << "\nERROR! @insertion" << endl;
                    return;
                }
            }
            if (!tmproot->leftNode)
                tmproot->leftNode = tmpNew;
            else
                tmproot->rightNode = tmpNew;
        }
        cout << "DONE";
    }

    bool binaryTree::searchElem(int dt)
    {
        tNode *tmproot = root;
        while (tmproot)
        {
            if (dt == tmproot->data)
                return true;
            else if (dt < tmproot->data)
                tmproot = tmproot->leftNode;
            else
                tmproot = tmproot->rightNode;
        }
        return false;
    }

    int binaryTree::minElem()
    {
        tNode *tmp = root;
        while (tmp->leftNode)
            tmp = tmp->leftNode;
        return tmp->data;
    }
    int binaryTree::maxElem()
    {
        tNode *tmp = root;
        while (tmp->rightNode)
            tmp = tmp->rightNode;
        return tmp->data;
    }

    void binaryTree::printInOrder(tNode *tmp) // Left Data Right
    {
        if (!tmp)
        {
            return;
        }
        printInOrder(tmp->leftNode);
        cout << tmp->data << " ";
        printInOrder(tmp->rightNode);
    }
    void binaryTree::printPreOrder(tNode *tmp) // Data Left Right
    {
        if (!tmp)
        {
            return;
        }
        cout << tmp->data << " ";
        printInOrder(tmp->leftNode);
        printInOrder(tmp->rightNode);
    }
    void binaryTree::PrintPostOrder(tNode *tmp) // Right Left Data
    {
        if (!tmp)
        {
            return;
        }
        printInOrder(tmp->leftNode);
        printInOrder(tmp->rightNode);
        cout << tmp->data << " ";
    }

    void binaryTree::printLevel() // Breadth First
    {
        if (root == NULL)
        {
            cout << "\nTree is Empty..\n";
            return;
        }

        queue<tNode *> Q;
        Q.push(root);
        tNode *tmp;
        while (!Q.empty())
        {
            tmp = Q.front();
            cout << tmp->data << " ,";

            if (tmp->leftNode)
            {
                Q.push(tmp->leftNode);
            }
            if (tmp->rightNode)
            {
                Q.push(tmp->rightNode);
            }
            Q.pop();
        }
    }

} // namespace nm_binary_tree

#endif // _binary_tree_
