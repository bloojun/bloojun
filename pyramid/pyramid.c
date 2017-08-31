#include <stdio.h>

int pyramid()
{
	int a;
	int i;
	for (i = 1; i < 3; i++)
	{
		// 2n+1
		if (a<i)
			printf("_");
		printf("¤±");
	}
}

int main(void)
{
	int a;

	printf("¿øÇÏ´Â Ãþ : ");
	scanf("%d", &a);
	pyramid();

	return 0;
}