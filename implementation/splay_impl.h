//IMPLEMENTATION
#include "../class/splay.h"

//PUBLIC
template<typename T>
Splay<T>::Splay() {};

template<typename T>
Splay<T>::Splay(T array[], size_t length) {

};

template<typename T>
Splay<T>::~Splay() {
    if (this->root_ != NULL)
        delete this->root_;
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
    this->pre_order_(this->root_, f);
};

template<typename T>
void Splay<T>::in_order(void (*f)(T &value)) {
    this->in_order_(this->root_, f);
};

template<typename T>
void Splay<T>::post_order(void (*f)(T &value)){
    this->post_order_(this->root_, f);
};


template<typename T>
Splay<T> *Splay<T>::operator+(const Splay<T> &tree) {

};

template<typename T>
Splay<T> *Splay<T>::operator-(const Splay<T> &tree) {

};




//PROTECTED
template<typename T>
void Splay<T>::splay_(Node<T> node) {

}

template<typename T>
T *Splay<T>::search_(Node<T> *node, T &value) {
    return NULL;
}

template<typename T>
void Splay<T>::insert_(Node<T> *&node, T &value) {

}

template<typename T>
bool Splay<T>::remove_(Node<T> *&node, T &value, Node<T> *parent) {
    return false;
}


template<typename T>
void Splay<T>::pre_order_(Node<T>* node, void(*f)(T &value)) {
    if(node != NULL) {
        f(node->data);
        this->pre_order_(node->left, f);
        this->pre_order_(node->right, f);
    }
};

template<typename T>
void Splay<T>::in_order_(Node<T>* node, void(*f)(T &value)) {
    if(node != NULL) {
        this->in_order_(node->left, f);
        f(node->data);
        this->in_order_(node->right, f);
    }
};

template<typename T>
void Splay<T>::post_order_(Node<T>* node, void(*f)(T &value)) {
    if(node != NULL) {
        this->post_order_(node->left, f);
        this->post_order_(node->right, f);
        f(node->data);
    }
};

template<typename T>
Node<T> *Splay<T>::merge_(Node<T> *node_1, Node<T> *node_2) {
    return NULL;
}

template<typename T>
Node<T> *Splay<T>::split_(Node<T> *node_1, Node<T> *node_2) {
    return NULL;
}