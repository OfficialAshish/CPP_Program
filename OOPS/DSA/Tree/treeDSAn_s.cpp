#include <iostream>

#include <bits/stdc++.h>

using namespace std;

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

    friend void deallocNodes(tNode *tmproot);

    // build tree
    friend tNode *buildTree(tNode *root);
    friend tNode *buildTreeLevelOrder(tNode *root);
    friend tNode *buildTreeInPreSolveRec(int *inO, int *preO, int &preIndex, int inStartIndex, int inEndIndex, int n, map<int, int> nodeToIndex);
    // printing
    friend void levelTraversal(tNode *root);
    friend void levelTraversalIndent(tNode *root);
    friend void inOrder(tNode *);
    friend void preOrder(tNode *);
    friend void postOrder(tNode *);
    friend void parents(tNode *, map<tNode *, tNode *> &, tNode *&, int);
    friend int burnTree(tNode *root, int start);

    // functions
    friend int height(tNode *);

    friend vector<int> verticalPrint(tNode *root);
    friend void burnTree(tNode *root, stack<tNode *> &stackToTarget, int target, int &countTime);

    // lca = lowest common ancester
    friend int main();
};

vector<int> verticalPrint(tNode *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    map<int, map<int, vector<int>>> nodes;
    queue<pair<tNode *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<tNode *, pair<int, int>> temp;
        temp = q.front();
        q.pop();
        tNode *tm = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        nodes[hd][lvl].push_back(tm->data);

        if (tm->leftNode)
        {
            q.push(make_pair(tm->leftNode, make_pair(hd - 1, lvl + 1)));
        }
        if (tm->rightNode)
            q.push(make_pair(tm->rightNode, make_pair(hd + 1, lvl + 1)));
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int height(tNode *root)
{
    if (root == nullptr)
        return 0;
    return max(height(root->leftNode), height(root->rightNode)) + 1;
}

tNode *buildTree(tNode *root)
{
    int val;
    cout << "\nEnter digit : ";
    cin >> val;
    if (val == -1)
        return nullptr;

    root = new tNode(val);

    cout << "\nEnter data for left node of " << val << " : ";
    root->leftNode = buildTree(root->leftNode);

    cout << "\nEnter data for right node of " << val << " : ";
    root->rightNode = buildTree(root->rightNode);

    return root;
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

int digitCount(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

void levelTraversalIndent(tNode *root)
{
    vector<int> verticalOrder = verticalPrint(root);
    int printed = 0;
    cout << "\nPrint levelOrder with indentation : " << endl;
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
            printed = 0;
        }
        else
        {
            int rootIndentation = std::distance(verticalOrder.begin(), std::find(verticalOrder.begin(), verticalOrder.end(), tmp->data)) -
                                  printed;
            for (int j = rootIndentation; j > 0; j--)
                cout << " ";
            int dc = digitCount(tmp->data);
            printed += rootIndentation + dc;

            cout << tmp->data;
            if (tmp->leftNode)
                q.push(tmp->leftNode);
            if (tmp->rightNode)
                q.push(tmp->rightNode);
        }
    }
}

void inOrder(tNode *root)
{
    if (root == nullptr)
        return;

    inOrder(root->leftNode);
    cout << " " << root->data;
    inOrder(root->rightNode);
}

void preOrder(tNode *root)
{
    if (root == nullptr)
        return;

    cout << " " << root->data;
    inOrder(root->leftNode);
    inOrder(root->rightNode);
}
void postOrder(tNode *root)
{
    if (root == nullptr)
        return;

    inOrder(root->leftNode);
    inOrder(root->rightNode);
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
tNode *buildTreeInPreSolveRec(int *inO, int *preO, int &preIndex, int inStartIndex, int inEndIndex, int n, map<int, int> nodeToIndex)
{
    if (inEndIndex < inStartIndex or preIndex >= n)
        return nullptr;

    int preElem = preO[preIndex++];
    tNode *root = new tNode(preElem);
    int pos = nodeToIndex[preElem]; // position of pre inside in-order arr,map

    // recursive calls
    root->leftNode = buildTreeInPreSolveRec(inO, preO, preIndex, inStartIndex, pos - 1, n, nodeToIndex);
    root->rightNode = buildTreeInPreSolveRec(inO, preO, preIndex, pos + 1, inEndIndex, n, nodeToIndex);

    return root;
}

tNode *buildTreeLevelOrder(tNode *root)
{
    queue<tNode *> q;
    int val;
    cout << "\nEnter root digit : ";
    cin >> val;
    if (val == -1)
        return nullptr;

    root = new tNode(val);
    q.push(root);

    while (!q.empty())
    {
        tNode *tmp = q.front();
        q.pop();
        cout << "\nEnter data for left node of " << tmp->data << " : ";
        cin >> val;
        if (val != -1)
        {
            tmp->leftNode = new tNode(val);
            q.push(tmp->leftNode);
        }

        cout << "\nEnter data for right node of " << tmp->data << " : ";
        cin >> val;
        if (val != -1)
        {
            tmp->rightNode = new tNode(val);
            q.push(tmp->rightNode);
        }
    }
    return root;
}

/* void burnTree(tNode *root, stack<tNode *> &stackToTarget, int target, int &countTime)
{
    if (root == nullptr)
        return;
    if (root->data == target)
    {
        countTime = 1;
        root->data = 0;
    }

    if (countTime < 0)
    {
        stackToTarget.push(root);
        burnTree(root->leftNode, stackToTarget, target, countTime);
        burnTree(root->rightNode, stackToTarget, target, countTime);
        stackToTarget.pop();
    }
    else // burning , countTime init to zero
    {
        root->data = 0;
        countTime++;
        tNode *pathBack = nullptr;
        if (stackToTarget.empty() == false)
            pathBack = stackToTarget.top();
        stackToTarget.pop();
        burnTree(root->leftNode, stackToTarget, target, countTime);
        burnTree(root->rightNode, stackToTarget, target, countTime);
        burnTree(pathBack, stackToTarget, target, countTime);
    }
    return;
} */

void parents(tNode *root, map<tNode *, tNode *> &mapp, tNode *&targetNode, int target)
{
    if (root == nullptr)
        return;
    if (root->data == target)
    {
        targetNode = root;
    }

    if (root->leftNode)
    {
        mapp[root->leftNode] = root;
    }
    if (root->rightNode)
    {
        mapp[root->rightNode] = root;
    }
    parents(root->leftNode, mapp, targetNode, target);
    parents(root->rightNode, mapp, targetNode, target);
}

int burnTree(tNode *root, int start)
{
    if (root == nullptr)
        return -1; 

    queue<tNode *> burn;
    map<tNode *, bool> visitedN;
    map<tNode *, tNode *> nodeToParent;
    tNode *trgN = nullptr;

    parents(root, nodeToParent, trgN, start);

    if (trgN == nullptr)
        return -1; 

    int size = 0, ans = 0;
    burn.push(trgN);
    visitedN[trgN] = true;

    while (!burn.empty())
    {
        int flag = 0;
        size = burn.size();

        for (int i = 0; i < size; i++)
        {
            tNode *front = burn.front();
            burn.pop();

            if (front->leftNode && !visitedN[front->leftNode])
            {
                flag = 1;
                burn.push(front->leftNode);
                visitedN[front->leftNode] = true;
            }
            if (front->rightNode && !visitedN[front->rightNode])
            {
                flag = 1;
                burn.push(front->rightNode);
                visitedN[front->rightNode] = true;
            }
            if (nodeToParent[front] && !visitedN[nodeToParent[front]])
            {
                flag = 1;
                burn.push(nodeToParent[front]);
                visitedN[nodeToParent[front]] = true;
            }
        }
        if (flag == 1)
            ans++;
    }
    return ans;
}

int createMapIndex(int *arr, int n, map<int, int> &nodetoindex)
{
    for (int i = 0; i < n; i++)
        nodetoindex[arr[i]] = i;
}

/*
// built tree
1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
20 6 2 -1 -1 4 -1 -1 4 4 -1 -1 -1
1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 8 5 4 -1 -1 -1 -1
1 3 7 -1 -1 -1 5 11 -1 -1 17 -1 -1
// levelorder build
24 10 4 6 4 -1 -1 -1 -1 -1 -1
24 10 4 6 4 -1 -1 3 3 -1 -1 -1 -1 -1 -1
24 10 4 6 4 3 1 4 2 2 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
88 14 30 4 6 14 16 1 3 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
 */

int main()
{
    tNode *bnt = nullptr;
    // bnt = buildTree(bnt);
    // cout << "\nLevel Order creation tree : \n";
    // bnt = buildTreeLevelOrder(bnt);
    // building tree from inorder and preorder arr
    int inO[] = {3, 1, 4, 0, 5, 2};
    int preO[] = {0, 1, 3, 4, 2, 5};
    // int inO[] = {4, 8, 2, 5, 1, 6, 3, 7};
    // int preO[] = {1, 2, 4, 8, 5, 3, 6, 7};
    int preIndex = 0, n = sizeof(inO) / sizeof(inO[0]); // no of nodes;
    map<int, int> nodeToIndex;
    createMapIndex(inO, n, nodeToIndex);
    bnt = buildTreeInPreSolveRec(inO, preO, preIndex, 0, n - 1, n, nodeToIndex);

    levelTraversalIndent(bnt);

    cout << endl;
    int countTime = -1, target = 3;
    stack<tNode *> stackTarget;
    // burnTree(bnt, stackTarget, target, countTime);
    countTime = burnTree(bnt, target);
    if (countTime == -1)
        cout << "\nTarget not found!! not burned\n";
    else
        cout<<"\nTime to burn tree is : "<<countTime <<endl;

    // cout << "\n Vertical Print : ";
    // vector<int> vrtP = verticalPrint(bnt);
    // for (auto i : vrtP)
    // {
    //     cout << i << ", ";
    // }
    cout << "\nHeight is : " << height(bnt);

    cout << "\nPrinting inorder : \n";
    inOrder(bnt);
    cout << "\nPrinting pre order : \n";
    preOrder(bnt);
    cout << "\nPrinting post order : \n";
    postOrder(bnt);
    cout << "\n\ndeleting nodes--";
    deallocNodes(bnt);
}
