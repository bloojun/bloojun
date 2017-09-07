#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX 4

typedef struct queue {
	int rear;
	int front;
	int arr[MAX];
}Queue;

void EnQueue(Queue *q, int data)
{
	
	if (q && q->front != (q->rear+1) % MAX )
	{
		q->arr[q->rear] = data;
		q->rear = (q->rear + 1) % (MAX-1);
		
	}
	else
	{
		printf("Full Array\n");
	}
}

int DeQueue(Queue *d)
{
	int data = 0;

	if (d && d->front != d->rear)
	{
		data = d->arr[d->front];
		//d->arr[d->front] = 0;
		d->front = (d->front + 1) % MAX;
		return data;
	}
	else
	{
		printf("No Data\n");
		return 0;
	}
}

int main(void)
{
	Queue q;
	int data = 0;
	
	memset(&q.arr, 0, sizeof(q.arr));
	q.rear = 0;
	q.front = 0;

	EnQueue(&q, 2);
	EnQueue(&q, 5);
	EnQueue(&q, 8);
	EnQueue(&q, 11);
	EnQueue(&q, 13);
	printf("%d\n", DeQueue(&q));
	printf("%d\n", DeQueue(&q));
	EnQueue(&q, 11);
	printf("%d\n", DeQueue(&q));
	printf("%d\n", DeQueue(&q));

	return 0;
}