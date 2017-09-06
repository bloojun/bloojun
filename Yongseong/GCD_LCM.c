#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int FindGCD(int num1, int num2)
{
	//quotient
	int q = 0;
	//remainder
	int r = 0;

	q = num1 / num2;
	r = num1 % num2;
	if (r == 0) return num2;
	
	return FindGCD(num2, r);
}
int FindLCM(int GCD, int a, int b)
{
	return (a / GCD) * (b / GCD) * GCD;
}

void main()
{
	int num1 = 0;
	int num2 = 0;
	//최대 공약수
	int GCD = 0;
	//최소 공배수
	int LCM = 0;
	printf("Input two numbers:");
	scanf("%d %d", &num1,&num2);

	if (num1 > num2) GCD = FindGCD(num1, num2);
	else GCD = FindGCD(num2, num1);
	
	LCM = FindLCM(GCD, num1, num2);
	printf("GCD: %d LCM: %d \n", GCD, LCM);
	//getch();
}