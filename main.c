#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	queue_init();

	for (int i = 0; i < 100000; i++) {
		T *new = malloc(sizeof(T));
		new->seq = i;
		put(new);
	}
	T *p = NULL;
	while ((p = pop())) {
		fprintf(stderr, "%d\n", p->seq);
	}
	
	return 0;
}
