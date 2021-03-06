#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int queue_init()
{
	int status;

	status = pthread_mutex_init(&mutex, NULL);
	if (status != 0) {
		perror("pthread_mutex_init");
		exit(100);
	}
	return 0;
}

int put(T *new_t)
{
	int s;
	if (!new_t) {
		return 1;
	}

	s = pthread_mutex_lock(&mutex);
	if (s != 0) {
		perror("pthread_mutex_lock");
		exit(100);
	}
	if (!task_manage.top && !task_manage.tail) {
		task_manage.top = new_t;
		task_manage.tail = new_t;
	} else {
		new_t->next = NULL;
		task_manage.tail->next = new_t;
		task_manage.tail = new_t;
	}
	task_manage.n++;
	s = pthread_mutex_unlock(&mutex);
	if (s != 0) {
		perror("pthread_mutex_unlock");
		exit(100);
	}
	return 0;
}

T *pop()
{
	int s;
	T *ret = NULL;
	s = pthread_mutex_lock(&mutex);
	if (s != 0) {
		perror("pthread_mutex_lock");
		exit(100);
	}
	if (!task_manage.top) {
		return NULL;
	}
	ret = task_manage.top;
	task_manage.top = ret->next;
	if (task_manage.top == task_manage.tail) {
		task_manage.tail = NULL;
	}
	if ((task_manage.n - 1) < 0) {
		task_manage.n = 1;
	}
	task_manage.n--;
	s = pthread_mutex_unlock(&mutex);
	if (s != 0) {
		perror("pthread_mutex_unlock");
		exit(100);
	}
	return ret;
}

int queue_exit()
{
	int s;
	s = pthread_mutex_destroy(&mutex);
	if (s != 0) {
		perror("pthread_mutex_unlock");
		exit(100);
	}
	return 0;
}
