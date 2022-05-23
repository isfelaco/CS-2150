#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// cd /mnt/c/Users/isfel/OneDrive\ -\ University\ of\ Virginia/Second\ Year/CS\ 2150/


AVLTree::AVLTree() {
    root = NULL;
    size = 0;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    root = insertB(root,x);
    balance(root);
}

AVLNode* AVLTree::insertB(AVLNode* n, const string& x) {
    if (n == NULL) {
        n = new AVLNode();
        n->value = x;
        size ++;
    }
    else if (x < n->value) {
        n->left = insertB(n->left, x);
    }
    else if (x > n->value) {
        n->right = insertB(n->right, x);
    }
    return n;
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
    size--;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    string path = "";
    if(findB(root, x, path)) {
        return path;
    }
    return "";
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    string path = "";
    return findB(root, x, path);
}


bool AVLTree::findB(AVLNode* n, const string& x, string& path) const{
    if (n == NULL) {
        return false;
    }
    if (x == n->value) {
        path += n->value;
        path += " ";
        return true;
    }
    if (x < n->value) {
        path += n->value;
        path += " ";
        return findB(n->left, x, path);
    }
    if (x > n->value) {
        path += n->value;
        path += " ";
        return findB(n->right, x, path);
    }
    return false;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    return size;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    n->height = height(n);
    if (n->left != NULL) {
        if (n->factor < -1) {
            if (n->left->factor > 0) {
                n->left = rotateLeft(n->left);
            }
            n = rotateRight(n);
        }
        balance(n->left);
    }
    if (n->right != NULL) {
        if (n->factor > 1) {
            if (n->right->factor < 0) {
                n->right = rotateRight(n->right);
            }
            n = rotateLeft(n);
        }
        balance(n->right);
    }
    printTree();
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* temp;
    if (n->right->left != NULL)
        temp = n->right->left;
    else
        temp = NULL;
    n->right->left = n;
    n->height = n->right->height;
    n = n->right;
    n->left->right = temp;
    return n;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* temp;
    if (n->left->right != NULL)
        temp = n->left->right;
    else
        temp = NULL;
    n->left->right = n;
    n->height = n->left->height;
    n = n->left;
    n->right->left = temp;
    return n;
}



// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node != NULL) {
        node = heightB(node);
        return node->height;
    }
    else {
        return 0;
    }
}

AVLNode* AVLTree::heightB(AVLNode* node) const {
    int right = 0;
    int left = 0;
    if (node->right != NULL) {
        right++;
        right += height(node->right);
    }
    if (node->left != NULL) {
        left ++;
        left += height(node->left);
    }
    node->height = max(right,left);
    node->factor = right-left;
    return node;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
