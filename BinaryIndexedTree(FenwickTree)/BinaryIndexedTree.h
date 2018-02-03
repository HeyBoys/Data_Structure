#pragma once
class BinaryIndexedTree
{
public:
	BinaryIndexedTree(int n,int *data);
	~BinaryIndexedTree();
	void update(int k, int x);
	int sum(int x);
private:
	int n;
	int * c;
	inline int lowbit(int t);

};

