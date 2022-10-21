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
        tNode(int dt = 0) : data(dt), leftNode(0), rightNode(0)
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
        binaryTree() : root(0) { cout << "\nTree Contr..\n"; }
        ~binaryTree() { cout << "\nTree Destr..\n"; }

        tNode *getRoot() { return root; }
        void insert(int);
        void insert(tNode **, int);
        // int minElem();
        // int maxElem();
        bool searchElem(int);
        void printLevel();           // breath first
        void printPreOrder(tNode *); // depth first
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
        else if (dt >= (*tmproot)->data)
        {
            insert(&(*tmproot)->rightNode, dt);
        }
        else
        {
            insert(&(*tmproot)->leftNode, dt);
        }
    }

    void binaryTree::insert(int dt = 0)
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
            while ((tmproot->leftNode != NULL) && (tmproot->rightNode != NULL))
            {
                if (dt <= tmproot->data)
                {
                    tmproot = tmproot->leftNode;
                }
                else
                {
                    tmproot = tmproot->rightNode;
                }
            }
            if (!tmproot->leftNode)
            {
                tmproot->leftNode = tmpNew;
            }
            else
            {
                tmproot->rightNode = tmpNew;
            }
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

    void binaryTree::printInOrder(tNode *tmp)
    {
        if (!tmp)
        {
            return;
        }
        printInOrder(tmp->leftNode);
        cout << tmp->data << " ";
        printInOrder(tmp->rightNode);
    }
    void binaryTree::printPreOrder(tNode *tmp)
    {
        if (!tmp)
        {
            return;
        }
        cout << tmp->data << " ";
        printInOrder(tmp->leftNode);
        printInOrder(tmp->rightNode);
    }
    void binaryTree::PrintPostOrder(tNode *tmp)
    {
        if (!tmp)
        {
            return;
        }
        printInOrder(tmp->leftNode);
        printInOrder(tmp->rightNode);
        cout << tmp->data << " ";
    }

    void binaryTree::printLevel()
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
