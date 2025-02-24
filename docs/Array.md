# Array

### 1.Array(int len);

> len 创建的数组的长度，数组里的值默认为0

```c++
Array<int> array(2);
```

### 2.Array(int len, T val);

> len 创建的数组的长度,val为初始的值

```c++
Array<int> array(2,0);
```

### 3.int GetLength();

> 获取数组长度

```c++
int length = array.GetLength();
```

### 4.void PrintArray();

> 打印数组

```c++
array.PrintArray();
```

### 5.void InsertBefore(T val);

> 头插

```c++
array.InsertBefore(5);
```

### 6.void InsertEnd(T val);

> 尾插

```c++
array.InsertEnd(10);
```

### 7.int ArrayCount();

> 求和

```c++
int count = array.ArrayCount()
```

### 8.void ArrayDelete(int index);

> 删除指定节点

```c++
array.ArrayDelete(0);
```

### 9.void ClearArray();

> 清空数组

```c++
array.ClearArray();
```

### 10.void ExchangeArrayById(T indexo,T indext);

> 交换两索引上的数

```c++
array.ExchangeArrayById(0,4);
```

### 11.void ReverseArray();

> 反转数组

```c++
array.ReverseArray();
```

### 11.void PrintArrayFromTo(int front, int rear);

> 按一定顺序打印数组

```c++
array.PrintArrayFromTo(1, 2);
```

