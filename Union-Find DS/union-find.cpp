#include"union-find.h"
union_find::union_find(int n)
{
	this->n = n;
	parent = new int[n];
	rank = new int[n];
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

union_find::~union_find()
{
	delete[] parent;
	delete[] rank;
}

int union_find::FindSet(int i)
{
	if (parent[i] == i)
		return i;
	else 
	return parent[i] = FindSet(parent[i]); 
}

bool union_find::IsSameSet(int i, int j)
{
	return FindSet(i) == FindSet(j);
}

void union_find::UnionSet(int i, int j)
{
	int x1, x2;
	x1 = FindSet(i);
	x2 = FindSet(j);
	if (x1 == x2) return;
	if (rank[x1] > rank[x2]) parent[x2] = x1;
	else
	{
		if (rank[x1] == rank[x2]) rank[x2]++;
		parent[x1] = x2;
	}
}
