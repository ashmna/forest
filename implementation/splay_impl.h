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
void Splay<T>::pre_order(void (*f)(T &value)){
    pre_order_(root_, f);
};

template<typename T>
void Splay<T>::in_order(void (*f)(T &value)) {
    in_order_(root_, f);
};

template<typename T>
void Splay<T>::post_order(void (*f)(T &value)){
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
void Splay<T>::splay_(Node node) {

}

template<typename T>
T *Splay<T>::search_(Node *node, T &value) {
    return NULL;
}

template<typename T>
void Splay<T>::insert_(Node *&node, T &value) {

}

template<typename T>
bool Splay<T>::remove_(Node *&node, T &value, Node *parent) {
    return false;
}


template<typename T>
void Splay<T>::pre_order_(Node* node, void(*f)(T &value)) {
    if(node != NULL) {
        f(node->data);
        pre_order_(node->left, f);
        pre_order_(node->right, f);
    }
};

template<typename T>
void Splay<T>::in_order_(Node* node, void(*f)(T &value)) {
    if(node != NULL) {
        in_order_(node->left, f);
        f(node->data);
        in_order_(node->right, f);
    }
};

template<typename T>
void Splay<T>::post_order_(Node* node, void(*f)(T &value)) {
    if(node != NULL) {
        post_order_(node->left, f);
        post_order_(node->right, f);
        f(node->data);
    }
};

template<typename T>
void Splay<T>::merge_(Node *&node, Node *node_1, Node *node_2) {
    
}

template<typename T>
void Splay<T>::split_(Node *&node, Node *node_1, Node *node_2) {

}