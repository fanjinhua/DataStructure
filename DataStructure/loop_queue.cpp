#include <cstdlib>
const int MAXQSIZE = 100;
typedef int Type;

typedef struct
{
	Type* base;
	int front;
	int rear;
} LoopQueue;

int init_queue(LoopQueue& Q)
{
	Q.base = (Type *)malloc(sizeof(Type));
	if (!Q.base)
		return 0;
	Q.front = Q.rear = 0;
	return 1;
}

int length(LoopQueue Q)
{
	return (Q.rear - Q.front+MAXQSIZE) % MAXQSIZE;
}

int enqueue(LoopQueue& Q, Type e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return 0;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return 1;
}

int dequeue(LoopQueue& Q, Type& e)
{
	if (Q.front == Q.rear)
		return 0;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return 1;
}

bool empty(const LoopQueue& Q)
{
	return Q.front == Q.rear;
}
