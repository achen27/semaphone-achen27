#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>

#define SEMKEY 202001
#define MEMKEY 202002
#define SIZE 1000

// union semun {
// 	int val;		// Value for SETVAL
// 	struct semid_ds *buf;		//Buffer for IPC_STAT, IPC_SET
// 	unsigned short *array;	//Array for GETALL, SETALL
// 	struct seminfo *__buf;	//Buffer for IPC_INFO (Linux-specific)
// };

int create();
int rremove();
// void view();
// void write();
