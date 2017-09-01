#include <stdio.h>

#define MAX 10

typedef struct stack {
	int arr[MAX];
	int top;
}STACK;

void push(STACK *s, int data)
{

	s->arr[++s->top] = data;
	printf("push : %d \n", data);
}

void pop()
{

}

int main(void)
{
	STACK s;
	int data;
	s.top = -1;

	push(&s, 10);
	push(&s, 20);
	return 0;
}