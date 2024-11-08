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
    if (this->curNum == 0) return '#';
    return this->ele[0];
}

/*�������T��ָ�����ch��˫�׽�㣬����ֵ��˫�׽����±꣬��˫�ײ����ڣ�����-1*/
template<class T>
int Tree<T>::parent(char ch)
{
    int res = 0;
    for (int i = 0; i < this->curNum; i++) {
        if (this->ele[i] == ch) {
            res = (i - 3) / 2;
        }
    }
    if (res < 0 || this->ele[res] == ' ') {
        return -1;
    }
    return res;
}

/*�������T��ָ�����ch�����ӵ��±꣬�����Ӳ����ڣ�����-1*/
template<class T>
int Tree<T>::leftChild(char ch)
{
    int res = 0;
    for (int i = 0; i < this->curNum; i++) {
        if (this->ele[i] == ch) {
            res = 2 * i + 1;
        }
    }
    if (res > this->curNum || this->ele[res - 1] == ' ') {
        return -1;
    }
    return res;
}

/*�������T��ָ�����ch���Һ��ӵ��±꣬�����Ӳ����ڣ�����-1*/
template<class T>
int Tree<T>::rightChild(char ch)
{
    int res = 0;
    for (int i = 0; i < this->curNum; i++) {
        if (this->ele[i] == ch) {
            res = 2 * i + 2;
        }
    }
    if (res > this->curNum) {
        return -1;
    }
    return res;
}

/*�����������������������õ��Ľ��*/
template<class T>
void Tree<T>::levelOrder()
{
    for (int i = 0; i < this->curNum; i++) {
        if (this->ele[i] != ' ') {
            printf("%c ", this->ele[i]);
        }
    }
}

/*�����������������������õ��Ľ��*/
template<class T>
void Tree<T>::preOrder() {
    static int index = 0;


    int currentIndex = index;


    if (currentIndex < this->curNum && this->ele[currentIndex] != ' ') {

        printf("%c", this->ele[currentIndex]);

        index = 2 * currentIndex + 1;
        preOrder();

        index = 2 * currentIndex + 2;
        preOrder();
    }

    index = currentIndex;
}