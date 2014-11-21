#ifndef __SPLAY_TREE_
#define __SPLAY_TREE_

#include <stddef.h>


template <class T>
class Splay {

public:
    Splay();
    Splay(T array[], size_t length);
    ~Splay();

    T *search(T value);
    void insert(T value);
    bool remove(T value);

    void pre_order(void (*f)(T &value)) const; // copy from bst tree
    void in_order(void (*f)(T &value)) const; // copy from bst tree
    void post_order(void (*f)(T &value)) const; // copy from bst tree

    Splay<T> *operator+(const Splay<T> &tree);
    Splay<T> *operator-(const Splay<T> &tree);

protected:
    struct Node;

    void splay_(Node *node);
    void rotate_(Node *x);

    T *search_(Node *node, T &value) const; // copy from bst tree
    void insert_(Node *&node, T &value, Node *parent = NULL);
    bool remove_(Node *&node, T &value, Node *parent = NULL);

    void pre_order_(Node *node, void (*f)(T &value)) const; // copy from bst tree
    void in_order_(Node *node, void (*f)(T &value)) const; // copy from bst tree
    void post_order_(Node *node, void (*f)(T &value)) const; // copy from bst tree

    void build_tree_from_sorted_array_(Node *&node, T array[], size_t start, size_t end);
    void merge_(Node *&node, Node *node_1, Node *node_2);
    void split_(Node *&node, Node *node_1, Node *node_2);

    Node *root_;

};

#endif