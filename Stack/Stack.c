#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack
{
	int Capacity;
	int Top;
	char *Data;
	int *LineNum;
}ArrayStack;

//스택 생성
void CreateStack(ArrayStack **Stack,int Capacity)
{
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Data = (char*)malloc(sizeof(char)*Capacity);
	(*Stack)->LineNum = (int*)malloc(sizeof(int)*Capacity);
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}
//데이터와 라인번호 Push
int Push(ArrayStack *Stack,char Data, int Linecount)
{
	if (Stack->Capacity == Stack->Top)
	{
		printf("스택이 가득 찼습니다. \n");
		return -1;
	}
	
	Stack->Data[Stack->Top] = Data;
	Stack->LineNum[Stack->Top] = Linecount;
	(Stack->Top)++;
	
	//printf("Push: %c \n", Data);
	return 0;
}

//POP
int Pop(ArrayStack* Stack)
{
	if (Stack->Top == 0)
	{
		printf("스택이 비었습니다. \n");
		return -1;
	}
	
		 --(Stack->Top);
	
	//printf("Pop: %c \n", Stack->Data);
		 return 0;
}
//괄호 오류체크 함수
int CheckBracket(ArrayStack *Stack, char * buf,int Linecount)
{
	int idx;
	for (idx = 0; idx < 100; idx++) {
		switch (buf[idx])
		{
		case '{':
		case '[':
		case '(':
			Push(Stack, buf[idx],Linecount);
			break;
		case ')':		
		case ']':
		case '}':
			if (Stack->Data[Stack->Top-1] == '(' && buf[idx] == ')' || Stack->Data[Stack->Top-1] == '[' && buf[idx] == ']' || Stack->Data[Stack->Top-1] == '{' && buf[idx] == '}')
			{
				Pop(Stack);
			}
			else
			{
				printf("%d 라인에서 %c의 짝이 맞지 않습니다.\n", Stack->LineNum[Stack->Top-1], Stack->Data[Stack->Top-1]);
				//getch(); 
				return -1;
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

int main()
{
	//줄의 번호 카운팅
	int linecount = 0;

	
	ArrayStack* Stack = NULL;

	CreateStack(&Stack, 100);
	
	FILE* fp = fopen("data.txt", "rt");
	if (fp == NULL)
	{
		printf("파일 열기 실패");
		return -1;
	}

	//4KByte
	char buf[4096] = { 0 };

	do
	{
		memset(buf, 0, sizeof(buf));
		if (fgets(buf, sizeof(buf), fp) == 0)
			break;
		linecount++;
		printf("%d: %s", linecount, buf);
		//괄호체크
		if (CheckBracket(Stack, buf, linecount) != 0)
		{
			break;
		}
			
	} while(!feof(fp));

	fclose(fp);
	//메모리 해제
	free(Stack->Data);
	free(Stack->LineNum);
	free(Stack);
	return 0;
}