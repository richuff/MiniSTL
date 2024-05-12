#pragma once
#include "LinkList.hpp"


template<class T>
class Stack_linklist
{
public:
	/*构造函数*/
	Stack_linklist(int len);

	/*析构函数*/
	~Stack_linklist();

	/*获取长度*/
	int StackSizeLinkList();

	/*获取栈顶元素*/
	T StackTopLinkList();

	/*判断栈为空栈*/
	bool StackEmptyLinkList();

	/*入栈*/
	void StackPushLinkList(T val);

	/*出栈*/
	void StackPopLinkList();

	/*打印栈*/
	void StackPrintLinkList();
private:
	int len;
	LinkList<T>* Linklist;
};


/*获取栈大小*/
template<class T>
int Stack_linklist<T>::StackSizeLinkList()
{
	return this->len;
}

/*获取栈顶元素*/
template<class T>
T Stack_linklist<T>::StackTopLinkList()
{
	return this->Linklist->getvalLinkList(this->Linklist,this->len - 1);
}

/*构造函数*/
template<class T>
Stack_linklist<T>::Stack_linklist(int len)
{
	this->len = len;
	this->Linklist = new LinkList<T>(len);
}

/*析构函数*/
template<class T>
Stack_linklist<T>::~Stack_linklist()
{
	free(this->Linklist);
}

/*判断栈为空栈*/
template<class T>
bool Stack_linklist<T>::StackEmptyLinkList()
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
void Stack_linklist<T>::StackPushLinkList(T val)
{
	std::cout << "入栈" << std::endl;
	this->Linklist->InsertValue(this->Linklist,len+1,val);
	this->len++;
}

/*出栈*/
template<class T>
void Stack_linklist<T>::StackPopLinkList()
{
	std::cout << "出栈" << std::endl;
	this->Linklist->deleteLinkListbyid(this->Linklist,len);
}

/*打印栈*/
template<class T>
void Stack_linklist<T>::StackPrintLinkList()
{
	this->Linklist->LinkListprint();
}