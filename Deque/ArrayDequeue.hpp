#pragma once
#include "Array.hpp"

template<class T>
class ArrayDequeue {
public:
	ArrayDequeue(int len);
	ArrayDequeue(int len, T res);
	~ArrayDequeue();

	/*��ȡ����*/
	int DequeSizeLinkList();

	/*��ȡ��ͷԪ��*/
	T DequeTopLinkList();

	/*��ȡ��βԪ��*/
	T DequeBottomLinkList();

	/*�ж�ջΪ�ն���*/
	bool DequeEmptyLinkList();

	/*���*/
	void DeuqePushLinkList(T val);

	/*����*/
	T DequePopLinkList();

	/*��ӡ����*/
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

//��ȡ���еĳ���
template<class T>
int ArrayDequeue<T>::DequeSizeLinkList() {
	return (this->rear - this->front + this->MAXNUM)%this->MAXNUM;
}

//��ȡ��ͷԪ��
template<class T>
T ArrayDequeue<T>::DequeTopLinkList() {
	return this->array->ArrayGetById((this->front)%this->MAXNUM);
}


//��ȡ�ӵ�Ԫ��
template<class T>
T ArrayDequeue<T>::DequeBottomLinkList() {
	return this->array->ArrayGetById((this->rear-1 + this->MAXNUM)%this->MAXNUM);
}

//�ж��Ƿ�Ϊ�ն���
template<class T>
bool ArrayDequeue<T>::DequeEmptyLinkList() {
	if (this == NULL) return false;
	if (this->front == this->rear) {
		return true;
	}
	return false;
}

//��ӡ����
template<class T>
void ArrayDequeue<T>::DequePrintLinkList() {
	this->array->PrintArrayFromTo(this->front,this->rear);
}

//����
template<class T>
T ArrayDequeue<T>::DequePopLinkList() {
	int res = this->array->ArrayGetById(this->front);
	this->array->ChangeValue(this->front, 0);
	this->front = (this->front + 1) % this->MAXNUM;
	return res;
}

//���
template<class T>
void ArrayDequeue<T>::DeuqePushLinkList(T value) {
	this->array->ChangeValue(this->rear,value);
	this->rear = (this->rear + 1) % this->MAXNUM;
}
