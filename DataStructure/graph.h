#pragma once

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType;

template <typename Tv, typename Te> //�������͡�������
class Graph
{
public:
	int n; //��������
	int e; //������

private:
	void reset()
	{ //���ж��㡢�ߵĸ�����Ϣ��λ
		for (int i = 0; i < n; i++)
		{ //���ж����

		}
	}

};