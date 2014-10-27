#ifndef __BINARY_SEARCH_TREE_
#define __BINARY_SEARCH_TREE_

#include <stddef.h>


template<class T>
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

template<class T>
class BST {

public:
    BST();
    ~BST();

    T *search(T value);
    void insert(T value);
    bool remove(T value);
    void preOrder(void (*f)(T &value));
    void inOrder(void (*f)(T &value));
    void postOrder(void (*f)(T &value));

protected:
    T *_search(Node<T> *node, T &value);
    void _insert(Node<T> *&node, T &value);
    bool _remove(Node<T> *node, T &value, Node<T> *parent = NULL);

    void _preOrder(Node<T> *node, void (*f)(T &value));
    void _inOrder(Node<T> *node, void (*f)(T &value));
    void _postOrder(Node<T> *node, void (*f)(T &value));

    Node<T> *_root;
};

#include "../implementation/bst_impl.h"

#endif