//IMPLEMENTATION
#include "../class/splay.h"

//PUBLIC
template<typename T>
Splay<T>::Splay() : root_(NULL) {};

template<typename T>
Splay<T>::Splay(T array[], size_t length) {

};

template<typename T>
Splay<T>::~Splay() {
    delete root_;
};

template<typename T>
T  *Splay<T>::search(T value) {

};

template<typename T>
void Splay<T>::insert(T value) {

};

template<typename T>
bool Splay<T>::remove(T value) {

};

template<typename T>
void Splay<T>::pre_order(void (*f)(T &value)) const {
    pre_order_(root_, f);
};

template<typename T>
void Splay<T>::in_order(void (*f)(T &value)) const {
    in_order_(root_, f);
};

template<typename T>
void Splay<T>::post_order(void (*f)(T &value)) const {
    post_order_(root_, f);
};


template<typename T>
Splay<T> *Splay<T>::operator+(const Splay<T> &tree) {

};

template<typename T>
Splay<T> *Splay<T>::operator-(const Splay<T> &tree) {

};


//PROTECTED
template<typename T>
struct Splay<T>::Node {
    T data;
    Node *left;
    Node *right;
    Node *parent;

    Node(T &value) : data(value), left(NULL), right(NULL), parent(NULL) {}

    ~Node() {
        delete left;
        delete right;
        delete parent;
    }
};

template<typename T>
void Splay<T>::splay_(Node *node) {
    while(node->parent != NULL) {
        if(node->parent == root_) {
            rotate_(node);
        } else if( (node->parent->left == node && node->parent->parent->left == node->parent) || (node->parent->right == node && node->parent->parent->right == node->parent) ) {
            rotate_(node->parent);
            rotate_(node);
        } else {
            rotate_(node);
            rotate_(node->parent);
        }
    }
}
template<typename T>
void Splay<T>::rotate_(Node *node) {
    if(node == node->parent->left) {
        node->parent->left = node->right;
        node->right = node->parent;
    } else {
        node->parent->right = node->left;
        node->left = node->parent;
    }
    if(node->parent->parent != NULL) {
        node->parent = node->parent->parent;
    } else {
        node->parent = NULL;
        root_ = node;
    }
}

template<typename T>
T *Splay<T>::search_(Node *node, T &value) {
    return NULL;
};

template<typename T>
void Splay<T>::insert_(Node *&node, T &value) {

};

template<typename T>
bool Splay<T>::remove_(Node *&node, T &value, Node *parent) {
    return false;
};


template<typename T>
void Splay<T>::pre_order_(Node* node, void(*f)(T &value)) const {
    if(node != NULL) {
        f(node->data);
        pre_order_(node->left, f);
        pre_order_(node->right, f);
    }
};

template<typename T>
void Splay<T>::in_order_(Node* node, void(*f)(T &value)) const {
    if(node != NULL) {
        in_order_(node->left, f);
        f(node->data);
        in_order_(node->right, f);
    }
};

template<typename T>
void Splay<T>::post_order_(Node* node, void(*f)(T &value)) const {
    if(node != NULL) {
        post_order_(node->left, f);
        post_order_(node->right, f);
        f(node->data);
    }
};

template<typename T>
void Splay<T>::merge_(Node *&node, Node *node_1, Node *node_2) {
    
};

template<typename T>
void Splay<T>::split_(Node *&node, Node *node_1, Node *node_2) {

};