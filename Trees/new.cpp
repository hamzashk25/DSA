#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node *root;

    Node *insertnode(Node *node, int val)
    {
        if (node == NULL)
        {
            Node *temp = new Node(val);
            node = temp;
            return temp;
        }

        if (val < node->data)
            node->left = insertnode(node->left, val);
        else
            node->right = insertnode(node->right, val);

        return node;
    }

    void inorderTraversal(Node *node)
    {
        if (node == NULL)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    Node *findMin(Node *root)
    {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    Node *deleteNode(Node *root, int key)
    {
        if (root == NULL)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL)
                return root->right;
            else if (root->right == NULL)
                return root->left;

            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int val)
    {
        root = insertnode(root, val);
    }

    void inorder()
    {
        inorderTraversal(root);
    }

    void Delete(int val)
    {
        deleteNode(root, val);
    }
};
int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << endl;
    
    tree.Delete(30);
    cout << "Inorder Traversal: ";
    tree.inorder();
    return 0;
}