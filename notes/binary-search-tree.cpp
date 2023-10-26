// Binary Search Tree (BST)

// Search
// best case O(log(n))
// worst case O(n)

// Insert
// O(log(n))

// Min/Max
// O(log(n))

// Printing
// inorder() for alphabetical
// O(n)

// Clearing
// also traverse all nodes like printing
// O(n)

#include <iostream>

struct Node {
    Node(const int &val) {
        value = val;
        left = right = nullptr;
    }
    int value;
    Node *left, *right;
};

class BST {
    public:
        BST() {
            m_root = nullptr;
        }
        void insert_iterative(const int &val);
        void insertRecursive(const int &val);

        bool searchIterative(int value);
        bool searchRecursive(int value);

        int GetMin(Node* root);
        int GetMax(Node* root);
        void inorder(Node* cur) {
            if (cur == nullptr)
                return;
            inorder(cur->left);
            std::cout << cur->value;
            inorder(cur->right);
        }
        void freetree(Node* cur) {
            if (cur == nullptr) {
                return;
            }
            freetree(cur->left);
            freetree(cur->right);
            delete cur;
        }
        void deleteNode(int val);
    private:
        Node* m_root;
        bool searchRecursiveHelper(Node* node, int value);
};

// SEARCH
// iterative
bool search_iterative(int v, Node* root) {
    while (root != nullptr) {
        if (v == root->value)
            return true;  // found
        else if(v < root->value)
            root = root->left;
        else
            root = root->right;
    }
    return false;  // not found
}
// recursive
bool search_recursive(int v, Node* root) {
    if (root == nullptr) {
        return false;
    }
    else if (v == root->value)
        return true;
    else if (v > root->value)
        return search_recursive(v, root->left);
    else
        return search_recursive(v, root->right);
}

bool BST::searchIterative(int value) {
    Node* current = m_root;
    while (current != nullptr) {
        if (value == current->value) {
            return true;
        } else if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

bool BST::searchRecursive(int value) {
    return searchRecursiveHelper(m_root, value);
}

bool BST::searchRecursiveHelper(Node* node, int value) {
    if (node == nullptr) {
        return false;
    } else if (value == node->value) {
        return true;
    } else if (value < node->value) {
        return searchRecursiveHelper(node->left, value);
    } else {
        return searchRecursiveHelper(node->right, value);
    }
}



// INSERT
// iterative
void BST::insert_iterative(const int &val) {
    if (m_root == nullptr) {
        m_root = new Node(val);
        return;
    }

    Node* cur = m_root;
    for(;;) {  // infinite loop
        // if value already in the tree, do nothing
        if (val == cur->value)
            return;

        // if val is less than what's in the cur node
        if (val < cur->value) {
            // advance to the left if there's no spot
            if (cur->left != nullptr)
                cur = cur->left;
            // else add new node with the value
            else {
                cur->left = new Node(val);
                return;
            }
        }

        // do right side
        if (val > cur->value) {
            // advance to the left if there's no spot
            if (cur->right != nullptr)
                cur = cur->right;
            // else add new node with the value
            else {
                cur->right = new Node(val);
                return;
            }
        }
    }
}
// recursive
void BST::insertRecursive(const int& val) {
    m_root = insertRecursiveHelper(m_root, val);
}
Node* insertRecursiveHelper(Node* root, const int& val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->value) {
        root->left = insertRecursiveHelper(root->left, val);
    } else if (val > root->value) {
        root->right = insertRecursiveHelper(root->right, val);
    }
    // if the value already exists in the tree, do nothing

    return root;
}



// MIN and MAX
int BST::GetMin(Node* p) {
    if (p == nullptr)
        return -1;

    while (p->left != nullptr)
        p = p->left;  // exits loop when we hit the most left node in tree

    return p->value;
}
int BST::GetMax(Node* p) {
    if (p == nullptr)
        return -1;

    while (p->right != nullptr)
        p = p->right;  // exits loop when we hit the most right node in tree

    return p->value;
}



// DELETE
void BST::deleteNode(int val) {
    m_root = deleteNodeRecursive(m_root, val);
}
Node* deleteNodeRecursive(Node* root, int val) {
    if (root == nullptr) {
        // Value not found, return nullptr
        return nullptr;
    }

    if (val < root->value) {
        // Value is less than current node, traverse left subtree
        root->left = deleteNodeRecursive(root->left, val);
    } else if (val > root->value) {
        // Value is greater than current node, traverse right subtree
        root->right = deleteNodeRecursive(root->right, val);
    } else {
        // Value matches current node, delete this node
        if (root->left == nullptr) {
            // Node is a leaf node
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            // Node has one child
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            // Node has two children
            // Find the inorder successor (minimum value in right subtree)
            Node* parent = root;
            Node* successor = root->right;
            while (successor->left != nullptr) {
                parent = successor;
                successor = successor->left;
            }
            // Replace the value of the node to be deleted with the successor value
            root->value = successor->value;
            // Recursively delete the successor node
            if (parent == root) {
                root->right = deleteNodeRecursive(root->right, successor->value);
            } else {
                parent->left = deleteNodeRecursive(parent->left, successor->value);
            }
        }
    }
    return root;
}
