#ifndef __BINARY_SEARCH_TREE_
#define __BINARY_SEARCH_TREE_

#include <stddef.h>

template<typename T>
class BST {

public:
    BST();
    BST(T array[], size_t length);
    ~BST();

    T *search(T value) const;
    void insert(T value);
    bool remove(T value);
    bool is_bst() const;

    void pre_order(void (*f)(T &value)) const;
    void in_order(void (*f)(T &value)) const;
    void post_order(void (*f)(T &value)) const;

    BST<T> *operator+(const BST<T> &tree);

protected:
    struct Node{
        T data;
        Node *left;
        Node *right;

        Node(const T &value) : data(value), left(NULL), right(NULL) {}

        ~Node() {
            delete left;
            delete right;
        }
    };

    T *search_(Node *node, T &value) const;
    void insert_(Node *&node, T &value);
    bool remove_(Node *node, T &value, Node *parent = NULL);
    bool is_bst_(Node *node) const;

    void pre_order_(Node *node, void (*f)(T &value)) const;
    void in_order_(Node *node, void (*f)(T &value)) const;
    void post_order_(Node *node, void (*f)(T &value)) const;
    void build_tree_from_sorted_array_(Node *&node, T array[], size_t start, size_t end);
    void merge_(Node *&node, Node *node_1, Node *node_2);

    Node *root_;
};

#include "../implementation/bst_impl.h"

#endif