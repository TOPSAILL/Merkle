#include "btree.h"
#include <string>
#include <iostream>
btree::btree()
{
    root = NULL;
}

btree::~btree()
{
    destroy_tree();
}

void btree::destroy_tree(node *leaf)
{
    while (leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::insert(int key, node *leaf)
{
    if (key < leaf->data)
    {
        if (leaf->left != NULL)
            insert(key, leaf->left);
        else
        {
            leaf->left = new node;
            leaf->left->data = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if (key >= leaf->data)
    {
        if (leaf->right != NULL)
            insert(key, leaf->right);
        else
        {
            leaf->right = new node;
            leaf->right->data = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

node *btree::search(int key, node *leaf)
{
    if (leaf == NULL)
        return NULL;
    else
    {
        if (leaf->data == key)
            return leaf;
        if (key < leaf->data)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
}

//public version
//takes care of the case where the root has not been initialized
void btree::insert(int key)
{
    if (root == NULL)
    {
        root = new node;
        root->data = key;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        insert(key, root);
    }
}

node *btree::search(int key)
{
    return search(key, root);
}

void btree::destroy_tree()
{
    destroy_tree(root);
}

void btree::printm(node *n, bool left, std::string const &indent)
{
    if (n->right)
    {
        printm(n->right, false, indent + (left ? "|     " : "      "));
    }
    std::cout << indent;
    std::cout << (left ? '\\' : '/');
    std::cout << "-----";
    std::cout << n->data << std::endl;
    if (n->left)
    {
        printm(n->left, true, indent + (left ? "      " : "|     "));
    }
}
void btree::print_tree(node *root)
{
    if (root->right)
    {
        printm(root->right, false, "");
    }
    std::cout << root->data << std::endl;
    if (root->left)
    {
        printm(root->left, true, "");
    }
}
void btree::print_tree()
{
    print_tree(root);
}
int main()
{
    btree p1 = btree();
    p1.insert(2);
    p1.insert(10);
    p1.insert(1);
    p1.insert(12);
    p1.insert(90);
    p1.insert(80);
    p1.insert(111);
    p1.insert(9);
    p1.print_tree();
}
