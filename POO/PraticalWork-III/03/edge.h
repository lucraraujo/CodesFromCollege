#ifndef _EDGE_H_
#define _EDGE_H_

class Edge
{
	int node1;
	int node2;
public:
	Edge (int, int);
	int GetNode1() const;
	int GetNode2() const;
	void Set(int, int);
};

inline int Edge::GetNode1() const
{
	return node1;
}

inline int Edge::GetNode2() const
{
	return node2;
}

inline void Edge::Set(int no1, int no2)
{
	node1 = no1;
	node2 = no2;
}

inline Edge::Edge(int no1, int no2) : node1(no1), node2(no2){}


#endif