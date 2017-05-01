#pragma once

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType;

template <typename Tv, typename Te> //顶点类型、边类型
class Graph
{
public:
	int n; //顶点总数
	int e; //边总数

private:
	void reset()
	{ //所有顶点、边的辅助信息复位
		for (int i = 0; i < n; i++)
		{ //所有顶点的

		}
	}

};