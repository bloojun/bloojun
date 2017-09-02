#include <stdio.h>

#define MAX 2

typedef struct stack {
	int arr[MAX];
	int top;
}STACK;

void push(STACK *s, int data)
{
	s->arr[++s->top] = data;
	if (s->top > MAX - 1) // 왜 data값이 s->top으로 들어가는지 이해가안된다리
	{
		printf("no push \n");
	}

		printf("push : %d \n", data);
}

void pop(STACK *s)
{
	s->arr[--s->top];
	if (s->top < 0)
	{
		printf("no pop\n");
		s->top = -1;
	}
	else
		printf("pop : %d \n", *(s->arr));
}

int main(void)
{
	STACK s;
	int data;
	s.top = -1;

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	pop(&s);
	pop(&s);
	//push(&s, 10);

	return 0;
}