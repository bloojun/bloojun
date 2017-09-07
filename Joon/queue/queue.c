#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX 2

typedef struct queue {
	int rear;
	int front;
	int arr[MAX];
}Queue;

void EnQueue(Queue *q, int data)
{
	if (q != NULL &&  q->rear != MAX)
	{
		q->arr[q->rear] = data;
		(q->rear)++;
	}
	else
		return;
}

int DeQueue(Queue *d)
{
	int data = 0;

	if (d != NULL && d->front != d->rear)
	{
		data = d->arr[d->front];
		d->arr[d->front] = 0;
		(d->front)++;
		return data;
	}
	else
		return;
}

int main(void)
{
	Queue q;
	int data = 0;

	memset(&q.arr, 0, sizeof(q.arr));
	q.rear = 0;
	q.front = 0;

	//EnQueue(&q, 1);

	DeQueue(&q);

	printf("%d\n", q.arr[q.front - 1]);

	return 0;
}