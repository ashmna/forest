#ifndef __BINARY_SEARCH_TREE_
#define __BINARY_SEARCH_TREE_

#include <stddef.h>


template<typename T>
struct Node {
    T data;
    Node *left;
    Node *right;

    Node(T &value) : data(value) {}

    ~Node() {
        if (this->left != NULL)
            delete this->left;
        if (this->right != NULL)
            delete this->right;
        //delete this->data;
    }
};

template<typename T>
class BST {

public:
    BST();
    BST(T array[], size_t length);
    ~BST();

    T *search(T value);
    void insert(T value);
    bool remove(T value);
    bool is_bst();

    void pre_order(void (*f)(T &value));
    void in_order(void (*f)(T &value));
    void post_order(void (*f)(T &value));

    BST<T> *operator+(const BST<T> &tree);

protected:
    T *search_(Node<T> *node, T &value);
    void insert_(Node<T> *&node, T &value);
    bool remove_(Node<T> *node, T &value, Node<T> *parent = NULL);
    bool is_bst_(Node<T> *node);

    void pre_order_(Node<T> *node, void (*f)(T &value));
    void in_order_(Node<T> *node, void (*f)(T &value));
    void post_order_(Node<T> *node, void (*f)(T &value));
    void build_tree_from_sorted_array_(Node<T> *&node, T array[], size_t start, size_t end);
    Node<T> *merge_(Node<T> *node_1, Node<T> *node_2);

    Node<T> *root_;
};

#include "../implementation/bst_impl.h"

#endif