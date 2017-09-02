#include <stdio.h>

#define MAX 2

typedef struct stack {
	int arr[MAX];
	int top;
}STACK;

void push(STACK *s, int data)
{
	
	if (s->top >= MAX - 1)
	{
		printf("no push \n");
		return;
	}
	s->arr[++(s->top)] = data;
	printf("push : %d \n", data);
}

void pop(STACK *s)
{
	if (s->top < 0)
	{
		printf("no pop\n");
		s->top = -1;
		return;
	}
	printf("pop : %d \n", (s->arr[s->top]));
	s->arr[--(s->top)];
}

int main(void)
{
	STACK s;

	s.top = -1;

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 50);
	pop(&s);
	pop(&s);
	pop(&s);
	//push(&s, 10);

	return 0;
}