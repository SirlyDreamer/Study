# C++ STL标准库学习笔记

## 1.STL容器
![STL 容器](https://oi-wiki.org/lang/csl/images/container1.png)

### 顺序容器(Sequence Containers)
----
### array 数组 `#include <array>`
* 定长的顺序表，原生数组的再封装，以便于使用迭代器

### vector 向量 `#include <vector>`
* 后端可高效增加元素的顺序表，等同于动态数组，可以直接使用 `[]` 访问数据

### deque 双端队列 `#include <deque>`
* 双端都可高效增加元素的顺序表

### list 列表 `#include <list>`
* 可以沿双向遍历的链表

### forward_list 单向链表
* 只能沿单方向遍历的链表

#### 顺序容器的成员函数

|Iterators|vector|deque|list|功能说明|
|:-:|:-:|:-:|:-:|-|
|`begin`|O|O|O|返回容器前端的迭代器|
|`end`|O|O|O|返回容器末端的迭代器|
|`rbegin`|O|O|O|返回容器前端的倒转迭代器|
|`rend`|O|O|O|返回容器末端的倒转迭代器|
|`cbegin`|O|O|O|返回容器前端的只读迭代器|
|`cend`|O|O|O|返回容器末端的只读迭代器|
|`crbegin`|O|O|O|返回容器前端的倒转只读迭代器|
|`crend`|O|O|O|返回容器末端的倒转只读迭代器|

|Capacity|vector|deque|list|功能说明|
|:-:|:-:|:-:|:-:|-|
|`size`|O|O|O|返回当前容器中的元素个数|
|`max_size`|O|O|O|返回容器理论上可存储元素的最大个数（取决于索引的数据类型）|
|`resize`|O|O|O|改变容器的大小（分配内存并初始化，改变元素数量）|
|`capacity`|O|X|X|返回容器实际上可存储元素的最大个数（取决于容器当前可用的内存大小）|
|`empty`|O|O|O|检测容器是否为空。若容器为空，返回 true，否则返回 false 
|`reserve`|O|X|O|改变容器的大小（仅分配内存而不初始化，不改变元素数量）|
|`shrink_to_fit`|O|O|X|将容器从曾经最大的容量减少到它现在需要的容量|

|Element access|vector|deque|list|功能说明|
|:-:|:-:|:-:|:-:|-|
|`operator[]`|O|O|X|取出容器中的元素（不安全，可能发生下标越界）|
|`at`|O|O|X|返回当前容器指定位置的元素的引用（越界时抛出异常）|
|`front`|O|O|O|返回容器前端元素的引用|
|`back`|O|O|O|返回容器末端元素的引用|
|`data`|O|X|X|返回直接指向容器中元素的指针|

|Modifiers|vector|deque|list|功能说明|
|:-:|:-:|:-:|:-:|-|
|`assign`|O|O|O|将新内容分配给容器，替换其当前内容，并相应地修改其大小|
|`push_back`|O|O|O|在容器后端添加元素|
|`push_front`|X|O|O|在容器前端添加元素|
|`pop_back`|O|O|O|在容器后端删除元素|
|`pop_front`|X|O|O|在容器前端删除元素|
|`insert`|O|O|O|在容器中间插入元素|
|`erase`|O|O|O|删除容器中间的元素|
|`swap`|O|O|O|与另外一个同类型容器互换元素|
|`clear`|O|O|O|清除容器内的元素|
|`emplace`|O|O|O|构造并向指定位置插入元素|
|`emplace_front`|X|O|O|构造并向容器前端添加元素|
|`emplace_back`|O|O|O|构造并向容器后端添加元素|

|Operations|vector|deque|list|功能说明|
|:-:|:-:|:-:|:-:|-|
|`splice`|

### 关联容器(Associative Containers)
----
### Set/Multiset 集合/多重集合 `#include <set>`
* 集合是用以有序地存储互异元素的容器,其中的对象已排序。

* 多重集合是用以有序地存储元素的容器，其允许存在相等的元素。

### Map/Multimap 映射/多重映射 `#include <map>`
* 由 {key,value} 对组成的集合，以键大小关系进行排列。

* 由 {key,value} 对组成的多重集合，允许键有相等情况的映射。



### 无序容器(Unordered Containers)
----
### Unordered_set/Unordered_multiset 无序集合/无序多重集合
* 与 set/multiset 的区别在与元素无序，只关心”元素是否存在“，使用哈希实现

### Unordered_map/Unordered_multimap 无序映射/无序多重映射
* 与 map/multimap 的区别在与键 (key) 无序，只关心 "键与值的对应关系"，使用哈希实现

(说白了就是俩哈希表)

## 2.STL容器适配器
### Stack 栈
### Queue 队列
### 
