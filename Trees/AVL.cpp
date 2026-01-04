#include <iostream>
using namespace std;
// Node class
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    int height;

    Node(int v)
    {
        value = v;
        left = right = NULL;
        height = 1;
    }
};

// AVL Tree class
class AVL
{
public:
    // Get height of node
    int getHeight(Node *n)
    {
        if (n == NULL)
            return 0;
        return n->height;
    }

    // Get balance factor
    int getBalance(Node *n)
    {
        if (n == NULL)
            return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    // Right Rotation
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    // Left Rotation
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    // Insert a value
    Node *insert(Node *node, int key)
    {
        // Normal BST insert
        if (node == NULL)
            return new Node(key);

        if (key < node->value)
            node->left = insert(node->left, key);
        else if (key > node->value)
            node->right = insert(node->right, key);
        else
            return node; // no duplicates

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Check balance
        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && key < node->left->value)
            return rightRotate(node);

        // RR Case
        if (balance < -1 && key > node->right->value)
            return leftRotate(node);

        // LR Case
        if (balance > 1 && key > node->left->value)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (balance < -1 && key < node->right->value)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node; // balanced
    }
    // Inorder Traversal
    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
};
// Driver Code
int main()
{
    AVL tree;
    Node *root = NULL;
    root = tree.insert(root, 30);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 10);
    cout << "Inorder Traversal: ";
    tree.inorder(root);
} 