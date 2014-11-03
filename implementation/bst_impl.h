//IMPLEMENTATION
#include "../class/bst.h"

//PUBLIC

template<class T>
BST<T>::BST() {
}

template<class T>
BST<T>::BST(T array[], size_t length) {
    this->build_tree_from_sorted_array_(this->root_, array, 0, length-1);
}

template<class T>
BST<T>::~BST() {
    if (this->root_ != NULL)
        delete this->root_;
}

template<class T>
T *BST<T>::search(T value) {
    return this->search_(this->root_, value);
}

template<class T>
void BST<T>::insert(T value) {
    this->insert_(this->root_, value);
}

template<class T>
bool BST<T>::remove(T value) {
    return this->remove_(this->root_, value);
}

template<class T>
bool BST<T>::is_bst() {
    return this->is_bst_(this->root_);
};


template<class T>
void BST<T>::pre_order(void (*f)(T &value)){
    this->pre_order_(this->root_, f);
};

template<class T>
void BST<T>::in_order(void (*f)(T &value)) {
    this->in_order_(this->root_, f);
};

template<class T>
void BST<T>::post_order(void (*f)(T &value)){
    this->post_order_(this->root_, f);
};

template<class T>
BST<T> *BST<T>::operator+(const BST<T> &tree) {
    BST<T> *bst = new BST<T>();
    bst->root_ = this->merge_(this->root_, tree.root_);
    return bst;
};

//PRIVATE

template<class T>
T* BST<T>::search_(Node<T> *node, T &value) {
    if (node == NULL)
        return NULL;
    if (node->data == value)
        return &node->data;
    if (node->data < value)
        return this->search_(node->right, value);
    else
        return this->search_(node->left, value);
}

template<class T>
void BST<T>::insert_(Node<T> *&node, T &value) {
    if (node == NULL) {
        node = new Node<T>(value);
    } else if (value < node->data) {
        this->insert_(node->left, value);
    } else {
        this->insert_(node->right, value);
    }
};

template<class T>
bool BST<T>::remove_(Node<T> *node, T &value, Node<T> *parent) {
    bool ret = false;
    if (node != NULL) {
        if (node->data == value) {
            if (node->left != NULL && node->right != NULL) {
                Node<T> *sub_node = node->right;
                while (sub_node->left != NULL) {
                    sub_node = sub_node->left;
                }
                T tmp_value = node->data;
                node->data = sub_node->data;
                sub_node->data = tmp_value;
                ret = this->remove_(node->right, value, node);
            } else {
                Node<T> *new_node = node->left;
                if (node->right != NULL) new_node = node->right;
                if (parent != NULL) {
                    if (parent->left == node)
                        parent->left = new_node;
                    else
                        parent->right = new_node;
                } else {
                    this->root_ = new_node;
                }
                node->left = NULL;
                node->right = NULL;
                delete node;
                ret = true;
            }
        } else {
            if (node->data < value) {
                ret = this->remove_(node->right, value, node);
            } else {
                ret = this->remove_(node->left, value, node);
            }
        }
    }
    return ret;
}
template<class T>
bool BST<T>::is_bst_(Node<T> *node) {
    bool ret = true;
    if(node != NULL) {
        if(node->left != NULL) {
            ret = node->left->data < node->data;
            if(ret)
                ret = this->is_bst_(node->left);
        }
        if(ret && node->right != NULL) {
            ret = node->data < node->right->data;
            if(ret)
                ret = this->is_bst_(node->right);
        }
    }
    return ret;
};


template<class T>
void BST<T>::pre_order_(Node<T>* node, void(*f)(T &value)) {
    if(node != NULL) {
        f(node->data);
        this->pre_order_(node->left, f);
        this->pre_order_(node->right, f);
    }
};

template<class T>
void BST<T>::in_order_(Node<T>* node, void(*f)(T &value)) {
    if(node != NULL) {
        this->in_order_(node->left, f);
        f(node->data);
        this->in_order_(node->right, f);
    }
};

template<class T>
void BST<T>::post_order_(Node<T>* node, void(*f)(T &value)) {
    if(node != NULL) {
        this->post_order_(node->left, f);
        this->post_order_(node->right, f);
        f(node->data);
    }
};

template<class T>
void BST<T>::build_tree_from_sorted_array_(Node<T> *&node, T array[], size_t start, size_t end) {
    size_t middle = start + (end - start)/2;
    node = new Node<T>(array[middle]);
    if(middle > start) {
        this->build_tree_from_sorted_array_(node->left, array, start, middle-1);
    }
    if(middle < end) {
        this->build_tree_from_sorted_array_(node->right, array, middle+1, end);
    }
};

template<class T>
Node<T> *BST<T>::merge_(Node<T> *node_1, Node<T> *node_2) {
    if (node_1 == NULL) {
        return new Node<T>(*node_2);
    }
    if (node_2 == NULL) {
        return new Node<T>(*node_1);
    }
    Node<T> *node = new Node<T>(node_1->data);
    if (node_1->left != NULL)
        node->left = new Node<T>(*node_1->left);
    node->right = this->merge_(node_1->right, node_2);
    return node;
};
