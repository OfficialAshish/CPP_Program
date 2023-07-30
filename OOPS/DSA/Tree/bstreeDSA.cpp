#include <iostream>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

class tNode
{
private:
    // public:
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

    friend void deallocNodes(tNode *tmproot);

    // build tree
    friend tNode *buildTree(tNode *root, int data);
    friend tNode *buildTreePreOrder(vector<int> const &preorder);
    friend tNode *solveBuildPre(vector<int> const &preorder, int &i, int &min_, int &max_);
    friend tNode *deleteNode(tNode *root, int data);
    // friend tNode *buildTreeLevelOrder(tNode *root);
    // friend tNode *buildTreeInPreSolveRec(int *inO, int *preO, int &preIndex, int inStartIndex, int inEndIndex, int n, map<int, int> nodeToIndex);
    // printing
    friend void levelTraversal(tNode *root);
    // friend void levelTraversalIndent(tNode *root);
    friend void inOrderIte(tNode *);
    friend void inOrder(tNode *);
    friend void preOrder(tNode *);
    friend void postOrder(tNode *);
    friend void predSuccessor(tNode *root, pair<int, int> &ans, int key);
    friend tNode *kthSmallest(tNode *root, int &i, int k);
    friend bool isBST(tNode *root, int &left, int &right);
    friend int minElem(tNode *root);
    friend int maxElem(tNode *root);
    friend void inOrderStore(tNode *root, vector<tNode *> &inOr);
    friend tNode *balanceBST(tNode *root);
    friend tNode *toBalance(int s, int e, vector<tNode *> const &inOr);
    // friend class info_l_bst;
    friend class info_l_bst largestSubBST(tNode *root, int &ans);
    // friend void parents(tNode *, map<tNode *, tNode *> &, tNode *&, int);
    // friend int burnTree(tNode *root, int start);

    // functions
    // friend int height(tNode *);

    // friend vector<int> verticalPrint(tNode *root);
    // friend void burnTree(tNode *root, stack<tNode *> &stackToTarget, int target, int &countTime);

    // lca = lowest common ancester
    friend int main();
};
class info_l_bst
{
public:
    int min;
    int max;
    bool isBST;
    int size;
};

info_l_bst largestSubBST(tNode *root, int &ans)
{
    if (root == nullptr)
        return {INT_MAX, INT_MIN, true, 0};

    info_l_bst left = largestSubBST(root->leftNode, ans);
    info_l_bst right = largestSubBST(root->rightNode, ans);

    info_l_bst current;

    current.size = left.size + right.size + 1;
    current.max = max(root->data, right.max);
    current.min = min(root->data, left.min);

    if (left.isBST && right.isBST && (root->data < right.min && root->data > left.max))
        current.isBST = true;
    else
        current.isBST = false;

    if (current.isBST)
        ans = max(ans, current.size);
    return current;
}

// if (4 < 21 == 1) is true
tNode *solveBuildPre(vector<int> const &preorder, int &i, int &min_, int &max_)
{
    if (i >= preorder.size())
        return nullptr;
    int value = preorder[i];
    if (max_ < value || value < min_)
        return nullptr;
    tNode *tmp = new tNode(preorder[i++]);
    tmp->leftNode = solveBuildPre(preorder, i, min_, value);
    tmp->rightNode = solveBuildPre(preorder, i, value, max_);
    return tmp;
}

tNode *buildTreePreOrder(vector<int> const &preorder)
{
    int min_ = INT_MIN, max_ = INT_MAX, i = 0;
    tNode *root = solveBuildPre(preorder, i, min_, max_);
    return root;
}

void inOrderStore(tNode *root, vector<tNode *> &inOr)
{
    if (root == nullptr)
        return;
    inOrderStore(root->leftNode, inOr);
    inOr.push_back(root);
    inOrderStore(root->rightNode, inOr);
}
tNode *toBalance(int s, int e, vector<tNode *> const &inOr)
{
    if (s > e)
        return nullptr;
    int mid = s + (e - s) / 2;
    tNode *tmp = inOr[mid];
    tmp->leftNode = toBalance(s, mid - 1, inOr);
    tmp->rightNode = toBalance(mid + 1, e, inOr);
    return tmp;
}
tNode *balanceBST(tNode *root)
{
    vector<tNode *> inOr;
    inOrderStore(root, inOr);
    return toBalance(0, inOr.size() - 1, inOr);
}
bool isBST(tNode *root, int &left, int &right)
{
    if (root == nullptr)
        return true;
    if (root->data < right and root->data > left)
    {
        bool lf = isBST(root->leftNode, left, root->data);
        bool rt = isBST(root->rightNode, root->data, right);
        return (lf and rt);
    }
    else
        return false;
}

tNode *kthSmallest(tNode *root, int &i, int k)
{
    if (root == nullptr)
        return root;
    tNode *left = kthSmallest(root->leftNode, i, k);

    if (left)
        return left;

    i++;
    if (i == k)
        return root;
    return kthSmallest(root->rightNode, i, k);
}

void predSuccessor(tNode *root, pair<int, int> &ans, int key)
{
    if (root == nullptr)
        return;
    if (root->data == key)
    {
        if (root->leftNode)
            ans.first = maxElem(root->leftNode);
        if (root->rightNode)
            ans.second = minElem(root->rightNode); // successor
    }
    else if (root->data > key)
    {
        ans.second = root->data; // successor
        predSuccessor(root->leftNode, ans, key);
    }
    else if (root->data < key)
    {
        ans.first = root->data;
        predSuccessor(root->rightNode, ans, key);
    }
}

tNode *buildTree(tNode *root, int data)
{
    if (root == nullptr)
    {
        tNode *tmp = new tNode(data);
        return tmp;
    }
    else if (root->data >= data)
    {
        root->leftNode = buildTree(root->leftNode, data);
    }
    else
        root->rightNode = buildTree(root->rightNode, data);

    return root;
}
void insertBST(tNode *&root)
{
    int a;
    cout << "\nEnter number :";
    cin >> a;
    while (a != -1)
    {
        root = buildTree(root, a);
        cout << "\nEnter number :";
        cin >> a;
    }
}

void levelTraversal(tNode *root)
{
    cout << "\nPrint levelOrder : " << endl;
    queue<tNode *> q;
    tNode *tmp = nullptr;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        if (tmp == nullptr)
        {
            cout << endl;
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            cout << " " << tmp->data;
            if (tmp->leftNode)
                q.push(tmp->leftNode);
            if (tmp->rightNode)
                q.push(tmp->rightNode);
        }
    }
}

void inOrderIte(tNode *root)
{
    stack<tNode *> st;
    st.push(root);
    tNode *tmp = root;

    while (!st.empty())
    {
        tmp = st.top();
        while (tmp->leftNode)
        {
            st.push(tmp->leftNode);
            tmp = tmp->leftNode;
        }
        tmp = st.top();
        cout << " " << tmp->data;
        st.pop();
        while (tmp->rightNode)
        {
            st.push(tmp->rightNode);
            tmp = tmp->rightNode;
        }
    }
}
void preOrder(tNode *root)
{
    if (root == nullptr)
        return;

    cout << " " << root->data;
    preOrder(root->leftNode);
    preOrder(root->rightNode);
}
void inOrder(tNode *root)
{
    if (root == nullptr)
        return;

    inOrder(root->leftNode);
    cout << " " << root->data;
    inOrder(root->rightNode);
}
void postOrder(tNode *root)
{
    if (root == nullptr)
        return;

    postOrder(root->leftNode);
    postOrder(root->rightNode);
    cout << " " << root->data;
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

int minElem(tNode *root)
{
    while (root->leftNode)
        root = root->leftNode;
    return root->data;
}
int maxElem(tNode *root)
{
    while (root->rightNode)
        root = root->rightNode;
    return root->data;
}

tNode *deleteNode(tNode *root, int data)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == data)
    {
        if (!root->leftNode and !root->rightNode)
        {
            delete root;
            return nullptr;
        }
        else if (root->leftNode and !root->rightNode)
        {
            tNode *t = root;
            root = root->leftNode;
            delete t;
            return root;
        }
        else if (!root->leftNode and root->rightNode)
        {
            tNode *t = root;
            root = root->rightNode;
            delete t;
            return root;
        }
        else if (root->leftNode and root->rightNode)
        {
            int maxinleft = maxElem(root->leftNode);
            root->data = maxinleft;
            root->leftNode = deleteNode(root->leftNode, maxinleft);
        }
        else
        {
            cout << "Error in deletion...";
            return nullptr;
        }
    }

    if (root->data < data)
    {
        root->rightNode = deleteNode(root->rightNode, data);
    }
    else if (root->data > data)
    {
        root->leftNode = deleteNode(root->leftNode, data);
    }
}

// 10 8 21 7 27 5 4 3 -1

int main()
{
    tNode *bnt = nullptr;
    // insertBST(bnt);
    vector<int> preorder = {20, 10, 5, 13, 15, 35, 30, 40};
    bnt = buildTreePreOrder(preorder);

    int right = INT_MAX;
    int left = INT_MIN;
    cout << "it\'s a vaild BST : " << isBST(bnt, left, right);

    int ans=0;
    info_l_bst largest_sz = largestSubBST(bnt, ans);
    cout << "\nLargest size is :" << ans;
    // cout << "\nLevel Order creation tree : \n";
    // bnt = buildTreeLevelOrder(bnt);

    // built tree from inorder and preorder array
    // Output: 3 4 1 5 2 ø

    // building tree from inorder and preorder arr
    // int inO[] = {3, 1, 4, 0, 5, 2};
    // int preO[] = {0, 1, 3, 4, 2, 5};
    // int inO[] = {4, 8, 2, 5, 1, 6, 3, 7};
    // int preO[] = {1, 2, 4, 8, 5, 3, 6, 7};
    // int preIndex = 0,n = sizeof(inO) / sizeof(inO[0]); // no of nodes;
    // map<int, int> nodeToIndex;
    // createMapIndex(inO, n, nodeToIndex);
    // bnt = buildTreeInPreSolveRec(inO, preO, preIndex, 0, n - 1, n, nodeToIndex);

    // buliding tree from inorder and postorder
    // int inO[] = {4, 8, 2, 5, 1, 6, 3, 7};
    // int postO[] = {8, 4, 5, 2, 6, 7, 3, 1};
    // int n = sizeof(inO) / sizeof(inO[0]); // no of nodes;
    // int postIndex = n - 1;
    // map<int, int> nodeToIndex;
    // createMapIndex(inO, n, nodeToIndex);
    // bnt = buildTreeInPostSolveRec(inO, postO, postIndex, 0, n - 1, n, nodeToIndex);

    // int ar[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    // int sz = sizeof(ar) / sizeof(ar[0]);
    // bnt = buildTreeAr(bnt, ar, sz); // Error in this

    // vector<vector<int>> lv = levelOrderReverse(bnt);
    // for (auto &&i : lv)
    //     for (auto &&j : i)
    //         cout << j << ',';

    levelTraversal(bnt);

    // int del = 5;
    // deleteNode(bnt, del);
    // cout << "Deleted";

    // levelTraversal(bnt);

    pair<int, int> prs;
    predSuccessor(bnt, prs, 5);
    int d = 8;
    cout << "Predecessor and successor are (for " << d << "):" << prs.first << "and" << prs.second << endl;

    /*
    int count = 0;
    int k = 5;
    vector<int> path;
    sumOfKPath(bnt, path, count, k);
    printf("\n Count of path that sum to k=%d : %d \n", k, count);

    int kth = 1;
    vector<tNode *> path2node;
    lcaKth(bnt, bnt->leftNode->leftNode->rightNode->data, kth, path2node);
    cout << "\n Kth LCA for " << bnt->leftNode->leftNode->rightNode->data << "  : " << path2node[path2node.size() - 1]->data << endl;
    // tNode *n2 = lcaKth(bnt, bnt->leftNode->leftNode->rightNode->data, kth);
    // cout << "\n Kth LCA for " << bnt->leftNode->leftNode->rightNode->data << "  : " << n2->data << endl;
    // cout << "\nk: " << kth;
    tNode *n3 = lca(bnt, bnt->leftNode->leftNode->leftNode->data, bnt->leftNode->rightNode->data);
    cout << "\n LCA for " << bnt->leftNode->leftNode->leftNode->data << " & " << bnt->leftNode->rightNode->data << "  : " << n3->data << endl;

    pair<int, int> sumAns = sumMaxLength(bnt);
    cout << "\nSum of maximum length : " << sumAns.first << " & Len : " << sumAns.second << endl;

    vector<int> ansleft;
    leftView(bnt, 0, ansleft);
    cout << "\n Left view : ";
    for (auto &&i : ansleft)
        cout << i << ", ";

    cout << "\n Top view Print : ";
    vector<int> topv = topView(bnt);
    for (auto i : topv)
    {
        cout << i << ", ";
    }
    cout << "\n Vertical Print : ";
    vector<int> vrtP = verticalPrint(bnt);
    for (auto i : vrtP)
    {
        cout << i << ", ";
    }

    cout << "\n Boundary Print : ";
    boundaryPrint(bnt);
    cout << "\n Zigzag level order : ";
    zigzagLevelOrder(bnt);

    cout << "\n Is SumTree : " << isSumTree(bnt).first << endl;
    cout << "\n Is balanced tree : " << isBalance(bnt) << endl;
    cout << "\n Is balancedFast tree : " << isBalanceFast(bnt).first << endl;
    cout << "\nDiameter is : " << diameter(bnt) << endl;
    cout << "\n DiameterFast is : " << diameterFast(bnt).first << endl;

    */

    // cout << "\nHeight is : " << height(bnt);

    int i = 0, k = 5;
    tNode *kthS = kthSmallest(bnt, i, k);
    cout << k << "th Smallest element is :" << kthS->data;

    cout << "\nPrinting inorder : \n";
    inOrder(bnt);
    // cout << "\nPrinting inorder : \n";
    // inOrderIte(bnt);
    cout << "\nPrinting pre order : \n";
    preOrder(bnt);
    cout << "\nPrinting post order : \n";
    postOrder(bnt);
    cout << "\n\ndeleting nodes--";
    deallocNodes(bnt);
}
