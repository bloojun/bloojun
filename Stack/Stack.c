#define _CRT_SECURE_NO_WARNINGS
#define MAX 4096

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct stack {
	char arr[MAX];
	int top;
}STACK;

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

bool Check(char *buffer, int size, STACK *t, int *line_cnt)
{
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
			if (t->arr[t->top - 1] == '(' || t->arr[t->top - 1] == '[' || t->arr[t->top - 1] == '{')
			{
				return true;
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
			if (t->arr[t->top - 1] == '(' && buf == ')' || t->arr[t->top - 1] == '[' && buf == ']' || t->arr[t->top - 1] == '{' && buf == '}')
			{
				pop(t);
				*line_cnt = *line_cnt + 1;
			}
			else if (t->arr[0] == 0)
			{
				return true;
			}
		}
		}
	}
	return false;
}

void LastCheck(STACK *a, int recive_count, int recive_line_cnt)
{
	if (a->arr[a->top - 1] == '(' || a->arr[a->top - 1] == '[' || a->arr[a->top - 1] == '{')
	{
		printf("%d line fail \n", recive_count);
		printf("%d times correct matching \n", recive_line_cnt);
	}
	else
		printf("%d times correct matching \n", recive_line_cnt);
}
int main(void)
{
	STACK s;
	memset(&s, 0, sizeof(s));
	s.top = 0;

	char buffer[MAX] = { 0, };
	int size = 0;
	int count = 0;
	int line_cnt = 0;

	FILE *fp = NULL;

	fp = fopen("d:\\test\\test1.txt", "r");
	fseek(fp, 0, SEEK_SET);
	do
	{
		count++;
		memset(&buffer, 0, sizeof(buffer));
		fread(buffer, sizeof(buffer) - 1, 1, fp);

		size = strlen(buffer);

		if (Check(buffer, size, &s, &line_cnt) == true)
		{
			printf("%d line fail \n", count);
			break;
		}	
	} while (!feof(fp));
	
	LastCheck(&s, count, line_cnt);
	
	fclose(fp);

	return 0;
}
