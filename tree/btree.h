//      10
//    /    \
//   6      14
//  / \    /  \
// 5   8  11  18
#include <cstdio>
#include "stdio.h"
#include <string>
struct node
{
    int data;
    node *left;
    node *right;
};

class btree
{
private:
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
    void destroy_tree(node *leaf);
    void printm(node *n, bool left, std::string const &indent);
    void print_tree(node *root);
    node *root;

public:
    btree();
    ~btree();
    void insert(int key);
    node *search(int key);
    void destroy_tree();
    void print_tree();
};
