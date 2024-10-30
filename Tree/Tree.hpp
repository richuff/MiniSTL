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

//���캯��
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

//��������
template<class T>
Tree<T>::~Tree() {
    delete this->MAXNUM;
    delete this->curNum;
    delete this->ele;
}

//������˳����Ԫ��
template<class T>
void Tree<T>::printTree()
{
    for (int i = 0; i < this->curNum; i++) {
        printf("%c ", this->ele[i]);
    }
}

//����ڵ��Ԫ�أ������ڷ���#
template<class T>
char Tree<T>::root()
{
    if (this->curNum == 0) return "#";
    return this->ele[0];
}

/*�������T��ָ�����ch��˫�׽�㣬����ֵ��˫�׽����±꣬��˫�ײ����ڣ��򷵻�-1*/
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

/*�������T��ָ�����ch�����ӵ��±꣬�����Ӳ����ڣ��򷵻�-1*/
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

/*�������T��ָ�����ch���Һ��ӵ��±꣬�����Ӳ����ڣ��򷵻�-1*/
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

/*�����������������������õ��Ľ�㣬���֮�䲻��Ҫ�ո�*/
template<class T>
void Tree<T>::levelOrder()
{
    for (int i = 0; i < T->curNum; i++) {
        if (T->ele[i] != ' ') {
            printf("%c", T->ele[i]);
        }
    }
}

/*�����������������������õ��Ľ�㣬���֮�䲻��Ҫ�ո�*/
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