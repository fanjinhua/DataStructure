#pragma once

#include <queue>
#include <stack>

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType;

template <typename Tv, typename Te> //顶点类型、边类型
class Graph
{
public:
	// 顶点
	int n; //顶点总数
	virtual int insert(Tv const&) = 0; //插入顶点，返回编号
	virtual Tv remove(int) = 0; //删除顶点及其关联边，返回该顶点信息
	virtual Tv& vertex(int) = 0; //顶点v的数据（该顶点的确存在）
	virtual int inDegree(int) = 0; //顶点v的入度（该顶点的确存在）
	virtual int outDegree(int) = 0; //顶点v的出度（该顶点的确存在）
	virtual int firstNbr(int) = 0; //顶点v的首个邻接顶点
	virtual int nextNbr(int, int) = 0; //顶点v的（相对于顶点j的）下一邻接顶点
	virtual VStatus& status(int) = 0;  //顶点v的状态
	virtual int& dTime(int) = 0; //顶点v的时间标签dTime
	virtual int& fTime(int) = 0; //顶点v的时间标签fTime
	virtual int& parent(int) = 0; //顶点v在遍历树中的父亲
	virtual int& priority(int) = 0; //顶点v在遍历树中的优先级数
// 边：这里约定，无向边均统一转化为方向互逆的一对有向边，从而将无向图视作有向图的特例
	int e; //边总数
	virtual bool exists(int, int) = 0; //边(v, u)是否存在
	virtual void insert(Te const&, int, int, int) = 0; //在顶点v和u之间插入权重为w的边e
	virtual Te remove(int, int) = 0; //删除顶点v和u之间的边e，返回该边信息
	virtual EType & type(int, int) = 0; //边(v, u)的类型
	virtual Te& edge(int, int) = 0; //边(v, u)的数据（该边的确存在）
	virtual int& weight(int, int) = 0; //边(v, u)的权重
// 算法
	void bfs(int); //广度优先搜索算法
	void dfs(int); //深度优先搜索算法
private:
	void reset()
	{ //所有顶点、边的辅助信息复位
		for (int i = 0; i < n; i++)
		{ //所有顶点的
			status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;
			parent(i) = -1; priority(i) = INT_MAX;
			for (int j = 0; j < n; j++)
				if (exists(i, j))
					type(i, j) = UNDETERMINED;
		}
	}
	void BFS(int, int&); //（连通域）广度优先搜索算法
	void DFS(int, int&); //（连通域）深度优先搜索算法
};

template<typename Tv, typename Te>  //广度优先搜索BFS算法（单个连通域）
inline void Graph<Tv, Te>::BFS(int v, int & clock)
{
	//assert: 0 <= v < n
	std::queue<int> Q;
	status(v) = DISCOVERED;
	Q.push(v);
	while (!Q.empty()) //在Q变空之前，不断
	{
		int v = Q.front();  Q.pop(); //取出队首顶点v
		dTime(v) = ++clock;
		for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))  //枚举v的所有邻居u
			if (status(u) == UNDISCOVERED)
			{
				status(u) = DISCOVERED; Q.push(u);
				type(v, u) = TREE; parent(u) = v;  //引入树边拓展支撑树
			}
			else
				type(v, u) = CROSS; //将(v, u)归类于跨边
		status(v) = VISITED;  //至此，当前顶点访问完毕
	}
}

template<typename Tv, typename Te> //深度优先搜索DFS算法（单个连通域）
inline void Graph<Tv, Te>::DFS(int v, int &clock)
{
	dTime(v) = ++clock; status(v) = DISCOVERED; //发现当前顶点v
	for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))
		switch (status(u))
		{
		case UNDISCOVERED: //u尚未发现，意味着支撑树可在此拓展
			type(v, u) = TREE; parent(u) = v; DFS(u, clock); break;
		case DISCOVERED: //u已被发现但尚未访问完毕，应属被后代指向的祖先
			type(v, u) = BACKWARD; break;
		default: //u已访问完毕（VISITED，有向图），则视承袭关系分为前向边或跨边
			type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS; break;
		}
	status(v) = VISITED; fTime(v) = ++clock; //至此，当前顶点v方告访问完毕
}

template<typename Tv, typename Te> //广度优先搜索BFS算法（全图）
inline void Graph<Tv, Te>::bfs(int s)
{
	//assert: 0 <= s < n
	reset(); int clock = 0; int v = s;
	do //逐一检查所有顶点
		if (UNDISCOVERED == status(v)) //一旦遇到尚未发现的顶点
			BFS(v, clock);  //即从该顶点出发启动一次BFS
	while (s != (v = (++v % n))); //按序号检查，故不漏不重
}

template<typename Tv, typename Te>
inline void Graph<Tv, Te>::dfs(int s)
{
	reset(); int clock = 0; int v = s; //初始化
	do //逐一检查所有顶点
		if (UNDISCOVERED == status(v)) //一旦遇到尚未发现的顶点
			DFS(v, clock); //即从该顶点出发启动一次DFS
	while (s != (v = (++v % n))); //按序号检查，故不漏不重
}
