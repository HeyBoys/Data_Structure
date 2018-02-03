# Data_Structure
## 1并查集
并查集是一种描述不相交集合的数据结构，设有一个动态集合S={s1，s2，s3，.....sn}，每个集合通过一个代表元来标识，代表元就是动态集合Si中的某个元素。并查集数据结构可实现快速查找某一元素所在集合，以及集合之间的合并。

多用于处理无向图的连通分量，某两顶点是否想通，以及最小生成树
## 2二叉索引树（树状数组）
给定一个n个元素的数组A[1……n]，采取一个数据结构支持更新update(x,d)：让Ax增加d，以及Query(L,R)计算A[L……R]部分和，则树状数组是最好的选择。
## 3线段树
假设有编号从1到n的n个点，每个点都存了一些信息，用[L,R]表示下标从L到R的这些点。</br> 线段树的用处就是，对编号连续的一些点进行修改或者统计操作，修改和统计的复杂度都是O(log2(n)).</br>  线段树的原理，就是，将[1,n]分解成若干特定的子区间(数量不超过4*n),然后，将每个区间[L,R]都分解为 少量特定的子区间，通过对这些少量子区间的修改或者统计，来实现快速对[L,R]的修改或者统计。 </br> 由此看出，用线段树统计的东西，必须符合区间加法，否则，不可能通过分成的子区间来得到[L,R]的统计结果。 </br> 
**符合区间加法,可以使用线段树储存**</br> 
数字之和——总数字之和 = 左区间数字之和 + 右区间数字之和</br> 
最大值/最小值——总最大值/最小值=max(左区间最大值/最小值，右区间最大值/最小值)
