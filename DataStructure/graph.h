#pragma once

#include <queue>
#include <stack>

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType;

template <typename Tv, typename Te> //�������͡�������
class Graph
{
public:
	// ����
	int n; //��������
	virtual int insert(Tv const&) = 0; //���붥�㣬���ر��
	virtual Tv remove(int) = 0; //ɾ�����㼰������ߣ����ظö�����Ϣ
	virtual Tv& vertex(int) = 0; //����v�����ݣ��ö����ȷ���ڣ�
	virtual int inDegree(int) = 0; //����v����ȣ��ö����ȷ���ڣ�
	virtual int outDegree(int) = 0; //����v�ĳ��ȣ��ö����ȷ���ڣ�
	virtual int firstNbr(int) = 0; //����v���׸��ڽӶ���
	virtual int nextNbr(int, int) = 0; //����v�ģ�����ڶ���j�ģ���һ�ڽӶ���
	virtual VStatus& status(int) = 0;  //����v��״̬
	virtual int& dTime(int) = 0; //����v��ʱ���ǩdTime
	virtual int& fTime(int) = 0; //����v��ʱ���ǩfTime
	virtual int& parent(int) = 0; //����v�ڱ������еĸ���
	virtual int& priority(int) = 0; //����v�ڱ������е����ȼ���
// �ߣ�����Լ��������߾�ͳһת��Ϊ�������һ������ߣ��Ӷ�������ͼ��������ͼ������
	int e; //������
	virtual bool exists(int, int) = 0; //��(v, u)�Ƿ����
	virtual void insert(Te const&, int, int, int) = 0; //�ڶ���v��u֮�����Ȩ��Ϊw�ı�e
	virtual Te remove(int, int) = 0; //ɾ������v��u֮��ı�e�����ظñ���Ϣ
	virtual EType & type(int, int) = 0; //��(v, u)������
	virtual Te& edge(int, int) = 0; //��(v, u)�����ݣ��ñߵ�ȷ���ڣ�
	virtual int& weight(int, int) = 0; //��(v, u)��Ȩ��
// �㷨
	void bfs(int); //������������㷨
	void dfs(int); //������������㷨
private:
	void reset()
	{ //���ж��㡢�ߵĸ�����Ϣ��λ
		for (int i = 0; i < n; i++)
		{ //���ж����
			status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;
			parent(i) = -1; priority(i) = INT_MAX;
			for (int j = 0; j < n; j++)
				if (exists(i, j))
					type(i, j) = UNDETERMINED;
		}
	}
	void BFS(int, int&); //����ͨ�򣩹�����������㷨
	void DFS(int, int&); //����ͨ��������������㷨
};

template<typename Tv, typename Te>  //�����������BFS�㷨��������ͨ��
inline void Graph<Tv, Te>::BFS(int v, int & clock)
{
	//assert: 0 <= v < n
	std::queue<int> Q;
	status(v) = DISCOVERED;
	Q.push(v);
	while (!Q.empty()) //��Q���֮ǰ������
	{
		int v = Q.front();  Q.pop(); //ȡ�����׶���v
		dTime(v) = ++clock;
		for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))  //ö��v�������ھ�u
			if (status(u) == UNDISCOVERED)
			{
				status(u) = DISCOVERED; Q.push(u);
				type(v, u) = TREE; parent(u) = v;  //����������չ֧����
			}
			else
				type(v, u) = CROSS; //��(v, u)�����ڿ��
		status(v) = VISITED;  //���ˣ���ǰ����������
	}
}

template<typename Tv, typename Te>
inline void Graph<Tv, Te>::DFS(int, int &)
{
}

template<typename Tv, typename Te> //�����������BFS�㷨��ȫͼ��
inline void Graph<Tv, Te>::bfs(int)
{
	//assert: 0 <= s < n
	reset(); int clock = 0; int v = s;
	do //��һ������ж���
		if (UNDISCOVERED == status(v)) //һ��������δ���ֵĶ���
			BFS(v, clock);  //���Ӹö����������һ��BFS
	while (s != (v = (++v % n))); //����ż�飬�ʲ�©����
}

template<typename Tv, typename Te>
inline void Graph<Tv, Te>::dfs(int)
{
}
