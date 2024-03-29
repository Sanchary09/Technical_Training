#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// PreOrder traversal function
void preOrder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    
    // First print the data of the node
    cout << node->val << " ";
    
    // Then recur on left child
    preOrder(node->left);
    
    // Finally recur on right child
    preOrder(node->right);
}

// Utility function to add a new node
TreeNode* insertNode(int data) {
    TreeNode* newNode = new TreeNode(data);
    return newNode;
}

int main() {
    // Example to test the preOrder function
    // Creating a simple binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    
    TreeNode *root = insertNode(1);
    root->left = insertNode(2);
    root->right = insertNode(3);
    root->left->left = insertNode(4);
    root->left->right = insertNode(5);
    
    cout << "Pre-order traversal of binary tree is: \n";
    preOrder(root);
    
    return 0;
}
