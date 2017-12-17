#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define ARY_M_SIZE 5

typedef struct Queuetag {
	int Queue_array[ARY_M_SIZE];
	int front, rear;
}Queue;

void init(Queue *Q);
int is_empty(Queue *Q);
int is_full(Queue *Q);
int enqueue(Queue *Q, int data);
int dequeue(Queue *Q);

void init(Queue *Q)
{
	memset(Q->Queue_array, 0, sizeof(int)* ARY_M_SIZE);	//배열 초기화
	Q->front = Q->rear = -1;
}

int enqueue(Queue *Q, int data)
{
	if (is_full(Q))
	{
		printf("큐가 포화상태입니다.\n");
		return -1;
	}
	(Q->rear)++;
	Q->Queue_array[Q->rear] = data;

}

int dequeue(Queue *Q)
{
	if (is_empty(Q))
	{
		printf("큐가 공백상태입니다.\n");
		return -1;
	}
	(Q->front)++;
	return Q->Queue_array[Q->front];
}

int is_full(Queue *Q)
{
	return ((Q->rear + 1) == ARY_M_SIZE);
}

int is_empty(Queue *Q)
{
	return (Q->front == Q->rear);
}
