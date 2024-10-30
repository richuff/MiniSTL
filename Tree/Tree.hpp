#pragma once
#include <stdlib.h>
template<class T>
class Tree{
public: 
    Tree();
    ~Tree();
    void printTree();
    char root();
    int parent(char ch);
    int leftChild(char ch);
    int rightChild(char ch);
    void levelOrder();
    void preOrder();
public:
    int MAXNUM;
    int curNum;
    T* ele;
};

//构造函数
template<class T>
Tree<T>::Tree() {
    this->MAXNUM = 10;
    this->curNum = 0;
    this->ele = (char*)malloc(10);
    char c;
    while ((c = getchar()) != '\n') {
        this->ele[this->curNum] = c;
        this->curNum++;
    }
}

//析构函数
template<class T>
Tree<T>::~Tree() {
    delete this->MAXNUM;
    delete this->curNum;
    delete this->ele;
}

//逐个输出顺序表的元素
template<class T>
void Tree<T>::printTree()
{
    for (int i = 0; i < this->curNum; i++) {
        printf("%c ", this->ele[i]);
    }
}

//求根节点的元素，不存在返回#
template<class T>
char Tree<T>::root()
{
    if (this->curNum == 0) return "#";
    return this->ele[0];
}

/*求二叉树T中指定结点ch的双亲结点，返回值是双亲结点的下标，若双亲不存在，则返回-1*/
template<class T>
int Tree<T>::parent(char ch)
{
    int res = 0;
    for (int i = 0; i < T->curNum; i++) {
        if (T->ele[i] == ch) {
            res = (i - 3) / 2;
        }
    }
    if (res < 0 || T->ele[res] == ' ') {
        return -1;
    }
    return res;
}

/*求二叉树T中指定结点ch的左孩子的下标，若左孩子不存在，则返回-1*/
template<class T>
int Tree<T>::leftChild(char ch)
{
    int res;
    for (int i = 0; i < T->curNum; i++) {
        if (T->ele[i] == ch) {
            res = 2 * i + 1;
        }
    }
    if (res > T->curNum || T->ele[res - 1] == ' ') {
        return -1;
    }
    return res;
}

/*求二叉树T中指定结点ch的右孩子的下标，若左孩子不存在，则返回-1*/
template<class T>
int Tree<T>::rightChild(char ch)
{
    int res;
    for (int i = 0; i < T->curNum; i++) {
        if (T->ele[i] == ch) {
            res = 2 * i + 2;
        }
    }
    if (res > T->curNum) {
        return -1;
    }
    return res;
}

/*层序遍历二叉树，输出遍历得到的结点，结点之间不需要空格*/
template<class T>
void Tree<T>::levelOrder()
{
    for (int i = 0; i < T->curNum; i++) {
        if (T->ele[i] != ' ') {
            printf("%c", T->ele[i]);
        }
    }
}

/*先序遍历二叉树，输出遍历得到的结点，结点之间不需要空格*/
template<class T>
void Tree<T>::preOrder() {
    static int index = 0;


    int currentIndex = index;


    if (currentIndex < T->curNum && T->ele[currentIndex] != ' ') {

        printf("%c", T->ele[currentIndex]);

        index = 2 * currentIndex + 1;
        preOrder(T);

        index = 2 * currentIndex + 2;
        preOrder(T);
    }

    index = currentIndex;
}