### 如果存储的两个对象键值相同, 该如何处理?

1. 二叉查找树中每一个节点不仅可以存储一个数据, 也可以通过链表和支持动态扩容的数组等数据结构, 把值相同的数据存储在同一个节点上。
2. 每个节点仍只存储一个数据。在查找插入位置的过程中, 如果碰到一个节点的值, 与要插入数据的值相同, 我们就将这个要插入的数据放到这个节点的右子树, 也就是说, 把这个新插入的数据当作大于这个节点的值来处理。查找时, 直到遇到叶子节点才停止; 删除时, 先找到每个节点, 在依次删除。