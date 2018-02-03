#include "Segment_Tree.h"
Segment_Tree::Segment_Tree(int n)
{
	segTree = new Segment_Tree_Node[4 * n];
	this->n = n;
}

Segment_Tree::~Segment_Tree()
{
	delete[] segTree;
}

void Segment_Tree::build(int val[])
{
	do_build(0, val, 1, n);
}

int Segment_Tree::query(int start, int end)
{
	return do_query(0, 1, n, start, end - 1);
}

void Segment_Tree::update(int start, int end, int addVal)
{
	do_update(0, 1, n, start, end - 1, addVal);
}

inline int Segment_Tree::min(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

void Segment_Tree::pushDown(int root)
{
	if (segTree[root].addMark != 0)
	{
		segTree[root * 2 + 1].addMark += segTree[root].addMark;
		segTree[root * 2 + 2].addMark += segTree[root].addMark;
		segTree[root * 2 + 1].val += segTree[root].addMark;
		segTree[root * 2 + 2].val += segTree[root].addMark;
		segTree[root].addMark = 0;
	}
}

void Segment_Tree::do_build(int root, int val[], int start, int end)
{
	segTree[root].addMark = 0;
	if (start == end)
		segTree[root].val = val[start];
	else
	{
		int mid = (start + end) / 2;
		do_build(root * 2 + 1, val, start, mid);
		do_build(root * 2 + 2, val, mid + 1, end);
		segTree[root].val = min(segTree[root * 2 + 1].val, segTree[root * 2 + 2].val);
	}
}

void Segment_Tree::do_update(int root, int nstart, int nend, int ustart, int uend, int addVal)
{
	if (ustart > nend || uend < nstart)
		return;
	if (ustart <= nstart && uend >= nend)
	{
		segTree[root].val += addVal;
		segTree[root].addMark += addVal;
		return;
	}
	pushDown(root);
	int mid = (nstart + nend) / 2;
	do_update(root * 2 + 1, nstart, mid, ustart, uend, addVal);
	do_update(root * 2 + 2, mid + 1, nend, ustart, uend, addVal);
	segTree[root].val = min(segTree[root * 2 + 1].val, segTree[root * 2 + 2].val);
}

int Segment_Tree::do_query(int root, int nstart, int nend, int qstart, int qend)
{
	if (qstart > nend || qend < nstart)
		return INFINITE;
	if (qstart <= nstart && qend >= nend)
		return segTree[root].val;
	pushDown(root);
	int mid = (nstart + nend) / 2;
	return min(do_query(root * 2 + 1, nstart, mid, qstart, qend), do_query(root * 2 + 2, mid + 1, nend, qstart, qend));
}
