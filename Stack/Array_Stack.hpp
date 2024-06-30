#pragma once
#include "Array.hpp"


template<class T>
class Array_Stack
{
public:
	/*构造函数*/
	Array_Stack(int len);

	/*析构函数*/
	~Array_Stack();

	/*获取长度*/
	int StackSize();

	/*获取栈顶元素*/
	T StackTop();

	/*判断栈为空栈*/
	bool StackEmpty();

	/*入栈*/
	void StackPush(T val);

	/*出栈*/
	void StackPop();

	/*打印栈*/
	void StackPrint();
private:
	int len;
	Array<T>* array;
};


/*获取栈顶元素*/
template<class T>
int Array_Stack<T>::StackSize()
{
	return this->len;
}

/*获取栈顶元素*/
template<class T>
T Array_Stack<T>::StackTop()
{
	return array->ArrayGetById(this->len);
}

/*构造函数*/
template<class T>
Array_Stack<T>::Array_Stack(int len)
{
	this->len = len;
	this->array = new Array<T>(len);
}

/*析构函数*/
template<class T>
Array_Stack<T>::~Array_Stack()
{
	free(this->array);
}

/*判断栈为空栈*/
template<class T>
bool Array_Stack<T>::StackEmpty()
{
	if (this->len == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*入栈*/
template<class T>
void Array_Stack<T>::StackPush(T val)
{
	std::cout << "入栈" << std::endl;
	this->array->InsertEnd(val);
	++this->len;
}

/*出栈*/
template<class T>
void Array_Stack<T>::StackPop()
{
	std::cout << "出栈" << std::endl;
	this->array->ArrayDelete(this->len-1);
}

/*打印栈*/
template<class T>
void Array_Stack<T>::StackPrint()
{
	this->array->PrintArray();
}