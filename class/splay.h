#ifndef __SPLAY_TREE_
#define __SPLAY_TREE_

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
    }
};



template <class T>
class Splay {

public:
    Splay();
    Splay(T array[], size_t length);
    ~Splay();

    T *search(T value);
    void insert(T value);
    bool remove(T value);

    void pre_order(void (*f)(T &value));
    void in_order(void (*f)(T &value));
    void post_order(void (*f)(T &value));

    Splay<T> *operator+(const Splay<T> &tree);
    Splay<T> *operator-(const Splay<T> &tree);

protected:
    void splay_(Node<T> node);

    T *search_(Node<T> *node, T &value);
    void insert_(Node<T> *&node, T &value);
    bool remove_(Node<T> *&node, T &value, Node<T> *parent = NULL);

    void pre_order_(Node<T> *node, void (*f)(T &value));
    void in_order_(Node<T> *node, void (*f)(T &value));
    void post_order_(Node<T> *node, void (*f)(T &value));

    Node<T> *merge_(Node<T> *node_1, Node<T> *node_2);
    Node<T> *split_(Node<T> *node_1, Node<T> *node_2);

    Node<T> *root_;

};

#endif