#pragma once

template<class T>
class LinkList
{
public:
	LinkList();

	LinkList(int len);

	LinkList(int len, T res);

	~LinkList();

	//创建链表头插法
	LinkList* CreatLinkList_head(int length);

	//创建指定长度，固定值的链表
	LinkList* CreateLinkListByNum(int length, T res);

	//创建链表尾插法
	LinkList* CreatLinkList_back(int length);

	//统计链表的长度
	int LinkListlength();

	//打印链表
	void LinkListprint();

	//遍历链表的函数
	//获得该位置的指针域
	LinkList* LinkListTraverse(int n);

	//插入一个结点
	//e为插入的位置,遍历到e-1的位置
	void InsertLinkList(int e);

	//获得指定索引的值
	T getvalLinkList(int e);

	//删除链表
	void DeleteLinkList();

	//合并链表
	void groupLinkList(LinkList* L2);

	//反转链表
	void reverseLinkList();

	//求和链表上的数
	T countLinkList();

	//交换两索引上的数
	void exchangeLinkList(int l1, int l2);

	//删除指定节点
	void deleteLinkListbyid(int l1);

	//在指定位置插入指定值
	void InsertValue(int e, T val);

	//头插入法
	void insertHead(T val);

	//尾插法
	void insertBack(T val);
private:
	T val;
	LinkList* Ln;
};

template<class T>
LinkList<T>::LinkList()
{
	this->val = 0;
	this->Ln = NULL;
}

//构造函数
template<class T>
LinkList<T>::LinkList(int len)
{
	if (len <= 0) {
		std::cout << "the linklist's length must greater than 0" << std::endl;
		return;
	}
	this->Ln=CreatLinkList_back(len);
}

//构造函数
template<class T>
LinkList<T>::LinkList(int length, T res) {
	this->Ln = CreateLinkListByNum(length, res);
}

template<class T>
LinkList<T>* LinkList<T>::CreateLinkListByNum(int length, T res) {
	//头结点
	LinkList* L1 = new LinkList();
	//头指针
	LinkList* p = L1;
	for (int i = length - 1; i >= 0; i--)
	{
		LinkList* temp = new LinkList();
		temp->val = res;
		//开始头插
		//先修改插入链表的指针域
		temp->Ln = p->Ln;
		//再修改头结点的指针域
		p->Ln = temp;
	}
	return p;
}

template<class T>
LinkList<T>::~LinkList()
{
	free(this->Ln);
}
//创建链表--头插法
//传入一个带头结点的链表

template<class T>
LinkList<T>* LinkList<T>::CreatLinkList_head(int length)
{
	//头结点
	LinkList* L1 = new LinkList();
	//头指针
	LinkList* p = L1;
	for (int i = length - 1; i >= 0; i--)
	{
		LinkList* temp = new LinkList();
		std::cout << "该方法为头插法从后往前插入";
		std::cout << "请输入第" << i + 1 << "个元素" << std::endl;
		std::cin >> temp->val;
		//开始头插
		//先修改插入链表的指针域
		temp->Ln = p->Ln;
		//再修改头结点的指针域
		p->Ln = temp;
	}
	return p;
}

//创建链表尾插法
template<class T>
LinkList<T>* LinkList<T>::CreatLinkList_back(int length)
{
	//头结点
	LinkList* L1 = new LinkList();
	//头指针
	LinkList* p = L1;
	p->Ln = NULL;
	//创建一个记录指针用于记录插入位置前一个结点的指针域
	LinkList* t = new LinkList();
	t = p;
	for (int i = 0; i < length; i++)
	{
		LinkList* temp = new LinkList();
		std::cout << "该方法为尾插法从前往后插入";
		std::cout << "请输入第" << i + 1 << "个元素" << std::endl;
		std::cin >> temp->val;
		//先将指向的指针域赋值成临时变量
		t->Ln = temp;
		//将指针区域进行后移位
		t = temp;
		//给下一步置空，关键一步
		t->Ln = NULL;
	}
	return p;
}

//统计链表的长度
template<class T>
int LinkList<T>::LinkListlength()
{
	int len = 0;
	LinkList<T>* temp = this->Ln;
	if (temp == NULL || temp->Ln == NULL)
	{
		std::cout << "linklist is NULL" << std::endl;
		return -1;
	}
	temp = temp->Ln;
	while (temp != NULL)
	{
		len++;
		temp = temp->Ln;
	}
	return len;
}

//打印链表
template<class T>
void LinkList<T>::LinkListprint()
{
	int i = 0;
	if (this->Ln == NULL || this->Ln->Ln == NULL)
	{
		std::cout << "error" << std::endl;
		return;
	}
	LinkList* tem = new LinkList();
	tem = this->Ln;
	tem = tem->Ln;
	while (tem != NULL)
	{
		std::cout << "第" << ++i << "个元素为";
		std::cout << tem->val << std::endl;
		tem = tem->Ln;
	}
}

//遍历链表的函数
//获得该位置的指针域
template<class T>
LinkList<T>* LinkList<T>::LinkListTraverse(int n)
{
	LinkList<int>* L = this->Ln;
	if (n == 0)
	{
		return L->Ln;
	}
	for (int i = 0; i <= n; i++)
	{
		if (L != NULL)
		{
			L = L->Ln;
		}
		else
		{
			std::cout << "发生错误该位置没有结点" << std::endl;
			return 0;
		}
	}
	return L;
}

//插入一个结点
//e为插入的位置,遍历到e-1的位置
template<class T>
void LinkList<T>::InsertLinkList(int e)
{
	if (e < 0)
	{
		std::cout << "ERROR" << std::endl;
		return;
	}
	LinkList* p = new LinkList();
	p->Ln = NULL;
	std::cout << "请输入结点的值" << std::endl;
	std::cin >> p->val;
	//头结点的下一个为空，即只有一个头结点
	if (this->Ln == NULL)
	{
		this->Ln = p;
	}
	//取到前一个元素的指针域
	else
	{
		LinkList* temp = this->LinkListTraverse(e);
		//新建结点的指针域指向索引前的指针域
		p->Ln = temp->Ln;
		//修改索引前的指针域指向新建指针
		temp->Ln = p;
	}
}

//获得指定索引的值
template<class T>
T LinkList<T>::getvalLinkList(int e)
{
	if (e == 0) {
		return this->val;
	}
	int length = this->LinkListlength();
	if (e > length - 1 || e < 0)
	{
		std::cout << "没有该索引" << std::endl;
		return -1;
	}
	LinkList* l1 = this->LinkListTraverse(e + 1);
	return l1->val;
}

//删除链表
template<class T>
void LinkList<T>::DeleteLinkList()
{
	LinkList<T>* current = this;
	LinkList<T>* next = nullptr;

	while (current->Ln != NULL) {
		next = current->Ln;
		free(current);
		current = next;
	}
}

//合并链表
template<class T>
void LinkList<T>::groupLinkList(LinkList* L2)
{
	int length1 = this->LinkListlength();
	int length2 = L2->LinkListlength();
	LinkList* temp = this;
	for (int i = 0; i <= length1; i++)
	{
		temp = temp->Ln;
	}
	temp->Ln = L2->Ln->Ln;
}

//反转链表
template<class T>
void LinkList<T>::reverseLinkList()
{
	LinkList* prev = nullptr;

	//LinkList* current = this->Ln;
	LinkList* current = this->Ln->Ln;

	LinkList* next = nullptr;

	while (current != nullptr) {
		next = current->Ln; // 保存下一个节点
		current->Ln = prev; // 反转当前节点的指针
		prev = current; // 移动prev指针
		current = next; // 移动current指针
	}
	//this->Ln = prev;
	this->Ln->Ln = prev; // 重新设置头节点为反转后的第一个节点
}

//求和链表上的数
template<class T>
T LinkList<T>::countLinkList()
{
	if (this->Ln == NULL) {
		std::cout <<  "The LinkList is NULL!" << std::endl;
	}

	int length = this->LinkListlength();
	LinkList* L = this->Ln;

	int count = 0;
	for (int i = 0; i <= length; i++)
	{
		count += L->val;
		L = L->Ln;
	}
	return count;
}

//交换两索引上的数
template<class T>
void LinkList<T>::exchangeLinkList(int l1, int l2)
{

	LinkList* nL1 = this->LinkListTraverse(l1);
	LinkList* nL2 = this->LinkListTraverse(l2);

	T temp = 0;

	temp = nL1->val;
	nL1->val = nL2->val;
	nL2->val = temp;
}

//删除指定节点
template<class T>
void LinkList<T>::deleteLinkListbyid(int l1)
{
	LinkList* temp1 = this->LinkListTraverse(l1 - 1);
	LinkList* temp2 = this->LinkListTraverse(l1);

	temp1->Ln = temp2->Ln;
}

//头插法
template<class T>
void LinkList<T>::insertHead(T val) {
	LinkList* temp = new LinkList();
	temp->val = val;

	//temp->Ln = this->Ln;
	temp->Ln = this->Ln->Ln;

	//this->Ln = temp;
	this->Ln->Ln = temp;
}

//尾插法
template<class T>
void LinkList<T>::insertBack(T val) {
	LinkList* temp = new LinkList();
	temp->val = val;

	LinkList* current = this->Ln;
	while (current->Ln != NULL)
	{
		current = current->Ln;
	}
	current->Ln = temp;
}

//在指定位置插入指定值
template<class T>
void LinkList<T>::InsertValue(int e, T val)
{
	if (e < 0)
	{
		std::cout << "ERROR" << std::endl;
		return;
	}
	else if (e == 0) {
		this->insertHead(val);
		return;
	}
	LinkList* p = new LinkList();
	p->Ln = NULL;
	p->val = val;

	LinkList<T>* L = this->Ln;

	//头结点的下一个为空，即只有一个头结点
	if (L->Ln == NULL)
	{
		L->Ln = p;
	}
	//取到前一个元素的指针域
	else
	{
		LinkList* temp = L->LinkListTraverse( e - 1);
		//新建结点的指针域指向索引前的指针域
		p->Ln = temp->Ln;
		//修改索引前的指针域指向新建指针
		temp->Ln = p;
	}
}