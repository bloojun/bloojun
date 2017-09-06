#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Bufsize 4096

#define TRUE 0;
#define FALSE -1;

typedef struct ArrayStack
{
	int Capacity;
	int Top;
	char *Data;
	int *LineNum;
}ArrayStack;

//���� ����
void CreateStack(ArrayStack **Stack,int Capacity)
{
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Data = (char*)malloc(sizeof(char)*Capacity);
	(*Stack)->LineNum = (int*)malloc(sizeof(int)*Capacity);
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}
//�����Ϳ� ���ι�ȣ Push
int Push(ArrayStack *Stack,char Data, int Linecount)
{
	if (!Stack || Stack->Capacity == Stack->Top)
	{
		printf("Stack is full. \n");
		return FALSE;
	}
	
	Stack->Data[Stack->Top] = Data;
	Stack->LineNum[Stack->Top] = Linecount;
	(Stack->Top)++;
	
	//printf("Push: %c \n", Data);
	return TRUE;
}

//POP
int Pop(ArrayStack* Stack)
{
	if (!Stack || Stack->Top == 0)
	{
		printf("Stack is empty. \n");
		return FALSE;
	}
	
		 --(Stack->Top);
	
	//printf("Pop: %c \n", Stack->Data);
		 return TRUE;
}
//��ȣ ����üũ �Լ�
int CheckBracket(ArrayStack *Stack, char * buf,int Linecount)
{
	int idx;
	for (idx = 0; idx < Bufsize; idx++) {
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
				printf("%d ���ο��� %c�� ¦�� ���� �ʽ��ϴ�.\n", Stack->LineNum[Stack->Top-1], Stack->Data[Stack->Top-1]);
				//getch(); 
				return FALSE;
			}
			break;
		default:
			break;
		}
	}
	return TRUE;
}

int main()
{
	//���� ��ȣ ī����
	int linecount = 0;
	
	ArrayStack* Stack = NULL;

	CreateStack(&Stack, 100);
	
	FILE* fp = fopen("data.txt", "rt");
	if (fp == NULL)
	{
		printf("���� ���� ����");
		return FALSE;
	}

	//4KByte
	char buf[Bufsize] = { 0 };

	do
	{
		memset(buf, 0, sizeof(buf));
		if (fgets(buf, sizeof(buf), fp)==0)
		{
			break;
		}
		
		linecount++;
		printf("%d: %s", linecount, buf);
		//��ȣüũ
		if (CheckBracket(Stack, buf, linecount) != 0)
		{
			break;
		}
			
	} while(!feof(fp));

	fclose(fp);
	//�޸� ����
	if (Stack != 0) 
	{
		free(Stack->Data);
		free(Stack->LineNum);
		free(Stack);
	}
	return TRUE;
}