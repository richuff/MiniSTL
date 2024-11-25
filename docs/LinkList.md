### 1.LinkList();

> 无参构造函数,可用于构造头节点

```c++
LinkList<int>* list = new LinkList<int>();
```

### 2.LinkList(int len);

`length` 创建的长度

> 有参构造函数，指定生成链表的长度

```c++
//创建一个长度为10的链表
LinkList<int>* list = new LinkList<int>(10);
```

### 3.LinkList(int len, T res);

- `length` 创建的长度
- `res` 初始的数大小

>有参构造函数，指定生成链表的长度和初始化每个元素为指定的值

```c++
//创建一个长度为10，元素都为2的链表
LinkList<int>* list = new LinkList<int>(10,2);
```

### 4.~LinkList();

> 析构函数

### 5.LinkList* CreatLinkList_head(int length);

- `length` 创建的长度

`(不推荐使用)`

> 创建链表--头插法，指定链表的长度

```c++
LinkList<int>* list = new LinkList<int>(10,2);
LinkList<int>* temp = list->CreatLinkList_head(10);
```

### 6.LinkList* CreateLinkListByNum(int length, T res);

- `length` 创建的长度
- `res` 初始的数大小

`(不推荐使用)`

>创建链表--头插法，指定生成链表的长度和初始化每个元素为指定的值

```c++
LinkList<int>* list = new LinkList<int>(10,2);
LinkList<int>* temp = list->CreateLinkListByNum(10,2);
```

### 7.LinkList* CreatLinkList_back(int length);

- `length` 创建的长度

`(不推荐使用)`

> 创建链表尾插法

```c++
LinkList<int>* list = new LinkList<int>(10,2);
LinkList<int>* temp = list->CreatLinkList_back(10);
```

### 8.int LinkListlength();

> 统计链表的长度

```c++
LinkList<int>* list = new LinkList<int>(10,2);
cout << list->LinkListlength() << endl;;
```

### 9.void LinkListprint();

> 打印链表

```c++
LinkList<int>* list = new LinkList<int>(10,2);
list->LinkListprint();
```

### 10.LinkList* LinkListTraverse(int n);

- n `索引位置`

> 获得该位置的指针域

```c++
LinkList<int>* list = new LinkList<int>(3,0);
LinkList<int>* res = temp->LinkListTraverse(0);
cout << res->getvalLinkList(0) << endl;
```

### 11.void InsertLinkList(int e);

- n `索引位置`

> 插入一个结点,e为插入的位置,遍历到e-1的位置

```c++
LinkList<int>* list = new LinkList<int>(3); 
list->InsertLinkList(1);  //在下标为1的位置插入元素
```

### 12.T getvalLinkList(int e);

- n `索引位置`

> 获得指定索引的值

```c++
LinkList<int>* list = new LinkList<int>(3);
cout << list->getvalLinkList(0) << endl;
```

### 13.LinkList* ClearLinkList(LinkList* L);

> 清空链表



### 14.void DeleteLinkList(LinkList* L);

> 删除链表



### 15.LinkList* groupLinkList(LinkList* L1, LinkList* L2);

> 合并链表



### 16.LinkList* reverseLinkList(LinkList* L);

> 反转链表



### 17.T countLinkList(LinkList* L);

> 求和链表上的数



### 18.LinkList* exchangeLinkList(LinkList* L1, int l1, int l2);

> 交换两索引上的数



### 19.LinkList* deleteLinkListbyid(LinkList* L, int l1);

> 删除指定节点



### 20.LinkList* InsertValue(LinkList* L, int e, int num);

> 在指定位置插入指定值


