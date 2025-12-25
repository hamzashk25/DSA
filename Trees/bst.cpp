#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct Stack
{
    Node *arr[1000];
    int top;

    Stack() : top(-1) {}

    void push(Node *node)
    {
        arr[++top] = node;
    }

    Node *pop()
    {
        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class BST
{
private:
    Node *root;

    Node *insert(Node *node, int val)
    {
        if (node == nullptr)
        {
            return new Node(val);
        }

        Node *current = node;
        while (true)
        {
            if (val < current->data)
            {
                if (current->left == nullptr)
                {
                    current->left = new Node(val);
                    break;
                }
                current = current->left;
            }
            else if (val > current->data)
            {
                if (current->right == nullptr)
                {
                    current->right = new Node(val);
                    break;
                }
                current = current->right;
            }
            else
                break;
        }
        return node;
    }

    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node *deleteNode(Node *node, int val)
    {
        if (node == nullptr)
            return nullptr;

        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else
        {
            // Leaf node
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }

            // One child
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Two children
            Node *minRight = findMin(node->right);
            node->data = minRight->data;
            node->right = deleteNode(node->right, minRight->data);
        }
        return node;
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    Node *search(int val)
    {
        Node *current = root;
        while (current != nullptr)
        {
            if (val == current->data)
                return current;
            else if (val < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }

public:
    BST() : root(nullptr) {}

    void insert(int val)
    {
        root = insert(root, val);
    }

    void deleteVal(int val)
    {
        root = deleteNode(root, val);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }

    bool searchVal(int val)
    {
        return search(val) != nullptr;
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

    cout << "Inorder traversal: ";
    tree.display();

    tree.deleteVal(20);
    cout << "After deleting 20: ";
    tree.display();

    return 0;
}