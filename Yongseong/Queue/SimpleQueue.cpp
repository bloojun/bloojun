#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define ARY_M_SIZE 5

typedef struct Queuetag {
	int Queue_array[ARY_M_SIZE];
	int front, rear;
}Queue;

void init(Queue *Q);
bool is_empty(Queue *Q);
bool is_full(Queue *Q);
bool enqueue(Queue *Q, int data);
int dequeue(Queue *Q);

int main()
{
	Queue Q;	//declare Queue
	int pop = 0;
	int num = 0;
	init(&Q);
	enqueue(&Q, 1);
	enqueue(&Q, 2);
	enqueue(&Q, 3);
	pop = dequeue(&Q);
	printf("dequeue: %d\n", pop);
	pop = dequeue(&Q);
	printf("dequeue: %d\n", pop);
	pop = dequeue(&Q);
	printf("dequeue: %d\n", pop);
	return 0;
}

void init(Queue *Q)
{	
	memset(Q->Queue_array,0,sizeof(int)* ARY_M_SIZE);	//init array
	Q->front = Q->rear = -1;
}

bool enqueue(Queue *Q, int data)
{
	if (!Q || is_full(Q))
	{
		
		printf("Queue is full or Queue err.\n");
		return false;
	}
	(Q->rear)++;
	Q->Queue_array[Q->rear] = data;
	return true;
}

int dequeue(Queue *Q)
{
	if (!Q || is_empty(Q))
	{
		printf("Queue is empty or Queue err.\n");
		return -1;
	}
	(Q->front)++;
	return Q->Queue_array[Q->front];
}

bool is_full(Queue *Q) 
{
	bool isFull = ((Q->rear + 1) == ARY_M_SIZE)? true : false;
	return isFull;
}

bool is_empty(Queue *Q)
{
	bool isEmpty = (Q->front == Q->rear) ? true : false;
	return isEmpty;
}

