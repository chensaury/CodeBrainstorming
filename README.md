# 代码随想录

# 707.设计链表

[力扣题目链接(opens new window)](https://leetcode.cn/problems/design-linked-list/)

题意：

在链表类中实现这些功能：

- get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
- addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
- addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
- addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val 的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
- deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

#### ****方法一：单向链表\****

**思路**

实现单向链表，即每个节点仅存储本身的值和后继节点。除此之外，我们还需要一个哨兵（sentinel）节点作为头节点，和一个size参数保存有效节点数。如下图所示。
![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml35432\wps1.jpg)

初始化时，只需创建头节点 head 和 size即可。实现 get**(**index) 时，先判断有效性，再通过循环来找到对应的节点的值。如下图所示。
![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml35432\wps2.jpg)

实现addAtIndex(index, val)时，如果index是有效值，则需要找到原来下标为 index的节点的前驱节点 pred，并创建新节点 to_add，将to_add 的后继节点设为 pred 的后继节点，将 pred 的后继节点更新为 to_add，这样就将 to_add 插入到了链表中。最后需要更新 size。这样的操作对于 index=0 也成立，如以下两张图所示。
![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml35432\wps3.jpg)
![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml35432\wps4.jpg)

实现 addAtHead(val)和 addAtTail(val) 时，可以借助 addAtIndex(index, val)来实现。

实现 deleteAtIndex(index)，先判断参数有效性。然后找到下标为 index 的节点的前驱节点 pred，通过将 pred 的后继节点更新为 pred 的后继节点的后继节点，来达到删除节点的效果。同时也要更新 size。如下图所示。
![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml35432\wps5.jpg)

 


