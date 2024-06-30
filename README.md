# MiNiSTL

## 1.LinkList

### 1.LinkList();

> 无参构造函数,可用于构造头节点

```c++
LinkList<int> list = new LinkList<int>();
```

### 2.LinkList(int len);

> 有参构造函数，指定生成链表的长度

```c++
//创建一个长度为10的链表
LinkList<int> list = new LinkList<int>(10);
```

### 3.LinkList(int len, T res);

>有参构造函数，指定生成链表的长度和初始化每个元素为指定的值

### 4.~LinkList();

> 析构函数

### 5.LinkList* CreatLinkList_head(int length);

> 创建链表--头插法，指定链表的长度



### 6.LinkList* CreateLinkListByNum(int length, T res);

>创建链表--头插法，指定生成链表的长度和初始化每个元素为指定的值



### 7.LinkList* CreatLinkList_back(int length);

> 创建链表尾插法



### 8.int LinkListlength(LinkList* L);

> 统计链表的长度



### 9.void LinkListprint();

> 打印链表



### 10.LinkList* LinkListTraverse(LinkList* L, int n);

> 获得该位置的指针域



### 11.LinkList* InsertLinkList(LinkList* L, int e);

> 插入一个结点,e为插入的位置,遍历到e-1的位置



### 12.T getvalLinkList(LinkList* L, int e);

> 获得指定索引的值



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



### 21.LinkList* popLinkList(LinkList* L);

> 头删





























































