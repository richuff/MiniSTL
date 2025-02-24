#pragma once
#include "OutOfIndexException.h"

template<class T>
class Array
{
public:
	~Array();

	Array(int len);

	Array(int len, T val);

	/*��ȡ���鳤��*/
	int GetLength();

	/*��ӡ����*/
	void PrintArray();

	/*ͷ��*/
	void InsertBefore(T val);

	/*β��*/
	void InsertEnd(T val);

	/*���*/
	int ArrayCount();

	/*ɾ��ָ���ڵ�*/
	void ArrayDelete(int index);


	//�������
	void ClearArray();

	//�����������ϵ���
	void ExchangeArrayById(T n1,T n2);

	//��ת����
	void ReverseArray();

	//��һ��˳���ӡ����
	void PrintArrayFromTo(int front, int rear);

	const T& operator[](size_t index) const;

	T& operator[](size_t index);

	/*��ø�λ�õ�ֵ*/
	//T ArrayGetById(int n);
	//�޸�ָ��������ֵ
	//void ChangeValue(int index,T value);

private:
	int len;
	T* arr;
};


//��������
template<class T>
Array<T>::~Array()
{
	free(this->arr);
}

//���캯��
template<class T>
Array<T>::Array(int len)
{
	//�����쳣���  �����ĳ���С��1
	if (len <= 0) {
		len = 1;
	}

	this->len = len;
	this->arr = (T*)malloc(sizeof(T) * (static_cast<unsigned long long>(len) + 2));
	if (arr != NULL)
	{
		for (int j = 0; j < len; j++)
		{
			this->arr[j] = 0;
		}
	}
}

//������
template<class T>
Array<T>::Array(int len, T val)
{
	//�����쳣���  �����ĳ���С��1
	if (len <= 0) {
		len = 1;
	}

	this->len = len;
	this->arr = (T*)malloc(sizeof(T) * (static_cast<unsigned long long>(len) + 2));
	if (arr != NULL)
	{
		for (int j = 0; j < len; j++)
		{
			this->arr[j]=val;
		}
	}
}

template<class T>
const T& Array<T>::operator[](size_t index) const {
	if (index < 0 || index >= len) {
		throw OutOfIndexException("out of index");
	}
	return this->arr[index];
}

template<class T>
T& Array<T>::operator[](size_t index) {
	if (index < 0 || index >= len) {
		throw OutOfIndexException("out of index");
	}
	return this->arr[index];
}

/*��ȡ���鳤��*/
template<class T>
int Array<T>::GetLength()
{
	return this->len;
}

/*��ӡ����*/
template<class T>
void Array<T>::PrintArray()
{
	if (this->arr == NULL) return;
	for (int i = 0; i < this->len; i++)
	{
		std::cout << this->arr[i] << std::endl;
	}
}

/*��ӡ���鰴��һ����˳��*/
template<class T>
void Array<T>::PrintArrayFromTo(int front,int rear)
{
	if (this->arr == NULL) return;
	for (int i = front; i % this->len < rear; i++)
	{
		std::cout << this->arr[i % this->len] << std::endl;
	}
}

/*ͷ��*/
template<class T>
void Array<T>::InsertBefore(T val)
{
	this->len++;
	T* tem = (T*)malloc(sizeof(T) * (static_cast<unsigned long long>(this->len) + 2));
	tem[0] = val;
	for (int i = 1; i < this->len; i++)
	{
		tem[i] = this->arr[i - 1];
	}
	this->arr = tem;
}

/*β��*/
template<class T>
void Array<T>::InsertEnd(T val)
{
	this->len++;
	T* tem = (T*)malloc(sizeof(T) * (static_cast<unsigned long long>(this->len + 2)));
	if (tem != NULL)
	{
		for (int i = 0; i < len; i++)
		{
			tem[i] = this->arr[i];
		}
		tem[len - 1] = val;
		this->arr = tem;
	}
}


/*���*/
template<class T>
int Array<T>::ArrayCount()
{
	if (this->arr == NULL) return -1;
	int count = 0;
	for (int i = 0; i < this->len; i++)
	{
		count += this->arr[i];
	}
	return count;
}

/*ɾ��ָ���ڵ�*/
template<class T>
void Array<T>::ArrayDelete(int index)
{
	if (index < 0 || index >= len) {
		throw OutOfIndexException("out of index");
	}
	if (this->arr == NULL) return;
	for (int i = index; i < this->len-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	this->len--;
}


//�������
template<class T>
void Array<T>::ClearArray()
{
	this->len = 0;
	free(arr);
	this->arr = NULL;
}

//�����������ϵ���
template<class T>
void Array<T>::ExchangeArrayById(T indexo, T indext)
{
	if (this->arr == NULL) return;
	if (indexo < 0 || indexo >= len || indext < 0 || indext >= len) {
		throw OutOfIndexException("out of index");
	}
	this -> arr[indexo] = this -> arr[indexo] + this -> arr[indext];
	this -> arr[indext] = this -> arr[indexo] - this -> arr[indext];
	this -> arr[indexo] = this -> arr[indexo] - this -> arr[indext];
}

//��ת����
template<class T>
void Array<T>::ReverseArray()
{
	T* tem = (T*)malloc(sizeof(T) * (static_cast<unsigned long long>(this->len) + 2));
	if (tem != NULL)
	{
		for (int i = this->len - 1; i >= 0; i--)
		{
			tem[len - 1 - i] = this->arr[i];
		}
		this->arr = tem;
	}
	else
	{
		return;
	}
}

///*��ø�λ�õ�ֵ*/
//template<class T>
//T Array<T>::ArrayGetById(int n)
//{
//	if (this->arr == NULL || this->len < n + 1) return INT_MIN;
//	return this->arr[n];
//}
////�޸�ָ��������ֵ
//template<class T>
//void Array<T>::ChangeValue(int index, T value) {
//	this->arr[index] = value;
//}