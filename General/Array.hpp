#pragma once

template<class T>
class Array
{
public:
	~Array();

	Array(int len);

	Array(int len, T val);

	/*��ȡ���鳤��*/
	int Arraylength();

	/*��ӡ����*/
	void PrintArray();

	/*ͷ��*/
	void InsertBefore(T val);

	/*β��*/
	void InsertEnd(T val);

	/*���*/
	int ArrayCount();

	/*ɾ��ָ���ڵ�*/
	void ArrayDelete(int n);

	/*��ø�λ�õ�ֵ*/
	T ArrayGetById(int n);

	//�������
	void ClearArray();

	//�����������ϵ���
	void ExchangeArrayById(T n1,T n2);

	//��ת����
	void ReverseArray();

	//��һ��˳���ӡ����
	void PrintArrayFromTo(int front, int rear);

	//�޸�ָ��������ֵ
	void ChangeValue(int index,T value);
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


/*��ȡ���鳤��*/
template<class T>
int Array<T>::Arraylength()
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
void Array<T>::ArrayDelete(int n)
{
	if (this->arr == NULL) return;
	for (int i = n; i < this->len-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	this->len--;
}

/*��ø�λ�õ�ֵ*/
template<class T>
T Array<T>::ArrayGetById(int n)
{
	if (this->arr == NULL || this->len < n + 1) return INT_MIN;
	return this->arr[n];
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
void Array<T>::ExchangeArrayById(T n1, T n2)
{
	if (this->arr == NULL || this->len < n1 + 1 || this->len < n2 + 1) return;
	this -> arr[n1] = this -> arr[n1] + this -> arr[n2];
	this -> arr[n2] = this -> arr[n1] - this -> arr[n2];
	this -> arr[n1] = this -> arr[n1] - this -> arr[n2];
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

//�޸�ָ��������ֵ
template<class T>
void Array<T>::ChangeValue(int index, T value) {
	this->arr[index] = value;
}