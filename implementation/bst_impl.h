//IMPLEMENTATION
#include "../class/bst.h"

//PUBLIC

template<typename T>
BST<T>::BST() : root_(NULL) {
}

template<typename T>
BST<T>::BST(T array[], size_t length) {
    build_tree_from_sorted_array_(root_, array, 0, length-1);
}

template<typename T>
BST<T>::~BST() {
    delete root_;
}

template<typename T>
T *BST<T>::search(T value) const {
    return search_(root_, value);
}

template<typename T>
void BST<T>::insert(T value) {
    insert_(root_, value);
}

template<typename T>
bool BST<T>::remove(T value) {
    return remove_(root_, value);
}

template<typename T>
bool BST<T>::is_bst() const {
    return is_bst_(root_);
};


template<typename T>
void BST<T>::pre_order(void (*f)(T &value)) const {
    pre_order_(root_, f);
};

template<typename T>
void BST<T>::in_order(void (*f)(T &value)) const {
    in_order_(root_, f);
};

template<typename T>
void BST<T>::post_order(void (*f)(T &value)) const {
    post_order_(root_, f);
};

template<typename T>
BST<T> *BST<T>::operator+(const BST<T> &tree) {
    BST<T> *bst = new BST<T>();
    merge_(bst->root_, root_, tree.root_);
    return bst;
};

//PROTECTED

template<typename T>
T* BST<T>::search_(Node *node, T &value) const {
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
void BST<T>::insert_(Node *&node, T &value) {
    if (node == NULL) {
        node = new Node(value);
    } else if (value < node->data) {
        insert_(node->left, value);
    } else {
        insert_(node->right, value);
    }
};

template<typename T>
bool BST<T>::remove_(Node *node, T &value, Node *parent) {
    bool ret = false;
    if (node != NULL) {
        if (node->data == value) {
            if (node->left != NULL && node->right != NULL) {
                Node *sub_node = node->right;
                while (sub_node->left != NULL) {
                    sub_node = sub_node->left;
                }
                T tmp_value = node->data;
                node->data = sub_node->data;
                sub_node->data = tmp_value;
                ret = remove_(node->right, value, node);
            } else {
                Node *new_node = node->left;
                if (node->right != NULL) new_node = node->right;
                if (parent != NULL) {
                    if (parent->left == node)
                        parent->left = new_node;
                    else
                        parent->right = new_node;
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
                ret = remove_(node->right, value, node);
            } else {
                ret = remove_(node->left, value, node);
            }
        }
    }
    return ret;
}
template<typename T>
bool BST<T>::is_bst_(Node *node) const {
    bool ret = true;
    if(node != NULL) {
        if(node->left != NULL) {
            ret = node->left->data < node->data;
            if(ret)
                ret = is_bst_(node->left);
        }
        if(ret && node->right != NULL) {
            ret = node->data < node->right->data;
            if(ret)
                ret = is_bst_(node->right);
        }
    }
    return ret;
};


template<typename T>
void BST<T>::pre_order_(Node* node, void(*f)(T &value)) const {
    if(node != NULL) {
        f(node->data);
        pre_order_(node->left, f);
        pre_order_(node->right, f);
    }
};

template<typename T>
void BST<T>::in_order_(Node* node, void(*f)(T &value)) const {
    if(node != NULL) {
        in_order_(node->left, f);
        f(node->data);
        in_order_(node->right, f);
    }
};

template<typename T>
void BST<T>::post_order_(Node* node, void(*f)(T &value)) const {
    if(node != NULL) {
        post_order_(node->left, f);
        post_order_(node->right, f);
        f(node->data);
    }
};

template<typename T>
void BST<T>::build_tree_from_sorted_array_(Node *&node, T array[], size_t start, size_t end) {
    size_t middle = start + (end - start)/2;
    node = new Node(array[middle]);
    if(middle > start) {
        build_tree_from_sorted_array_(node->left, array, start, middle-1);
    }
    if(middle < end) {
        build_tree_from_sorted_array_(node->right, array, middle+1, end);
    }
};

template<typename T>
void BST<T>::merge_(Node *&node, Node *node_1, Node *node_2) {
    if (node_1 == NULL) {
        node = new Node(*node_2);
    } else if (node_2 == NULL) {
        node = new Node(*node_1);
    } else {
        node = new Node(node_1->data);
        if (node_1->left != NULL)
            node->left = new Node(*node_1->left);
        merge_(node->right, node_1->right, node_2);
    }
};

