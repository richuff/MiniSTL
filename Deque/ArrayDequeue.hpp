#pragma once
#include "Array.hpp"

template<class T>
class ArrayDequeue {
public:
	ArrayDequeue(int len);
	ArrayDequeue(int len, T res);
	~ArrayDequeue();

	/*获取长度*/
	int DequeSizeLinkList();

	/*获取队头元素*/
	T DequeTopLinkList();

	/*获取队尾元素*/
	T DequeBottomLinkList();

	/*判断栈为空队列*/
	bool DequeEmptyLinkList();

	/*入队*/
	void DeuqePushLinkList(T val);

	/*出队*/
	T DequePopLinkList();

	/*打印队列*/
	void DequePrintLinkList();
private:
	int front,rear;
	int MAXNUM;
	Array<T>* array;
};

template<class T>
ArrayDequeue<T>::ArrayDequeue(int len) {
	this->MAXNUM = len;
	this->array = new Array<T>(len);
	this->front = 0;
	this->rear = 0;
}

template<class T>
ArrayDequeue<T>::ArrayDequeue(int len, T res) {
	this->MAXNUM = len;
	this->array = new Array<T>(len, res);
	this->front = 0;
	this->rear = 0;
}

template<class T>
ArrayDequeue<T>::~ArrayDequeue() {
	delete this->array;
}

//获取队列的长度
template<class T>
int ArrayDequeue<T>::DequeSizeLinkList() {
	return (this->rear - this->front + this->MAXNUM)%this->MAXNUM;
}

//获取队头元素
template<class T>
T ArrayDequeue<T>::DequeTopLinkList() {
	return this->array->ArrayGetById((this->front)%this->MAXNUM);
}


//获取队底元素
template<class T>
T ArrayDequeue<T>::DequeBottomLinkList() {
	return this->array->ArrayGetById((this->rear-1 + this->MAXNUM)%this->MAXNUM);
}

//判断是否为空队列
template<class T>
bool ArrayDequeue<T>::DequeEmptyLinkList() {
	if (this == NULL) return false;
	if (this->front == this->rear) {
		return true;
	}
	return false;
}

//打印队列
template<class T>
void ArrayDequeue<T>::DequePrintLinkList() {
	this->array->PrintArrayFromTo(this->front,this->rear);
}

//出队
template<class T>
T ArrayDequeue<T>::DequePopLinkList() {
	int res = this->array->ArrayGetById(this->front);
	this->array->ChangeValue(this->front, 0);
	this->front = (this->front + 1) % this->MAXNUM;
	return res;
}

//入队
template<class T>
void ArrayDequeue<T>::DeuqePushLinkList(T value) {
	this->array->ChangeValue(this->rear,value);
	this->rear = (this->rear + 1) % this->MAXNUM;
}
