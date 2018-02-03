#include "BinaryIndexedTree.h"
BinaryIndexedTree::BinaryIndexedTree(int n,int * data)
{
	this->n = n;
	c = new int[n + 1];
	for (int i = 1; i <= n; i++)
		c[i] = 0;
	for (int i = 1; i <= n; i++)
		update(i, data[i]);
}

BinaryIndexedTree::~BinaryIndexedTree()
{
	delete[] c;
}

void BinaryIndexedTree::update(int k, int x)
{
	for (int i = k; i <= n; i += lowbit(i))
	{
		c[i] += x;
	}
}

int BinaryIndexedTree::sum(int x)
{
	int ans = 0;
	for (int i = x; i; i -= lowbit(i))
		ans += c[i];
	return ans;
}

inline int BinaryIndexedTree::lowbit(int t)
{
	return t & (-t);
}
