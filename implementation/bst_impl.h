//IMPLEMENTATION
#include "../class/bst.h"

//PUBLIC
template<class T>
BST<T>::BST() {
}

template<class T>
BST<T>::BST(T*) {

}

template<class T>
BST<T>::~BST() {
    if (this->_root != NULL)
        delete this->_root;
}

template<class T>
T *BST<T>::search(T value) {
    return this->_search(this->_root, value);
}

template<class T>
void BST<T>::insert(T value) {
    this->_insert(this->_root, value);
}

template<class T>
bool BST<T>::remove(T value) {
    return this->_remove(this->_root, value);
}

template<class T>
bool BST<T>::isBST() {
    return this->_isBST(this->_root);
};


template<class T>
void BST<T>::preOrder(void (*f)(T &value)){
    this->_preOrder(this->_root, f);
};

template<class T>
void BST<T>::inOrder(void (*f)(T &value)) {
    this->_inOrder(this->_root, f);
};

template<class T>
void BST<T>::postOrder(void (*f)(T &value)){
    this->_postOrder(this->_root, f);
};


//PRIVATE
template<class T>
T* BST<T>::_search(Node<T> *node, T &value) {
    if (node == NULL)
        return NULL;
    if (node->data == value)
        return &node->data;
    if (node->data < value)
        return this->_search(node->right, value);
    else
        return this->_search(node->left, value);
}

template<class T>
void BST<T>::_insert(Node<T> *&node, T &value) {
    if (node == NULL) {
        node = new Node<T>(value);
    } else if (value < node->data) {
        this->_insert(node->left, value);
    } else {
        this->_insert(node->right, value);
    }
};

template<class T>
bool BST<T>::_remove(Node<T> *node, T &value, Node<T> *parent) {
    bool ret = false;
    if (node != NULL) {
        if (node->data == value) {
            if (node->left != NULL && node->right != NULL) {
                Node<T> *subNode = node->right;
                while (subNode->left != NULL) {
                    subNode = subNode->left;
                }
                T tmpValue = node->data;
                node->data = subNode->data;
                subNode->data = tmpValue;
                ret = this->_remove(node->right, value, node);
            } else {
                Node<T> *newNode = node->left;
                if (node->right != NULL) newNode = node->right;
                if (parent != NULL) {
                    if (parent->left == node)
                        parent->left = newNode;
                    else
                        parent->right = newNode;
                } else {
                    this->_root = newNode;
                }
                node->left = NULL;
                node->right = NULL;
                delete node;
                ret = true;
            }
        } else {
            if (node->data < value) {
                ret = this->_remove(node->right, value, node);
            } else {
                ret = this->_remove(node->left, value, node);
            }
        }
    }
    return ret;
}
template<class T>
bool BST<T>::_isBST(Node<T> *node) {
    bool ret = true;
    if(node != NULL) {
        if(node->left != NULL) {
            ret = node->left->data < node->data;
            if(ret)
                ret = this->_isBST(node->left);
        }
        if(ret && node->right != NULL) {
            ret = node->data < node->right->data;
            if(ret)
                ret = this->_isBST(node->right);
        }
    }
    return ret;
};


template<class T>
void BST<T>::_preOrder(Node<T>* node, void(*f)(T &value)) {
    if(node != NULL) {
        f(node->data);
        this->_preOrder(node->left, f);
        this->_preOrder(node->right, f);
    }
};

template<class T>
void BST<T>::_inOrder(Node<T>* node, void(*f)(T &value)) {
    if(node != NULL) {
        this->_inOrder(node->left, f);
        f(node->data);
        this->_inOrder(node->right, f);
    }
};

template<class T>
void BST<T>::_postOrder(Node<T>* node, void(*f)(T &value)) {
    if(node != NULL) {
        this->_postOrder(node->left, f);
        this->_postOrder(node->right, f);
        f(node->data);
    }
};
