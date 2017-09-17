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
void enqueue(Queue *Q, int data);
int dequeue(Queue *Q);
int printQueue(Queue *Q);

int main()
{
	Queue Q;	//큐 생성
	int pop = 0;
	int num = 0;
	int data = 0;
	init(&Q);
	while (1)
	{
		printf("********* ArrayQueue *********\n");
		printf("1.enqueue 2.dequeue 3.printQ 4.exit \n");
		printf("번호를 선택해 주세요 : ");
		scanf("%d", &num);
		if (num == 1)
		{
			printf("입력하실 데이터를 입력해주세요 : ");
			scanf("%d", &data);
			enqueue(&Q, data);
		}
		else if (num == 2)
		{
			pop = dequeue(&Q);
			//printf("dequeue: %d\n", pop);
		}
		else if (num == 3)
		{
			printQueue(&Q);
		}
		else
		{
			break;
		}
		system("cls");
	}
	return 0;
}

void init(Queue *Q)
{	
	memset(Q->Queue_array,0,sizeof(int)* ARY_M_SIZE);	//배열 초기화
	Q->front = Q->rear = -1;
}

void enqueue(Queue *Q, int data)
{
	if (is_full(Q))
	{
		printf("큐가 포화상태입니다.\n");
		exit(1);
	}
	(Q->rear)++;
	Q->Queue_array[Q->rear] = data;
	
}

int dequeue(Queue *Q)
{
	if (is_empty(Q))
	{
		printf("큐가 공백상태입니다.\n");
		exit(1);
	}
	(Q->front)++;
	return Q->Queue_array[Q->front];
}

int is_full(Queue *Q) 
{
	return ((Q->rear+1) == ARY_M_SIZE);
}

int is_empty(Queue *Q)
{
	return (Q->front == Q->rear);
}

int printQueue(Queue *Q)
{
	int i;
	for (i = Q->front + 1; i <= Q->rear; i++)
		printf("Queue[%d] : %d \n",i, Q->Queue_array[i]);
	printf("메뉴로 넘어가시려면 아무키나 눌러주세요 \n");
	getch();
	return 0;
}
