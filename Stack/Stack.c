#define _CRT_SECURE_NO_WARNINGS
#define MAX 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;
typedef struct stack {
	char arr[MAX];
	int top;
}STACK;

int cnt = 0;

void push(STACK *s, char data)
{
	if (s->top >= MAX)
	{
		//printf("no push \n");
		return;
	}

	s->arr[s->top] = data;
	(s->top)++;

}

int pop(STACK *s)
{
	char val = 0;

	if (s->top <= 0)
	{
		//printf("no pop\n");
		s->top = 0;
		return;
	}

	(s->top)--;
	val = s->arr[s->top];
	s->arr[s->top] = 0;

	return val;
}

char check(char *buffer, int size, STACK *t)
{
	bool status = 0;
	int i = 0;
	char buf;

	for (i = 0; i < size; i++)
	{
		buf = buffer[i];
		switch (buf)
		{
		case '(':
		case '[':
		case '{':
		{
			if (t->arr[0] > 0)
			{
				return 1;
			}
			else
			{
				push(t, buf);
			}
		}

		case ')':
		case ']':
		case '}':
		{
			if (t->arr[0] == '(' && buf == ')' || t->arr[0] == '[' && buf == ']' || t->arr[0] == '{' && buf == '}')
			{
				pop(t);
				cnt++;
			}
			else if (t->arr[0] == 0)
			{
				return 1;
			}
		}
		}
	}
	return 0;
}
int main(void)
{
	STACK s;
	memset(&s, 0, sizeof(s));
	s.top = 0;

	//char temp;
	char buffer[3] = { 0, };
	int size = 0;
	int count = 0;

	FILE *fp = NULL;

	fp = fopen("d:\\test\\test1.txt", "r");
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp))
	{
		count++;

		fread(buffer, sizeof(buffer) - 1, 1, fp);

		size = strlen(buffer);

		if (check(buffer, size, &s) == 1)
		{
			printf("%d line fail \n", count);
			fclose(fp);
			return 0;
		}
		memset(&buffer, 0, sizeof(buffer));
	}
	/*if (s.top > 0)
	{
		printf("%d line fail \n", count);
		fclose(fp);
		return 0;
	}*/
	
	printf("%d times correct matching \n", cnt);
	fclose(fp);

	return 0;
}