#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
	int data;
	struct QueueNode* lnode;
	struct QueueNode* rnode;
}Q_Node;

typedef struct QueueType {
	QueueNode* front;
	QueueNode* rear;
}Q_Type;

void init(Q_Type *Q);
void enqueue(Q_Type* Q, int data);
int ldequeue(Q_Type* Q);
int rdequeue(Q_Type* Q);

void main()
{
	
	Q_Type Q;
	init(&Q);
	enqueue(&Q, 3);
	enqueue(&Q, 4);
	enqueue(&Q, 5);
	printf("%d\n", ldequeue(&Q));
	printf("%d\n", rdequeue(&Q));
	//getc(0);
}

void init(Q_Type* Q)
{
	Q->front = Q->rear = NULL;
}

void enqueue(Q_Type* Q, int data)
{
	Q_Node* temp = (Q_Node*)malloc(sizeof(Q_Node));
	temp->data = data;
	temp->lnode= NULL;
	temp->rnode = NULL;
	if (Q->front == NULL)
	{
		Q->front = temp;
		Q->rear = temp;
	}
	else
	{
		Q->rear->rnode = temp;
		temp->lnode = Q->rear;
		Q->rear = temp;
	}
}
int ldequeue(Q_Type* Q)
{
	Q_Node* temp = Q->front;
	int data = 0;
	data = temp->data;
	Q->front = Q->front->rnode;
	if (Q->front == NULL)
		Q->rear = NULL;
	free(temp);
	return data;
}
int rdequeue(Q_Type* Q)
{
	Q_Node* temp = Q->rear;
	int data = 0;
	data = temp->data;
	Q->rear = Q->rear->lnode;
	if (Q->rear == NULL)
		Q->front = NULL;
	free(temp);
	return data;
}













/*
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
	int data;
	struct QueueNode* nextNode;
}Q_Node;

typedef struct QueueType {
	QueueNode* frontNode;
	QueueNode* rearNode;
}Q_Type;
void init(Q_Type *Q_t);
void enqueue(Q_Type* Q_t, int data);
int dequeue(Q_Type* Q_t);

void main()
{	
	int data;
	Q_Type Q_t;
	init(&Q_t);
	enqueue(&Q_t, 3);
	enqueue(&Q_t, 4);
	data = dequeue(&Q_t);
	printf("%d\n", data);
	data = dequeue(&Q_t);
	printf("%d\n", data);
	getc(0);
}

void init(Q_Type* Q_t)
{
	Q_t->frontNode = Q_t->rearNode = NULL;
}
void enqueue(Q_Type* Q_t, int data)
{
	Q_Node *Q_n = (Q_Node*)malloc(sizeof(Q_Node));
	Q_n->data = data;
	Q_n->nextNode = NULL;
	if (Q_t->frontNode == NULL)		
	{
		Q_t->frontNode = Q_n;
		Q_t->rearNode = Q_n;
	}
	else
	{ 
		Q_t->frontNode->nextNode = Q_n;
		Q_t->rearNode = Q_n;
	}
}
int dequeue(Q_Type* Q_t)
{
	Q_Node* Q_n = Q_t->frontNode;
	int data = 0;
	data = Q_n->data;
	Q_t->frontNode = Q_t->frontNode->nextNode;
	if (Q_t->frontNode == NULL)
		Q_t->rearNode = NULL;
	free(Q_n);
	return data;
}
*/