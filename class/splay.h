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

    void pre_order(void (*f)(T &value)) const;
    void in_order(void (*f)(T &value)) const;
    void post_order(void (*f)(T &value)) const;

    Splay<T> *operator+(const Splay<T> &tree);
    Splay<T> *operator-(const Splay<T> &tree);

protected:
    struct Node;

    void splay_(Node *node);

    T *search_(Node *node, T &value);
    void insert_(Node *&node, T &value);
    bool remove_(Node *&node, T &value, Node *parent = NULL);

    void pre_order_(Node *node, void (*f)(T &value)) const;
    void in_order_(Node *node, void (*f)(T &value)) const;
    void post_order_(Node *node, void (*f)(T &value)) const;

    void merge_(Node *&node, Node *node_1, Node *node_2);
    void split_(Node *&node, Node *node_1, Node *node_2);

    Node *root_;

};

#endif