#include <iostream>
using namespace std;

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

class AVL
{
public:
    int getheight(Node *n)
    {
        if (n == NULL)
            return 0;

        return n->height;
    }

    int getbalance(Node *n)
    {
        if (n == NULL)
            return 0;
        return getheight(n->left) - getheight(n->right);
    }

    Node *RightRotation(Node *y)
    {
        Node *x = y->left;
        Node *t2 = x->right;

        x->right=y;
        y->left=t2;

            
    }


};