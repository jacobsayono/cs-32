#include <iostream>
#include <queue>

struct BinaryTree {
    int value;
    BinaryTree* left, *right;
};

void preorder(BinaryTree* p) {
    if (p == nullptr)
        return;
    std::cout << p->value << " ";
    preorder(p->left);
    preorder(p->right);
}

// prints BST in alphabetical order
// O(n) because we have to visit all nodes (recusively) to print all of its values
void inorder(BinaryTree* p) {
    if (p == nullptr)
        return;
    inorder(p->left);
    std::cout << p->value << " ";
    inorder(p->right);
}

void postorder(BinaryTree* p) {
    if (p == nullptr)
        return;
    postorder(p->left);
    postorder(p->right);
    std::cout << p->value << " ";
}

void levelorder(BinaryTree* root) {
    if (root == nullptr)
        return;

    std::queue<BinaryTree*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTree* current = q.front();
        q.pop();
        std::cout << current->value << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

int main() {
    // Create a binary tree
    BinaryTree* root = new BinaryTree();
    root->value = 1;
    root->left = new BinaryTree();
    root->left->value = 2;
    root->right = new BinaryTree();
    root->right->value = 3;
    root->left->left = new BinaryTree();
    root->left->left->value = 4;
    root->left->right = new BinaryTree();
    root->left->right->value = 5;
    root->right->left = new BinaryTree();
    root->right->left->value = 6;
    root->right->right = new BinaryTree();
    root->right->right->value = 7;

    /*

        1
       / \
      2   3
     / \ / \
    4  5 6  7

    */

    std::cout << "Preorder traversal: ";
    preorder(root);
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorder(root);
    std::cout << std::endl;

    std::cout << "Level-order traversal: ";
    levelorder(root);
    std::cout << std::endl;

    return 0;
}
