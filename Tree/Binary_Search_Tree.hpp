#pragma once
#include <iostream>

// ���ݽṹ����
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

/* ���캯�� */
template<class T>
BinarySearchTree<T>::BinarySearchTree(T element) {
    this->data = element;
    this->lchild = NULL;
    this->rchild = NULL;
}

/* �������� */
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete this->lchild;
    delete this->rchild;
}

/* �ڶ����������в���һ������Ԫ�أ���������Ϊ�գ����½����ڵ� */
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
    else if (x > T->data) { // �����������в��������ظ�Ԫ��
        if (T->rchild) {
            T->rchild = insertData(x, T->rchild);
        }
        else {
            T->rchild = new BinarySearchTree(x);
        }
    }
    return T;
}

/* �������������������� */
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

/* �ڶ���������T�в�����Сֵ�����ظý�� */
template<class T>
BinarySearchTree<T>* BinarySearchTree<T>::findMin() {
    if (this->lchild == NULL) return this;
    else return this->lchild->findMin();
}

/* �ڶ���������T�в������ֵ�����ظý�� */
template<class T>
BinarySearchTree<T>* BinarySearchTree<T>::findMax() {
    if (this->rchild == NULL) return this;
    else return this->rchild->findMax();
}

/* �ڶ���������T�в���ָ������Ԫ�أ���δ�ҵ����򷵻�NULL */
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

/* �ڶ���������T��ɾ��ָ��Ԫ�صĽ��,��ɾ���ɹ��򷵻ظý�㣬���򷵻�NULL */
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