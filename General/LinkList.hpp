#pragma once

template<class T>
class LinkList
{
public:
	LinkList();

	LinkList(int len);

	LinkList(int len, T res);

	~LinkList();

	//��������ͷ�巨
	LinkList* CreatLinkList_head(int length);

	//����ָ�����ȣ��̶�ֵ������
	LinkList* CreateLinkListByNum(int length, T res);

	//��������β�巨
	LinkList* CreatLinkList_back(int length);

	//ͳ������ĳ���
	int LinkListlength();

	//��ӡ����
	void LinkListprint();

	//��������ĺ���
	//��ø�λ�õ�ָ����
	LinkList* LinkListTraverse(int n);

	//����һ�����
	//eΪ�����λ��,������e-1��λ��
	void InsertLinkList(int e);

	//���ָ��������ֵ
	T getvalLinkList(int e);

	//ɾ������
	void DeleteLinkList();

	//�ϲ�����
	void groupLinkList(LinkList* L2);

	//��ת����
	void reverseLinkList();

	//��������ϵ���
	T countLinkList();

	//�����������ϵ���
	void exchangeLinkList(int l1, int l2);

	//ɾ��ָ���ڵ�
	void deleteLinkListbyid(int l1);

	//��ָ��λ�ò���ָ��ֵ
	void InsertValue(int e, T val);

	//ͷ���뷨
	void insertHead(T val);

	//β�巨
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

//���캯��
template<class T>
LinkList<T>::LinkList(int len)
{
	if (len <= 0) {
		std::cout << "the linklist's length must greater than 0" << std::endl;
		return;
	}
	this->Ln=CreatLinkList_back(len);
}

//���캯��
template<class T>
LinkList<T>::LinkList(int length, T res) {
	this->Ln = CreateLinkListByNum(length, res);
}

template<class T>
LinkList<T>* LinkList<T>::CreateLinkListByNum(int length, T res) {
	//ͷ���
	LinkList* L1 = new LinkList();
	//ͷָ��
	LinkList* p = L1;
	for (int i = length - 1; i >= 0; i--)
	{
		LinkList* temp = new LinkList();
		temp->val = res;
		//��ʼͷ��
		//���޸Ĳ��������ָ����
		temp->Ln = p->Ln;
		//���޸�ͷ����ָ����
		p->Ln = temp;
	}
	return p;
}

template<class T>
LinkList<T>::~LinkList()
{
	free(this->Ln);
}
//��������--ͷ�巨
//����һ����ͷ��������

template<class T>
LinkList<T>* LinkList<T>::CreatLinkList_head(int length)
{
	//ͷ���
	LinkList* L1 = new LinkList();
	//ͷָ��
	LinkList* p = L1;
	for (int i = length - 1; i >= 0; i--)
	{
		LinkList* temp = new LinkList();
		std::cout << "�÷���Ϊͷ�巨�Ӻ���ǰ����";
		std::cout << "�������" << i + 1 << "��Ԫ��" << std::endl;
		std::cin >> temp->val;
		//��ʼͷ��
		//���޸Ĳ��������ָ����
		temp->Ln = p->Ln;
		//���޸�ͷ����ָ����
		p->Ln = temp;
	}
	return p;
}

//��������β�巨
template<class T>
LinkList<T>* LinkList<T>::CreatLinkList_back(int length)
{
	//ͷ���
	LinkList* L1 = new LinkList();
	//ͷָ��
	LinkList* p = L1;
	p->Ln = NULL;
	//����һ����¼ָ�����ڼ�¼����λ��ǰһ������ָ����
	LinkList* t = new LinkList();
	t = p;
	for (int i = 0; i < length; i++)
	{
		LinkList* temp = new LinkList();
		std::cout << "�÷���Ϊβ�巨��ǰ�������";
		std::cout << "�������" << i + 1 << "��Ԫ��" << std::endl;
		std::cin >> temp->val;
		//�Ƚ�ָ���ָ����ֵ����ʱ����
		t->Ln = temp;
		//��ָ��������к���λ
		t = temp;
		//����һ���ÿգ��ؼ�һ��
		t->Ln = NULL;
	}
	return p;
}

//ͳ������ĳ���
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

//��ӡ����
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
		std::cout << "��" << ++i << "��Ԫ��Ϊ";
		std::cout << tem->val << std::endl;
		tem = tem->Ln;
	}
}

//��������ĺ���
//��ø�λ�õ�ָ����
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
			std::cout << "���������λ��û�н��" << std::endl;
			return 0;
		}
	}
	return L;
}

//����һ�����
//eΪ�����λ��,������e-1��λ��
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
	std::cout << "���������ֵ" << std::endl;
	std::cin >> p->val;
	//ͷ������һ��Ϊ�գ���ֻ��һ��ͷ���
	if (this->Ln == NULL)
	{
		this->Ln = p;
	}
	//ȡ��ǰһ��Ԫ�ص�ָ����
	else
	{
		LinkList* temp = this->LinkListTraverse(e);
		//�½�����ָ����ָ������ǰ��ָ����
		p->Ln = temp->Ln;
		//�޸�����ǰ��ָ����ָ���½�ָ��
		temp->Ln = p;
	}
}

//���ָ��������ֵ
template<class T>
T LinkList<T>::getvalLinkList(int e)
{
	if (e == 0) {
		return this->val;
	}
	int length = this->LinkListlength();
	if (e > length - 1 || e < 0)
	{
		std::cout << "û�и�����" << std::endl;
		return -1;
	}
	LinkList* l1 = this->LinkListTraverse(e + 1);
	return l1->val;
}

//ɾ������
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

//�ϲ�����
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

//��ת����
template<class T>
void LinkList<T>::reverseLinkList()
{
	LinkList* prev = nullptr;

	//LinkList* current = this->Ln;
	LinkList* current = this->Ln->Ln;

	LinkList* next = nullptr;

	while (current != nullptr) {
		next = current->Ln; // ������һ���ڵ�
		current->Ln = prev; // ��ת��ǰ�ڵ��ָ��
		prev = current; // �ƶ�prevָ��
		current = next; // �ƶ�currentָ��
	}
	//this->Ln = prev;
	this->Ln->Ln = prev; // ��������ͷ�ڵ�Ϊ��ת��ĵ�һ���ڵ�
}

//��������ϵ���
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

//�����������ϵ���
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

//ɾ��ָ���ڵ�
template<class T>
void LinkList<T>::deleteLinkListbyid(int l1)
{
	LinkList* temp1 = this->LinkListTraverse(l1 - 1);
	LinkList* temp2 = this->LinkListTraverse(l1);

	temp1->Ln = temp2->Ln;
}

//ͷ�巨
template<class T>
void LinkList<T>::insertHead(T val) {
	LinkList* temp = new LinkList();
	temp->val = val;

	//temp->Ln = this->Ln;
	temp->Ln = this->Ln->Ln;

	//this->Ln = temp;
	this->Ln->Ln = temp;
}

//β�巨
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

//��ָ��λ�ò���ָ��ֵ
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

	//ͷ������һ��Ϊ�գ���ֻ��һ��ͷ���
	if (L->Ln == NULL)
	{
		L->Ln = p;
	}
	//ȡ��ǰһ��Ԫ�ص�ָ����
	else
	{
		LinkList* temp = L->LinkListTraverse( e - 1);
		//�½�����ָ����ָ������ǰ��ָ����
		p->Ln = temp->Ln;
		//�޸�����ǰ��ָ����ָ���½�ָ��
		temp->Ln = p;
	}
}