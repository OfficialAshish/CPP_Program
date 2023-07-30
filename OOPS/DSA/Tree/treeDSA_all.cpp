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
    friend tNode *buildTreeAr(tNode *root, int *ar, int &sz);
    friend tNode *buildTreeInPreSolveRec(int *inO, int *preO, int &preIndex, int inStartIndex, int inEndIndex, int n, map<int, int> nodeToIndex);
    friend tNode *buildTreeInPostSolveRec(int *inO, int *postO, int &postIndex, int inStartIndex, int inEndIndex, int n, map<int, int> nodeToIndex);
    // printing
    friend void levelTraversal(tNode *root);
    friend void levelTraversalIndent(tNode *root);
    friend void inOrder(tNode *);
    friend void preOrder(tNode *);
    friend void postOrder(tNode *);
    friend void zigzagLevelOrder(tNode *root);
    friend void boundaryPrint(tNode *root);

    friend void inOrderIte(tNode *);

    // functions
    friend int height(tNode *);

    friend int diameter(tNode *root);
    friend pair<int, int> diameterFast(tNode *root);

    friend bool isBalance(tNode *root);
    friend pair<bool, int> isBalanceFast(tNode *root);

    friend pair<bool, int> isSumTree(tNode *root);

    friend void traverseLeaf(vector<int> &collectLeaf, tNode *root);
    friend void traverseLeft(vector<int> &collectLeft, tNode *root);
    friend void traverseRight(vector<int> &collectRight, tNode *root);
    friend vector<vector<int>> levelOrderReverse(tNode *root);

    friend vector<int> verticalPrint(tNode *root);
    friend vector<int> topView(tNode *root);
    friend vector<int> bottomView(tNode *root);
    friend void leftView(tNode *root, int lvl, vector<int> &vec);
    friend pair<int, int> sumMaxLength(tNode *root);

    // lca = lowest common ancester
    friend tNode *lca(tNode *root, int n1, int n2);
    friend tNode *lcaKth(tNode *root, int n1, int &k);
    friend void lcaKth(tNode *root, int n1, int k, vector<tNode *> &path); // overload (with vector appr)
    friend void sumOfKPath(tNode *root, vector<int> &, int &count, int k);
    friend pair<int, int> getMaxSumNonAdj(tNode *root);

    friend void parents(tNode *, map<tNode *, tNode *> &, tNode *&, int);
    friend int burnTree(tNode *root, int start);

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

vector<vector<int>> levelOrderReverse(tNode *root)
{
    vector<vector<int>> ans;
    vector<int> tm;
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
            ans.push_back(tm);
            tm.clear();
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            tm.push_back(tmp->data);
            if (tmp->leftNode)
                q.push(tmp->leftNode);
            if (tmp->rightNode)
                q.push(tmp->rightNode);
        }
    }
    reverse(begin(ans), end(ans));
    return ans;
}

int height(tNode *root)
{
    if (root == nullptr)
        return 0;
    return max(height(root->leftNode), height(root->rightNode)) + 1;
}

int diameter(tNode *root)
{
    if (root == nullptr)
        return 0;

    int op1, op2, op3;
    // will reach to each node by this 2 call
    op1 = diameter(root->leftNode);
    op2 = diameter(root->rightNode);
    // n2 comlx, diametric height for each node
    op3 = height(root->leftNode) + height(root->rightNode) + 1;
    int ans = max(op1, max(op2, op3));
    return ans;
}

pair<int, int> diameterFast(tNode *root)
{
    if (root == nullptr)
        return make_pair(0, 0);

    pair<int, int> left, right, ans;
    left = diameterFast(root->leftNode);
    right = diameterFast(root->rightNode);

    int op1 = 0, op2 = 0, op3;

    op1 = left.first;
    op2 = right.first;
    op3 = left.second + right.second + 1; // height

    ans.first = max(op1, max(op2, op3)); // diameter

    ans.second = max(left.second, right.second) + 1; // height

    return ans;
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

void inOrder(tNode *root)
{
    if (root == nullptr)
        return;

    inOrder(root->leftNode);
    cout << " " << root->data;
    inOrder(root->rightNode);
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

/*
tNode *buildTreeAr(tNode *root, int *ar, int &sz)
{
    int val;
    // cout << "\nEnter digit : ";
    // cin >> val;.
    val = ar[0];
    if (val == -1)
        return nullptr;

    root = new tNode(val);
    // if (sz > 1)
    // {
    sz--;
    cout << "\nEnter data for left node of " << val << " : ";
    root->leftNode = buildTreeAr(root->leftNode, ar + 1, sz);

    cout << "\nEnter data for right node of " << val << " : ";
    root->rightNode = buildTreeAr(root->rightNode, ar + 2, sz);
    // }
    // else
    //     return nullptr;

    return root;
}
 */

int createMapIndex(int *arr, int n, map<int, int> &nodetoindex)
{
    for (int i = 0; i < n; i++)
        nodetoindex[arr[i]] = i;
}

tNode *buildTreeInPostSolveRec(int *inO, int *postO, int &postIndex, int inStartIndex, int inEndIndex, int n, map<int, int> nodeToIndex)
{
    if (inEndIndex < inStartIndex or postIndex < 0)
        return nullptr;

    int postElem = postO[postIndex--];
    tNode *root = new tNode(postElem);
    int pos = nodeToIndex[postElem]; // position of post inside in-order arr-map

    // recursive calls
    root->rightNode = buildTreeInPostSolveRec(inO, postO, postIndex, pos + 1, inEndIndex, n, nodeToIndex);
    root->leftNode = buildTreeInPostSolveRec(inO, postO, postIndex, inStartIndex, pos - 1, n, nodeToIndex);

    return root;
}

tNode *buildTreeInPreSolveRec(int *inO, int *preO, int &preIndex, int inStartIndex, int inEndIndex, int n, map<int, int> nodeToIndex)
{
    if (inEndIndex < inStartIndex or preIndex >= n)
        return nullptr;

    int preElem = preO[preIndex++];
    tNode *root = new tNode(preElem);
    int pos = nodeToIndex[preElem]; // position of pre inside in order arr-map

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

bool isBalance(tNode *root)
{
    if (root == nullptr)
        return true;
    bool left, right, diff;
    left = isBalance(root->leftNode);
    right = isBalance(root->rightNode);
    diff = abs(height(root->leftNode) - height(root->rightNode)) <= 1;
    if (left and right and diff)
        return true;
    else
        return false;
}

pair<bool, int> isBalanceFast(tNode *root)
{
    if (root == nullptr)
        return make_pair(true, 0);

    pair<bool, int> left, right;
    left = isBalanceFast(root->leftNode);
    right = isBalanceFast(root->rightNode);
    bool cond3 = abs(left.second - right.second) <= 1;

    int hgt = max(left.second, right.second) + 1;
    if (left.first and right.first and cond3)
        return make_pair(true, hgt);
    else
        return make_pair(false, hgt);
}

pair<bool, int> isSumTree(tNode *root)
{
    if (root == nullptr)
        return make_pair(true, 0);
    if (root->leftNode == nullptr and root->rightNode == nullptr)
        return make_pair(true, root->data);

    pair<bool, int> left, right, ans;
    left = isSumTree(root->leftNode);
    right = isSumTree(root->rightNode);

    ans.first = left.first and right.first and ((left.second + right.second) == root->data);
    ans.second = left.second + right.second + root->data;
    return ans;
}

void zigzagLevelOrder(tNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<tNode *> iter, tmp;
    tmp.push(root);
    bool rtol = false;

    while (!tmp.empty())
    {
        iter.swap(tmp);
        while (!iter.empty())
        {
            tNode *tempN = iter.top();
            iter.pop();

            cout << tempN->data << ", ";

            if (rtol)
            {
                if (tempN->rightNode)
                    tmp.push(tempN->rightNode);
                if (tempN->leftNode)
                    tmp.push(tempN->leftNode);
            }
            else
            {
                if (tempN->leftNode)
                    tmp.push(tempN->leftNode);
                if (tempN->rightNode)
                    tmp.push(tempN->rightNode);
            }
        }
        // change direction
        rtol = !rtol;
    }
}

void traverseLeft(vector<int> &collectLeft, tNode *root)
{
    if (root == nullptr or root->leftNode == nullptr and root->rightNode == nullptr)
    {
        return;
    }

    collectLeft.push_back(root->data);
    if (root->leftNode)
        traverseLeft(collectLeft, root->leftNode);
    else
        traverseLeft(collectLeft, root->rightNode);
}
void traverseLeaf(vector<int> &collectLeaf, tNode *root)
{
    if (root->leftNode == nullptr and root->rightNode == nullptr)
    {
        collectLeaf.push_back(root->data);
        return;
    }
    traverseLeaf(collectLeaf, root->leftNode);
    traverseLeaf(collectLeaf, root->rightNode);
}
void traverseRight(vector<int> &collectRight, tNode *root)
{
    if (root == nullptr or root->leftNode == nullptr and root->rightNode == nullptr)
        return;

    if (root->rightNode)
        traverseRight(collectRight, root->rightNode);

    else
        traverseRight(collectRight, root->leftNode);
    collectRight.push_back(root->data);
}

void boundaryPrint(tNode *root)
{
    vector<int> result;

    traverseLeft(result, root);
    // result.pop_back();
    traverseLeaf(result, root);
    traverseRight(result, root);

    for (auto &&i : result)
    {
        cout << " " << i;
    }
}

vector<int> topView(tNode *root)
{
    vector<int> ans;
    map<int, int> m;
    queue<pair<tNode *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<tNode *, int> tmpf = q.front();
        q.pop();
        tNode *firstnode = tmpf.first;
        int hd = tmpf.second;
        if (m.count(hd) == 0)
            m[hd] = firstnode->data;
        if (firstnode->leftNode)
            q.push(make_pair(firstnode->leftNode, hd - 1));
        if (firstnode->rightNode)
            q.push(make_pair(firstnode->rightNode, hd + 1));
    }
    for (auto i : m)
    {
        ans.push_back(i.second);
    }

    return ans;
}
vector<int> bottomView(tNode *root)
{
    vector<int> ans;
    map<int, int> m;
    queue<pair<tNode *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<tNode *, int> tmpf = q.front();
        q.pop();
        tNode *firstnode = tmpf.first;
        int hd = tmpf.second;

        m[hd] = firstnode->data; // update new value

        if (firstnode->leftNode)
            q.push(make_pair(firstnode->leftNode, hd - 1));
        if (firstnode->rightNode)
            q.push(make_pair(firstnode->rightNode, hd + 1));
    }
    for (auto i : m)
    {
        ans.push_back(i.second);
    }

    return ans;
}
void leftView(tNode *root, int lvl, vector<int> &vec)
{
    if (root == nullptr)
    {
        return;
    }
    if (lvl == vec.size())
    {
        vec.push_back(root->data);
        // vec[lvl] = root->data;
    }
    leftView(root->rightNode, lvl + 1, vec);
    leftView(root->leftNode, lvl + 1, vec);
}

// max sum of maximum height
pair<int, int> sumMaxLength(tNode *root)
{
    if (root == nullptr)
        return make_pair(0, 0);
    if (root->leftNode == nullptr and root->rightNode == nullptr)
        return make_pair(root->data, 1);

    pair<int, int> left = sumMaxLength(root->leftNode);
    pair<int, int> right = sumMaxLength(root->rightNode);

    if (left.second > right.second)
    {
        return make_pair(left.first + root->data, left.second + 1);
    }
    else if (left.second == right.second)
    {
        return make_pair(max(left.first, right.first) + root->data, left.second + 1);
    }
    else // if (left.second < right.second)
    {
        return make_pair(right.first + root->data, right.second + 1);
    }
}

// lowest common ancester
tNode *lca(tNode *root, int n1, int n2)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == n1 or root->data == n2)
        return root;

    tNode *left = lca(root->leftNode, n1, n2);
    tNode *right = lca(root->rightNode, n1, n2);

    if (left and right)
        return root;
    else if (left and right == nullptr)
        return left;
    else if (right and left == nullptr)
        return right;
    else
        return nullptr;
}

tNode *lcaKth(tNode *root, int n1, int &k)
{
    if (root == nullptr)
        return nullptr;

    tNode *left = lcaKth(root->leftNode, n1, k);
    tNode *right = lcaKth(root->rightNode, n1, k);

    if (k == 0 and (left or right))
    {
        k--; // needed
        return root;
    }

    if (left and right == nullptr)
    {
        k--;
        return left;
    }
    else if (right and left == nullptr)
    {
        k--;
        return right;
    }
    else if (root->data == n1)
    {
        k--;
        return root;
    }
    else
        return nullptr;
}

//  kth ancester of n1
void lcaKth(tNode *root, int n1, int k, vector<tNode *> &path)
{
    if (root == nullptr)
        return;

    lcaKth(root->leftNode, n1, k, path);
    lcaKth(root->rightNode, n1, k, path);

    if (path.size() > k)
    {
        return;
    }
    if (root->data == n1)
    {
        path.push_back(root);
    }
    else if (path.size() > 0)
    {
        path.push_back(root);
    }
}

// count of paths that sums to k
void sumOfKPath(tNode *root, vector<int> &path, int &count, int k)
{
    if (root == nullptr)
        return;

    path.push_back(root->data);

    sumOfKPath(root->leftNode, path, count, k);
    sumOfKPath(root->rightNode, path, count, k);

    int sz = path.size() - 1, sum = 0;
    for (int i = sz; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
    path.pop_back();
    // return;
}

pair<int, int> getMaxSumNonAdj(tNode *root)
{
    if (root == nullptr)
        return make_pair(0, 0);

    pair<int, int> left = getMaxSumNonAdj(root->leftNode);
    pair<int, int> right = getMaxSumNonAdj(root->rightNode);

    pair<int, int> ans;
    ans.first = root->data + left.second + right.second;
    ans.second = left.first + right.first;

    return ans;
}
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
    int inO[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int postO[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(inO) / sizeof(inO[0]); // no of nodes;
    int postIndex = n - 1;
    map<int, int> nodeToIndex;
    createMapIndex(inO, n, nodeToIndex);
    bnt = buildTreeInPostSolveRec(inO, postO, postIndex, 0, n - 1, n, nodeToIndex);

    // int ar[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    // int sz = sizeof(ar) / sizeof(ar[0]);
    // bnt = buildTreeAr(bnt, ar, sz); // Error in this

    // vector<vector<int>> lv = levelOrderReverse(bnt);
    // for (auto &&i : lv)
    //     for (auto &&j : i)
    //         cout << j << ',';

    levelTraversal(bnt);

    pair<int, int> ansPS = getMaxSumNonAdj(bnt);
    printf("\nSum of all level nodes (Including root) : %d,\n( excluding root ): %d\n", ansPS.first, ansPS.second);

    cout << endl;

    int countTime = -1, target = 3;
    countTime = burnTree(bnt, target);
    if (countTime == -1)
        cout << "\nTarget not found!! not burned\n";
    else
        cout << "\nTime to burn tree is : " << countTime << endl;

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
    levelTraversalIndent(bnt);

    cout << "\nHeight is : " << height(bnt);

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

/* void boundaryPrintL(tNode *root)
 {
    // left side first
    deque<int> left, bottom, right;
    vector<tNode *> rNs;
    leafNodes(leafNs, root);

    for (auto i : leafNs)
        bottom.push_back(i->data);

    tNode *temp = root;
    for (; temp != nullptr; left.push_back(temp->data), temp = temp->leftNode)
        ;
    left.pop_back();
    temp = root->rightNode;
    for (; temp != nullptr; right.push_front(temp->data), temp = temp->rightNode)
        ;
    right.pop_front();

    for (auto &&i : left)
        cout << i << " ";

    for (auto &&i : bottom)
        cout << i << " ";

    for (auto &&i : right)
        cout << i << " ";
}
*/
