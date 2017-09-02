#define _CRT_SECURE_NO_WARNINGS
#define MAX 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;
typedef struct stack {
	int arr[MAX];
	int top;
}STACK;

void push(STACK *s, char data)
{
	if (s->top >= MAX )
	{
		printf("no push \n");
		return;
	}
	
	s->arr[s->top] = data;
	(s->top)++;
	
	//printf("push : %s \n", &data);
}

int pop(STACK *s)
{
	char val = 0;

	if (s->top <= 0)
	{
		printf("no pop\n");
		s->top = 0;
		return;
	}
		
	(s->top)--;
	val = s->arr[s->top];
	//printf("pop : %d \n", (s->arr[s->top]));
	
	s->arr[s->top] = 0;
			
	return val;
}

int check(char *buffer, int size)
{
	bool status = 0;
	STACK s;
	int i = 0;
	char temp = 0;
	
	memset(&s.arr, 0, sizeof(s.arr));
	s.top = 0;
	
	for (i = 0; i < size; i++)
	{
		switch (buffer[i])
		{
		case '(':
		case '[':
			if (temp == 0)
			{
				push(&s, buffer[i]);
				temp = buffer[i];
				break;
			}
			else return false;
		case ')':
		case ']':
			if ((temp == '(' && buffer[i] == ')' ) || (temp == '[' && buffer[i] == ']'))
			{
				pop(&s);
				temp = 0;
				status = true;
			}
			else
				return false;
		}
	}
	if (temp != 0)
		return false;
	
	return status;
}
int main(void)
{
	STACK s;
	//memset(&s.arr,0,sizeof(s.arr));
	//s.top = 0;
	
	char temp,buffer[20] = { 0, };
	int size=0;
	int count = 0;
	
	int i;
	
	FILE *fp = NULL;
	
	fp = fopen("d:\\test\\test1.txt", "r");
	
//	memset(&buffer, 0, sizeof(buffer));
	while (!feof(fp))
	{
		fgets(buffer, sizeof(buffer), fp);
		size = strlen(buffer);
		if (check(buffer, size) == 1)
		{
			printf("matching ok \n");
		}
		else printf("no matching \n");
	}
	

	fclose(fp);

	
	return 0;
}