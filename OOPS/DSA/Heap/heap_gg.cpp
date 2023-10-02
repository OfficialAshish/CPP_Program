
// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    int countn(struct Node* tree){
        if (tree == nullptr) return 0;
        return (1 + countn(tree->left) + countn(tree->right));
    }

    bool iscbt(struct Node* tree, int i, int tc){
        if (tree == nullptr) return true;

        if (i >= tc) return false;

        bool left = iscbt(tree->left, 2*i + 1, tc);
        bool right = iscbt(tree->right, 2*i + 2, tc);
        return left && right;
    }

    bool isheap(struct Node* tree) {
    if (tree == nullptr) return true;
    
    if (tree->left != nullptr && tree->left->data > tree->data) return false;
    if (tree->right != nullptr && tree->right->data > tree->data) return false;

    return isheap(tree->left) && isheap(tree->right);
}


    bool isHeap(struct Node* tree) {
        int count = countn(tree);
        bool iscb = iscbt(tree, 0, count);
        if (!iscb) return false;
        bool ismaxH = isheap(tree);
        
        return (iscb && ismaxH);
    }
};