#pragma once
struct Segment_Tree_Node
{
public:
	int val = 0;
	int addMark = 0;
};
class Segment_Tree
{
public:
	Segment_Tree(int n);
	~Segment_Tree();
	void build(int val[]);
	int query(int start, int end);
	void update(int start, int end, int addVal);

private:
	int n;
	Segment_Tree_Node * segTree;
	const int INFINITE = 0X7FFFFFFF;
	inline int min(int a, int b);
	void pushDown(int root);
	void do_build(int root, int val[], int start, int end);
	void do_update(int root, int nstart, int nend, int ustart, int uend, int addVal);
	int do_query(int root, int nstart, int nend, int qstart, int qend);

};

