#include "sem.h"

union semun us;
struct sembuf sb;

int create(){

  int semd;
  semd = semget(SEMKEY, 1, IPC_CREAT | IPC_EXCL | 0644);
  if (semd == -1){
    printf("Error Creating Semaphore: %s\n", strerror(errno));
    return -1;
  } else {
    semctl(semd, 0, SETVAL, us);
    printf("Semaphore Created\n");
  }

  int shmd;
  shmd = shmget(MEMKEY, SIZE, IPC_CREAT | IPC_EXCL | 0644);
  if (shmd == -1){
    printf("Error Creating Shared Memory: %s\n", strerror(errno));
    return -1;
  } else {
    printf("Shared Memory Created\n");
  }

  int fd;
  fd = open("story.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
  if (shmd == -1){
    printf("Error Creating Story File: %s\n", strerror(errno));
    return -1;
  } else {
    printf("Story File Created\n");
    close(fd);
  }

  return 0;

}

int main(int argc, char * argv[]){

  if (argc == 2) {
    if (strcmp(argv[1],"-c") == 0) {
      create();
    } else if (strcmp(argv[1],"-r") == 0) {
      //remove();
      printf("remove\n");
    } else if (strcmp(argv[1],"-v") == 0) {
      //view();
      printf("view\n");
    } else {
      printf("Invalid input.\n-c: Create Story\n-r: Remove Story\n-v: View Entire Story\n");
    }
  } else {
    printf("Invalid input.\n-c: Create Story\n-r: Remove Story\n-v: View Entire Story\n");
  }

  return 0;

}
