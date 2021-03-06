#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <pthread.h>
#include <stdint.h>

typedef struct task_manage	Tm;
typedef struct task		T;

/* 任务管理结构 */
struct task_manage
{
	T *top;		// 队列头
	T *tail;	// 队列尾
	uint32_t n;	// 队列元素总数
};

/* 任务结构 */
struct task
{
	T *next;
	uint32_t seq;
};

static Tm task_manage;
static pthread_mutex_t mutex;

int queue_init();
int put(T*);
T *pop();
int queue_exit();

#endif
