#pragma once
class union_find
{
public:
	union_find(int n);
	~union_find();
	int FindSet(int i);
	bool IsSameSet(int i, int j);
	void UnionSet(int i, int j);
private:
	int n;
	int *parent,*rank;
};

