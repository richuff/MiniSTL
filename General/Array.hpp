#pragma once
#include "OutOfIndexException.h"

template<class T>
class Array
{
public:
	~Array();

	Array(int len);

	Array(int len, T val);

	/*获取数组长度*/
	int GetLength();

	/*打印数组*/
	void PrintArray();

	/*头插*/
	void InsertBefore(T val);

	/*尾插*/
	void InsertEnd(T val);

	/*求和*/
	int ArrayCount();

	/*删除指定节点*/
	void ArrayDelete(int index);


	//清空数组
	void ClearArray();

	//交换两索引上的数
	void ExchangeArrayById(T n1,T n2);

	//反转数组
	void ReverseArray();

	//按一定顺序打印数组
	void PrintArrayFromTo(int front, int rear);

	const T& operator[](size_t index) const;

	T& operator[](size_t index);

	/*获得该位置的值*/
	//T ArrayGetById(int n);
	//修改指定索引的值
	//void ChangeValue(int index,T value);

private:
	int len;
	T* arr;
};


//析构函数
template<class T>
Array<T>::~Array()
{
	free(this->arr);
}

//构造函数
template<class T>
Array<T>::Array(int len)
{
	//处理异常情况  创建的长度小于1
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

//构造器
template<class T>
Array<T>::Array(int len, T val)
{
	//处理异常情况  创建的长度小于1
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

/*获取数组长度*/
template<class T>
int Array<T>::GetLength()
{
	return this->len;
}

/*打印数组*/
template<class T>
void Array<T>::PrintArray()
{
	if (this->arr == NULL) return;
	for (int i = 0; i < this->len; i++)
	{
		std::cout << this->arr[i] << std::endl;
	}
}

/*打印数组按照一定的顺序*/
template<class T>
void Array<T>::PrintArrayFromTo(int front,int rear)
{
	if (this->arr == NULL) return;
	for (int i = front; i % this->len < rear; i++)
	{
		std::cout << this->arr[i % this->len] << std::endl;
	}
}

/*头插*/
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

/*尾插*/
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


/*求和*/
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

/*删除指定节点*/
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


//清空数组
template<class T>
void Array<T>::ClearArray()
{
	this->len = 0;
	free(arr);
	this->arr = NULL;
}

//交换两索引上的数
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

//反转数组
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

///*获得该位置的值*/
//template<class T>
//T Array<T>::ArrayGetById(int n)
//{
//	if (this->arr == NULL || this->len < n + 1) return INT_MIN;
//	return this->arr[n];
//}
////修改指定索引的值
//template<class T>
//void Array<T>::ChangeValue(int index, T value) {
//	this->arr[index] = value;
//}