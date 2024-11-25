#pragma once
#include <iostream>

// 数据结构定义
template<class T>
class BinarySearchTree {
private:
    T data;
    BinarySearchTree* lchild, * rchild;
public:
    BinarySearchTree(T element);
    ~BinarySearchTree();
    BinarySearchTree<T>* insertData(T x, BinarySearchTree<T>* T);
    void preOrder(BinarySearchTree<T>* T);
    void inOrder(BinarySearchTree<T>* T);
    BinarySearchTree<T>* findMin();
    BinarySearchTree<T>* findMax();
    BinarySearchTree<T>* findData(T element);
    BinarySearchTree<T>* deleteData(T element);
};

/* 构造函数 */
template<class T>
BinarySearchTree<T>::BinarySearchTree(T element) {
    this->data = element;
    this->lchild = NULL;
    this->rchild = NULL;
}

/* 析构函数 */
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete this->lchild;
    delete this->rchild;
}

/* 在二叉排序树中插入一个数据元素，若二叉树为空，则新建根节点 */
template<class T>
BinarySearchTree<T>* BinarySearchTree<T>::insertData(T x, BinarySearchTree<T>* T) {
    if (T == NULL) {
        return new BinarySearchTree(x);
    }
    if (x < T->data) {
        if (T->lchild) {
            T->lchild = insertData(x, T->lchild);
        }
        else {
            T->lchild = new BinarySearchTree(x);
        }
    }
    else if (x > T->data) { // 二叉搜索树中不允许有重复元素
        if (T->rchild) {
            T->rchild = insertData(x, T->rchild);
        }
        else {
            T->rchild = new BinarySearchTree(x);
        }
    }
    return T;
}

/* 先序遍历和中序遍历函数 */
template<class T>
void BinarySearchTree<T>::preOrder(BinarySearchTree<T>* T) {
    if (T == NULL) return;
    std::cout << T->data << " ";
    preOrder(T->lchild);
    preOrder(T->rchild);
}

template<class T>
void BinarySearchTree<T>::inOrder(BinarySearchTree<T>* T) {
    if (T == NULL) return;
    inOrder(T->lchild);
    std::cout << T->data << " ";
    inOrder(T->rchild);
}

/* 在二叉排序树T中查找最小值，返回该结点 */
template<class T>
BinarySearchTree<T>* BinarySearchTree<T>::findMin() {
    if (this->lchild == NULL) return this;
    else return this->lchild->findMin();
}

/* 在二叉排序树T中查找最大值，返回该结点 */
template<class T>
BinarySearchTree<T>* BinarySearchTree<T>::findMax() {
    if (this->rchild == NULL) return this;
    else return this->rchild->findMax();
}

/* 在二叉排序树T中查找指定数据元素，若未找到，则返回NULL */
template<class T>
BinarySearchTree<T>* BinarySearchTree<T>::findData(T element) {
    if (this == NULL) return NULL;
    if (element < this->data) {
        return this->lchild ? this->lchild->findData(element) : NULL;
    }
    else if (element > this->data) {
        return this->rchild ? this->rchild->findData(element) : NULL;
    }
    else
        return this;
}

/* 在二叉排序树T中删除指定元素的结点,若删除成功则返回该结点，否则返回NULL */
template<class T>
BinarySearchTree<T>* BinarySearchTree<T>::deleteData(T element) {
    BinarySearchTree<T>* p = this, * parent = NULL, * s = NULL, * temp = NULL;
    if (p == NULL) return NULL;
    if (p->data == element) {
        if (p->lchild != NULL && p->rchild != NULL) {
            s = p->rchild;
            parent = p;
            while (s->lchild != NULL) {
                parent = s;
                s = s->lchild;
            }
            p->data = s->data;
            if (parent != p) {
                parent->lchild = s->rchild;
            }
            else {
                parent->rchild = s->rchild;
            }
            delete s;
        }
        else {
            if (p->lchild == NULL) {
                temp = p->rchild;
                delete p;
            }
            else if (p->rchild == NULL) {
                temp = p->lchild;
                delete p;
            }
            else {
                temp = NULL;
            }
            p = temp;
        }
    }
    else if (element < p->data) {
        p->lchild = p->lchild ? p->lchild->deleteData(element) : NULL;
    }
    else {
        p->rchild = p->rchild ? p->rchild->deleteData(element) : NULL;
    }
    return p;
}