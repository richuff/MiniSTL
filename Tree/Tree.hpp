#pragma once
#include "Array.hpp"
#include "LinkList_Stack.hpp"

template<class T>
class Tree {
public:
	Tree(T value,Array<Tree*> child);
	~Tree();
	Array<Tree<T>*> TreeTraverse();
private:
	T val;
	Array<Tree*> child;
};

//构造函数
template<class T>
Tree<T>::Tree(T value, Array<Tree*> child) {
	this->child = child;
	this->val = value;
}

//析构函数
template<class T>
Tree<T>::~Tree() {
	delete this->val;
	delete this->child;
}

//层序遍历
template<class T>
Array<Tree<T>*> Tree<T>::TreeTraverse() {
	
}

void dfs() {

}