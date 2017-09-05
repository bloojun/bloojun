#define _CRT_SECURE_NO_WARNINGS
#define MAX 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>

_Bool false = 0;
_Bool true = 1;


typedef struct stack {
	char arr[MAX];
	int top;
}STACK;

void push(STACK *s, char data)
{
	if (s == NULL || s->top >= MAX)
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

	if (s == NULL || s->top <= 0)
	{
		//printf("no pop\n");
		return;
	}

	(s->top)--;
	val = s->arr[s->top];
	s->arr[s->top] = 0;

	return val;
}

_Bool Check(char *buffer, int size, STACK *t, int *line_cnt)
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
			if (t == NULL || t->arr[t->top - 1] == '(' || t->arr[t->top - 1] == '[' || t->arr[t->top - 1] == '{')
			{
				return false;
			}
			else
			{
				push(t, buf);
				break;
			}
		}
		case ')':
		case ']':
		case '}':
		{
			if (t == NULL || t->arr[t->top - 1] == '(' && buf == ')' || t->arr[t->top - 1] == '[' && buf == ']' || t->arr[t->top - 1] == '{' && buf == '}')
			{
				pop(t);
				*line_cnt = *line_cnt + 1;
				break;
			}
			else
			{
				return false;
			}
		}
		}
	}
	return true;
}

int main(void)
{
	STACK s;
	memset(&s.arr, 0, sizeof(s.arr));
	s.top = 0;

	_Bool isSuccess = false;
	char buffer[MAX] = { 0, };
	int size = 0;
	int count = 0;
	int successCnt = 0;

	FILE *fp = NULL;

	fp = fopen("d:\\test\\test1.txt", "r");
	if (fp != NULL)
	{
		do
		{
			memset(&buffer, 0, sizeof(buffer));
			fread(buffer, sizeof(buffer) - 1, 1, fp);

			size = strlen(buffer);
			if (size == 0) { break; }
			count++;
			isSuccess = Check(buffer, size, &s, &successCnt);

		} while (!feof(fp));
		
		if (isSuccess == false || s.top > 0)
		{
			printf("%d line fail \n", count);
			printf("%d times correct matching \n", successCnt);
		}
		else
		{
			printf("%d times correct matching \n", successCnt);
		}
		fclose(fp);
	}
	else
	{
		printf("no file\n");
	}

	return 0;
}