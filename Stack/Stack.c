#include <stdio.h>

#define MAX 2

typedef struct stack {
	int arr[MAX];
	int top;
}STACK;

void push(STACK *s, int data)
{
	if (s->top >= MAX )
	{
		printf("no push \n");
		return;
	}
	
	s->arr[s->top] = data;
	(s->top)++;
	
	printf("push : %d \n", data);
}

int pop(STACK *s)
{
	int val = 0;

	if (s->top <= 0)
	{
		printf("no pop\n");
		s->top = 0;
		return;
	}
		
	(s->top)--;
	val = s->arr[s->top];
	printf("pop : %d \n", (s->arr[s->top]));
	
	s->arr[s->top] = 0;
			
	return val;
}

int main(void)
{
	STACK s;
	memset(&s.arr,0,sizeof(s.arr));
	s.top = 0;
	
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 50);
	
	pop(&s);
	pop(&s);
	pop(&s);
	
	return 0;
}