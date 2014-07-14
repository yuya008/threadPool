#include "tpool.h"
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

int put(T *newTask)
{
	int s;
	if (!newTask) {
		return 1;
	}
	T *new_t = malloc(sozeof(T));
	s = pthread_mutex_lock(&mutex);
	if (s != 0) {
		perror("pthread_mutex_lock");
		exit(100);
	}
	if (!task_manage.top) {
		task_manage.top = new_t;
	} else {
		new_t->next = task_manage.top;
		task_manage.top = new_t;
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
	if (task_manage.n - 1 < 0) {
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
	s = pthread_mutex_lock(&mutex);
	if (s != 0) {
		perror("pthread_mutex_lock");
		exit(100);
	}

	s = pthread_mutex_unlock(&mutex);
	if (s != 0) {
		perror("pthread_mutex_unlock");
		exit(100);
	}
	return 0;
}
