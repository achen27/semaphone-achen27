#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>

// union semun {
// 	int val;		// Value for SETVAL
// 	struct semid_ds *buf;		//Buffer for IPC_STAT, IPC_SET
// 	unsigned short *array;	//Array for GETALL, SETALL
// 	struct seminfo *__buf;	//Buffer for IPC_INFO (Linux-specific)
// };

// void create();
// void remove();
// void view();
// void write();
