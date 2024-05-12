#pragma once
#include <iostream>

template<class T>
class Array
{
public:
	/*构造器*/
	~Array();
	Array(int len);

	/*获取数组长度*/
	int Arraylength();

	/*打印数组*/
	void PrintArray();

	/*头插*/
	void InsertBefore(T val);

	/*尾插*/
	void InsertEnd(T val);

	/*求和*/
	int ArrayCount();

	/*删除指定节点*/
	void ArrayDelete(int n);

	/*获得该位置的值*/
	T ArrayGetById(int n);

	//清空数组
	void ClearArray();

	//交换两索引上的数
	void ExchangeArrayById(int n1,int n2);

	//反转数组
	void ReverseArray();
private:
	int len;
	T* arr;
};

//构造器
template<class T>
Array<T>::~Array()
{
	free(this->arr);
}

//析构函数
template<class T>
Array<T>::Array(int len)
{
	this->len = len;
	this->arr = (T*)malloc(sizeof(T) * (static_cast<unsigned long long>(len) + 2));
	if (arr != NULL)
	{
		for (int j = 0; j < len; j++)
		{
			std::cout << "请输入第" << j + 1 << "个元素" << std::endl;
			std::cin >> this->arr[j];
		}
	}
}

/*获取数组长度*/
template<class T>
int Array<T>::Arraylength()
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
		std::cout << "第" << i+1 << "个元素为";
		std::cout << this->arr[i] << std::endl;
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
void Array<T>::ArrayDelete(int n)
{
	if (this->arr == NULL) return;
	for (int i = n; i < this->len-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	this->len--;
}

/*获得该位置的值*/
template<class T>
T Array<T>::ArrayGetById(int n)
{
	if (this->arr == NULL || this->len < n + 1) return INT_MIN;
	return this->arr[n];
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
void Array<T>::ExchangeArrayById(int n1, int n2)
{
	if (this->arr == NULL || this->len < n1 + 1 || this->len < n2 + 1) return;
	this -> arr[n1] = this -> arr[n1] + this -> arr[n2];
	this -> arr[n2] = this -> arr[n1] - this -> arr[n2];
	this -> arr[n1] = this -> arr[n1] - this -> arr[n2];
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

