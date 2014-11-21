//IMPLEMENTATION
#include "../class/splay.h"

//PUBLIC
template<typename T>
Splay<T>::Splay() : root_(NULL) {};

template<typename T>
Splay<T>::Splay(T array[], size_t length) {
    build_tree_from_sorted_array_(root_, array, 0, length-1);
};

template<typename T>
Splay<T>::~Splay() {
    delete root_;
};

template<typename T>
T  *Splay<T>::search(T value) {
    Node *node = search_(root_, value);
    if(node != NULL) {
        splay_(node);
    }
    return node;
};

template<typename T>
void Splay<T>::insert(T value) {
    insert_(root_, value);
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

    Node(T &value, Node* parent = NULL) : data(value), left(NULL), right(NULL), parent(parent) {}

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
            rotate_(node);
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
T* Splay<T>::search_(Node *node, T &value) const {
    if (node == NULL)
        return NULL;
    if (node->data == value)
        return &node->data;
    if (node->data < value)
        return search_(node->right, value);
    else
        return search_(node->left, value);
}

template<typename T>
void Splay<T>::insert_(Node *&node, T &value, Node *parent) {
    if (node == NULL) {
        node = new Node(value, parent);
        splay_(node);
    } else if (value < node->data) {
        insert_(node->left, value, node);
    } else {
        insert_(node->right, value, node);
    }
};

template<typename T>
bool Splay<T>::remove_(Node *&node, T &value) {
    bool ret = false;
    if(node != NULL) {
        if(node->data == value) {
            if (node->left != NULL && node->right != NULL) {
                Node *sub_node = node->right;
                while (sub_node->left != NULL) {
                    sub_node = sub_node->left;
                }
                T tmp_value = node->data;
                node->data = sub_node->data;
                sub_node->data = tmp_value;
                ret = remove_(node->right, value);
            } else {
                Node *new_node = node->left;
                if (node->right != NULL) new_node = node->right;
                if (node->parent != NULL) {
                    if (node->parent->left == node)
                        node->parent->left = new_node;
                    else
                        node->parent->right = new_node;
                } else {
                    root_ = new_node;
                }
                node->left = NULL;
                node->right = NULL;
                delete node;
                ret = true;
            }
        } else {
            if (node->data < value) {
                ret = remove_(node->right, value);
            } else {
                ret = remove_(node->left, value);
            }
        }
    }
    return ret;
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
void Splay<T>::build_tree_from_sorted_array_(Node *&node, T array[], size_t start, size_t end, Node *parent) {
    size_t middle = start + (end - start)/2;
    node = new Node(array[middle], parent);
    if(middle > start) {
        build_tree_from_sorted_array_(node->left, array, start, middle-1, node);
    }
    if(middle < end) {
        build_tree_from_sorted_array_(node->right, array, middle+1, end, node);
    }
}

template<typename T>
void Splay<T>::merge_(Node *&node, Node *node_1, Node *node_2) {
    
};

template<typename T>
void Splay<T>::split_(Node *&node, Node *node_1, Node *node_2) {

};