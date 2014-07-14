#ifndef __TPOOL_H__
#define __TPOOL_H__

/* 系统函数及接口 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

#include "queue.h"

/* 线程总数 */
#define Thread_max 	1000

/* 任务队列大小 */
#define Queue_max 	1000

#endif
