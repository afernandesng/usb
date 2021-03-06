#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void dump(unsigned char *buf, unsigned int start, unsigned int size)
{
	unsigned int i, count = 0;
	printf("\033[1;31m");
	printf("   Address  ");
	for (i = 0; i < 10; ++i) {
		printf(" %d ", i);
		if (i == 7) printf(" \033[1;34m|\033[1;31m  ");
	}
	for (i = 0; i < 6; ++i) {
		printf(" %c ", 'A' + i);
	}
	printf("\033[0;37m");

	printf("\n");
	printf("\033[1;34m");
	printf("------------");
	for (i = 0; i < 23; ++i) {
		if (i == 7) {
			printf("----+--");
		} else {
			printf("---");
		}
	}
	printf("\033[0;37m");

	for (i = start; i < start + size; ++i) {
		if ((i % 16) == 0) {
			int j;
			printf("\033[0;30m  ");
			for (j = i - 16; j < i; ++j) {
				if ((j % 8) == 0 && (j % 16) != 0) printf("  ");
				if (buf[j] < 33 || buf[j] > 126)	/* can't be dispaly */
				  printf("\033[0;30m%c\033[0;37m", '.');
				else
				  printf("\033[0;35m%c\033[0;37m", buf[j]);
				++count;
			}
			printf("\033[0;37m\n");
			printf("0x%08x  ", buf+i);
		}
		if ((i % 8) == 0 && (i % 16) != 0) printf(" \033[1;34m|\033[0;37m  ");
		if (*(buf+i) != 0) {
			printf("\033[0;37m%02x\033[0;37m ", *(buf+i));
		} else {
			printf("\033[0;37m%02x\033[0;37m ", *(buf+i));
		}
	}

	if (count != start + size) {
		printf("\033[0;30m  ");
		for (i = count; i < start + size; ++i) {
			if ((i % 8) == 0 && (i % 16) != 0) printf("  ");
                if (buf[i] < 33 || buf[i] > 126)        /* can't be dispaly */
			printf("\033[0;30m%c\033[0;37m", '.');
                else
			printf("\033[0;35m%c\033[0;37m", buf[i]);

		}
	}
	printf("\033[0;37m\n");
}
