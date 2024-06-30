#pragma once
#include "LinkList.hpp"

template<class T>
class deque {
public:
	deque(int len);
	deque(int len,T res);
	~deque();

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
	void DequePopLinkList();

	/*打印队列*/
	void DequePrintLinkList();
private:
	int len;
	LinkList<T>* Linklist;
};

template<class T>
deque<T>::deque(int len) {
	this->Linklist = new LinkList<T>(len,0);
}

template<class T>
deque<T>::deque(int len,T res) {
	this->len = len;
	this->Linklist = new LinkList<T>(len, res);
}

template<class T>
deque<T>::~deque() {
	delete this->Linklist;
}

//获取队列的长度
template<class T>
int deque<T>::DequeSizeLinkList() {
	return this->len;
}

//获取队头元素
template<class T>
T deque<T>::DequeTopLinkList() {
	return this->Linklist->getvalLinkList(this->Linklist, this->len);
}


//获取队底元素
template<class T>
T deque<T>::DequeBottomLinkList() {
	return this->Linklist->getvalLinkList(this->Linklist, 0);
}

//判断是否为空队列
template<class T>
bool deque<T>::DequeEmptyLinkList() {
	if (this->len != 0) {
		return false;
	}
	else {
		return true;
	}
}

//打印队列
template<class T>
void deque<T>::DequePrintLinkList() {
	this->Linklist->LinkListprint();
}

//出队
template<class T>
void deque<T>::DequePopLinkList() {
	this->Linklist = this->Linklist->popLinkList(this->Linklist);
	this->len = this->len - 1;
}

//入队
template<class T>
void deque<T>::DeuqePushLinkList(T value) {
	this->Linklist = this->Linklist->InsertValue(this->Linklist, this->len+1, value);
	this->len = this->len + 1;
}
