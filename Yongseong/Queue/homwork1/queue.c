#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

struct fileinfo {
	int sp;
	int ep;
	int seq;
}finfo[4];

int main() {

	FILE* fd;
	char fn[10];
	int fs = 0;
	int idx = 0;
	Queue Q;

	init(&Q);

	fd = fopen("test.txt", "rb");
	if (fd == NULL) {
		printf("file open error! \n");
	}

	fscanf(fd, "%s %d\n", fn, &fs);
	printf("%s %d\n", fn, fs);
	for (idx = 0; idx < 4; idx++) {
		fscanf(fd, "%d %d %d\n", &finfo[idx].sp, &finfo[idx].ep, &finfo[idx].seq);
		printf("%d %d %d\n", (finfo[idx].sp), finfo[idx].ep, finfo[idx].seq);
	}
	fclose(fd);

	FILE* fp = fopen(fn, "rt");
	for (int num = 1; num <= 4; num++) {
		for (idx = 0; idx < 4; idx++) {
			if (finfo[idx].seq == num) {

				enqueue(&Q, finfo[idx].sp);	//Push start Pointer to Queue
			}
		}
	}

	FILE* fp2 = fopen("output.txt", "w");
	char data[25];

	for (idx = 0; idx < 4; idx++) {
		fseek(fp, dequeue(&Q) + 1, SEEK_SET);	//Pop start Pointer to Queue
		fread((void*)data, sizeof(char), 25, fp);
		fwrite((void*)data, sizeof(char), 25, fp2);
	}
	
	fclose(fp2);
	fclose(fp);
	return 0;
}
